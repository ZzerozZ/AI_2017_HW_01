#include "helper.h"

bool is_exist_in_list(int val, vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (val == list.at(i))
			return true;
	}

	return false;
}
