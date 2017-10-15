#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


struct Node
{
	int value;
	vector<Node*> children;
	vector<int> path;

	Node(int _value)
	{
		value = _value;
	}
};

bool create_nodes(string input_file, vector<Node*> &node_list, vector<int> &heuristic_values, int &start_index, int &goal_index);
