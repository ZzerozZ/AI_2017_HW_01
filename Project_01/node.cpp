#include "node.h"


/*Create new node from input file and save it on node list*/
bool create_nodes(string input_file, vector<Node*> &node_list, vector<int> &heuristic_values, int &start_index, int &goal_index)
{
	//Open input file:
	fstream fin(input_file, ios::in);

	int vertexs = 0;/*Numbers of vertex*/
	fin >> vertexs;


	//Create vertex list:
	for (int i = 0; i < vertexs; i++)
	{
		node_list.push_back(new Node(i));
		heuristic_values.push_back(0);
	}

	//Get graph info:
	fin >> start_index;///Get start vertex
	fin >> goal_index;///Get goal vertex

	int itemp = 0;

	//Get node-linking info:
	for (int i = 0; i < vertexs * vertexs; i++)
	{
		fin >> itemp;
		if (itemp > 0)
		{
			node_list.at(i / vertexs)->children.push_back(node_list.at(i % vertexs));
			node_list.at(i / vertexs)->distances_to_child.push_back(itemp);
		}
	}

	//Get heuristic values:
	for (int i = 0; i < vertexs; i++)
	{
		fin >> itemp;
		heuristic_values.at(i) = itemp;
	}

	//Close input file:
	fin.close();

	return true;
}