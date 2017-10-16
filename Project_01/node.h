#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
Node is the vertex of graph
*/
struct Node
{
	int value;/*Value of node*/
	vector<Node*> children;/*Children of node in graph/tree*/

	int cost;/*Coat from root to this node*/
	vector<int> distances_to_child;/*Distance to any child in children list*/
	vector<int> path;/*Path from root node to this node*/


	//Constructor:
	Node(int _value)
	{
		value = _value;
	}
};


/*
Create new node from input file and save it on node list
*/
bool create_nodes(string input_file, vector<Node*> &node_list, vector<int> &heuristic_values, int &start_index, int &goal_index);
