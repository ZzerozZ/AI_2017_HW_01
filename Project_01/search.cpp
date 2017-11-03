#include "search.h"


/*Get new node from node list and start position(root_value)*/
Node * get_node(int root_value, vector<Node*> node_list, int _cost, vector<int> path)
{
	Node *node = new Node(root_value);/*Tempolary node*/
	Node *temp = node_list.at(root_value);/*Root*/

										  ///Set node's path:
	node->path = path;

	///Set node's cost:
	node->cost = _cost;

	//Get children list:
	for (int i = 0; i < temp->children.size(); i++)
	{
		//If the new child is not in root node, add this to children list:
		if (!is_exist_in_list(temp->children.at(i)->value, path))
		{
			///Add root value to the path of child:
			path.push_back(root_value);
			///Add distance from root to child:
			node->distances_to_child.push_back(temp->distances_to_child.at(i));
			///Create new node and add it to children list:
			node->children.push_back(get_node(temp->children.at(i)->value, node_list, _cost + temp->distances_to_child.at(i), path));
			///Remove last value for next loop:
			path.pop_back();
		}
	}

	//Return temp node:
	return node;
}


/*Depth-first search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed*/
vector<int> depth_first_search(Node *root, int goal_index, vector<int> &step_data)
{
	//If this node was extended, skip this:
	if (is_exist_in_list(root->value, step_data))
		return vector<int>();

	//Add root value to step list:
	step_data.push_back(root->value);

	//If this node is goal, return the path:
	if (root->value == goal_index)
		return root->path;

	//If this node is leaf of tree, return empty list:
	if (root->children.empty())
		return vector<int>();

	//Recursive depth_first_search with any children of this node:
	for (int i = 0; i < root->children.size(); i++)
	{
		vector<int> temp = depth_first_search(root->children.at(i), goal_index, step_data);
		///When temp isn't empty(goal value found), return temp: 
		if (!temp.empty())
			return temp;
	}

	//If the search failed, return empty list:
	return vector<int>();
}



/*Breadth-first search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed*/
vector<int> breadth_first_search(Node * root, int goal_index, vector<int>& step_data)
{
	//Add root value to step_data:
	step_data.push_back(root->value);

	//If this node is goal, return the path:
	if (root->value == goal_index)
		return root->path;

	//Define temporary list:
	vector<Node*> children;
	vector<Node*> temp_children;

	//Add all node in level 1 of tree:
	for (int i = 0; i < root->children.size(); i++)
	{
		children.push_back(root->children.at(i));
	}

	//Check any child in children list: return if exist goal, if not, add children of child to temporary list:
	while (children.size() > 0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			if (!is_exist_in_list(children.at(i)->value, step_data))
			{
				///Add node-in-process to steps list:
				step_data.push_back(children.at(i)->value);

				///Return if node is Goal:
				if (children.at(i)->value == goal_index)
					return children.at(i)->path;

				///Add children of child to temporary list:
				for (int j = 0; j < children.at(i)->children.size(); j++)
				{
					//if(is_exist_in_list(children.at(i)->children.at(j)->value, step_data))
					temp_children.push_back(children.at(i)->children.at(j));
				}
			}
		}

		///Update children list for next loop:
		children = temp_children;
		///Clear temporary list for next loop:
		temp_children.clear();
	}

	//If the search failed, return empty list:
	return vector<int>();
}



/*Uniform-cost search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed
*/
vector<int> uniform_cost_search(Node * root, int goal_index, vector<NextNode> &options, vector<int>& step_data)
{
	if (is_exist_in_list(root->value, step_data))
		return vector<int>();

	//Add root value to step list:
	step_data.push_back(root->value);

	//If this node is goal, return the path:
	if (root->value == goal_index)
		return root->path;

	//Find min:
	int min_index = min_of_next_node_list(options);


	//Add new options from node children:
	for (int i = 0; i < root->children.size(); i++)
	{
		///Add new node to node-list of min-option:
		options.at(min_index).node.push_back(root->children.at(i));
		///Get cost to new option:
		int cost = options.at(min_index).cost + root->distances_to_child.at(i);

		///Add option from children to options list:
		options.push_back(NextNode(options.at(min_index).node, cost));

		///Remove last node for next loop:
		options.at(min_index).node.pop_back();
	}

	//Add root value to step list:
	//if(options.at(min_index).node.size() != 0)
	//	step_data.push_back(options.at(min_index).node.at(options.at(min_index).node.size() - 1)->value);
	//Remove option of this node:
	options.erase(options.begin() + min_index);

	//Find new min-index: 
	min_index = min_of_next_node_list(options);


	//Recursive with node have min index:
	vector<int> result = uniform_cost_search(options.at(min_index).node.at(options.at(min_index).node.size() - 1), goal_index, options, step_data);
	//If result is not empty, return this:
	if (!result.empty())
		return result;
	//If not, delete current smallest-distance node and re-find in other items in queue:
	else
	{
		options.erase(options.begin() + min_index);
		min_index = min_of_next_node_list(options);
		return uniform_cost_search(options.at(min_index).node.at(options.at(min_index).node.size() - 1), goal_index, options, step_data);
	}
}


/*Greedy best-first search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed*/
vector<int> greedy_best_first_search(Node * root, int goal_index, vector<int> heuristic_value, vector<int> &step_data)
{
	//If this node was extended, skip this:
	if (is_exist_in_list(root->value, step_data))
		return vector<int>();

	//Add root value to step list:
	step_data.push_back(root->value);

	//If this node is goal, return the path:
	if (root->value == goal_index)
		return root->path;

	//If this node is leaf of tree, return empty list:
	if (root->children.empty())
		return vector<int>();

	//Children list order by heuristic value of any children: 
	sort_list(root->children, heuristic_value);

	//Recursive depth_first_search with any children of this node which ascension sorted:
	for (int i = 0; i < root->children.size(); i++)
	{
		vector<int> temp = greedy_best_first_search(root->children.at(i), goal_index, heuristic_value, step_data);
		///When temp isn't empty(goal value found), return temp: 
		if (!temp.empty())
			return temp;
	}

	//If the search failed, return empty list:
	return vector<int>();
}


/*A star search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed*/
vector<int> a_star_search(Node * root, int goal_index, vector<int> heuristic_value, vector<int>& step_data)
{
	//If this node was extended, skip this:
	if (is_exist_in_list(root->value, step_data))
		return vector<int>();

	//If this node was extended, skip this:
	if (is_exist_in_list(root->value, step_data))
		return vector<int>();

	//Add root value to step list:
	step_data.push_back(root->value);

	//If this node is goal, return the path:
	if (root->value == goal_index)
		return root->path;

	//If this node is leaf of tree, return empty list:
	if (root->children.empty())
		return vector<int>();

	//Children list order by heuristic value of any children: 
	sort_list(root->children, heuristic_value, true);

	//Recursive depth_first_search with any children of this node which ascension sorted:
	for (int i = 0; i < root->children.size(); i++)
	{
		vector<int> temp = a_star_search(root->children.at(i), goal_index, heuristic_value, step_data);
		///When temp isn't empty(goal value found), return temp: 
		if (!temp.empty())
			return temp;
	}

	//If the search failed, return empty list:
	return vector<int>();
}