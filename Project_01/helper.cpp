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


/*Order the Node list by heuristic value*/
void sort_list(vector<Node*> &node_list, vector<int> heuristic_value, bool is_include_cost)
{
	for (int i = 0; i < node_list.size(); i++)
	{
		for (int j = i + 1; j < node_list.size(); j++)
		{
			//GBFS:
			if (is_include_cost)
			{
				if (heuristic_value.at(node_list.at(i)->value) + node_list.at(i)->cost <= heuristic_value.at(node_list.at(j)->value) + node_list.at(j)->cost)
				{
					//If f(x) is the same, compare node id:
					if (heuristic_value.at(node_list.at(i)->value) + node_list.at(i)->cost == heuristic_value.at(node_list.at(j)->value) + node_list.at(j)->cost)
						if (node_list[i]->value > node_list[j]->value)
							swap(node_list[i], node_list[j]);
				}
				//If f(i) > f(j), swap:
				else
					swap(node_list[i], node_list[j]);
			}

			//A-start search:
			else
			{
				if (heuristic_value.at(node_list.at(i)->value) >= heuristic_value.at(node_list.at(j)->value))
				{
					if (heuristic_value.at(node_list.at(i)->value) == heuristic_value.at(node_list.at(j)->value))
					{
						if (node_list[i]->value > node_list[j]->value)
							swap(node_list[i], node_list[j]);
					}
					else
						swap(node_list[i], node_list[j]);
				}
			}
		}
	}
}

/*Print list of path and list of steps to output file*/
void print(string output, vector<int> path, vector<int> steps)
{
	fstream fout(output, ios::out);

	for each (int var in path)
	{
		fout << var << '\t';
	}

	fout << endl;

	for each (int var in steps)
	{
		fout << var << '\t';
	}

	fout.close();
}