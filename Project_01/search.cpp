#include "search.h"


/*Get new node from node list and start position(root_value)*/
Node * get_node(int root_value, vector<Node*> node_list, vector<int> path)
{
	Node *node = new Node(root_value);/*Tempolary node*/
	Node *temp = node_list.at(root_value);/*Root*/

	///Set node's path:
	node->path = path;

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
			node->children.push_back(get_node(temp->children.at(i)->value, node_list, path));
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
	//If root is tree root(haven't parent), add this value to step_data:
	if(root->path.empty())
		step_data.push_back(root->value);

	//If this node is goal, return the path:
	if (root->value == goal_index)
		return root->path;

	//Search in all children:
	for (int i = 0; i < root->children.size(); i++)
	{
		///Save the browsed-node value:
		step_data.push_back(root->children.at(i)->value);

		///If this child is goal, return:
		if (root->children.at(i)->value == goal_index)
			return root->children.at(i)->path;
	}

	//Recursive breadth_first_search with any children of this node:
	for (int i = 0; i < root->children.size(); i++)
	{
		for (int j = 0; j < root->children.at(i)->children.size(); j++)
		{
			vector<int> temp = breadth_first_search(root->children.at(i), goal_index, step_data);
			///When temp isn't empty(goal value found), return temp: 
			if (!temp.empty())
				return temp;
		}
	}

	//If the search failed, return empty list:
	return vector<int>();
}
