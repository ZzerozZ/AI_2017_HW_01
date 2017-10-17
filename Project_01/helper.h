#pragma once
#include <vector>
#include "node.h"

using namespace std;

struct NextNode
{
	vector<Node*> node;
	int cost;

	NextNode(vector<Node*> _value, int _cost) : node(_value), cost(_cost)
	{
	}
};


/*
Check the value is exist in list or not
*/
bool is_exist_in_list(int val, vector<int> list);


/*
Find index of min value
*/
int min_of_next_node_list(vector<NextNode> list);


/*
Order the Node list by heuristic value
*/
void sort_list(vector<Node*> &node_list, vector<int> heuristic_value, bool is_include_cost = false);


/*
Print list of path and list of steps to output file
*/
void print(string output, vector<int> path, vector<int> steps);
