#pragma once
#include <vector>
using namespace std;

struct NextNode
{
	vector<int> value;
	int cost;

	NextNode(vector<int> _value, int _cost) : value(_value), cost(_cost)
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