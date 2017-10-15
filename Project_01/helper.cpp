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
