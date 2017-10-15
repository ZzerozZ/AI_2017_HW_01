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
			///Create new node and add it to children list:
			node->children.push_back(get_node(temp->children.at(i)->value, node_list, path));
			///Remove last value for next loop:
			path.pop_back();
		}
	}

	//Return temp node:
	return node;
}
