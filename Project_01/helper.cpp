#include "helper.h"


/*Check the value is exist in list or not*/
bool is_exist_in_list(int val, vector<int> list)
{
	//Check in every item of list: 
	for (int i = 0; i < list.size(); i++)
	{
		if (val == list.at(i))
			return true;
	}

	return false;
}


/*Find index of min value*/
int min_of_next_node_list(vector<NextNode> list)
{
	int min = 0;
	for (int i = 1; i < list.size(); i++)
	{
		if (list.at(i).cost < list.at(min).cost)
			min = i;
	}

	return min;
}
