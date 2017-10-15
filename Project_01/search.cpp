#include "search.h"

Node * get_node(int value, vector<Node*> node_list, vector<int> path)
{
	Node *node = new Node(value);
	Node *temp = node_list.at(value);

	for (int i = 0; i < temp->children.size(); i++)
	{
		if (!is_exist_in_list(temp->children.at(i)->value, path))
		{
			node->path = path;
			path.push_back(value);
			node->children.push_back(get_node(temp->children.at(i)->value, node_list, path));
		}
	}

	return node;
}
