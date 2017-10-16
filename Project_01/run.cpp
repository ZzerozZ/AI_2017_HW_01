#include "node.h"
#include "search.h"

int main()
{
	vector<Node*> node_list;
	vector<int> heu_val;
	vector<int> path_list;
	vector<int> steps;
	int start = 0, goal = 0;
	string path = "input.txt";

	create_nodes(path, node_list, heu_val, start, goal);

	Node *root = get_node(start, node_list, 0, path_list);
	vector<NextNode> options({ NextNode(vector<Node*>(), 0) });
	vector<int> search = a_star_search(root, goal, heu_val, steps);

	return 0;
}