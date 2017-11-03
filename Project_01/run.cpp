#include "node.h"
#include "search.h"

int main()
{
	//Temporary variable: 
	vector<Node*> node_list;
	vector<int> heuristic_value;
	vector<int> path_list;
	vector<int> steps;
	int start = 0, goal = 0;
	string input_file = "input.txt";

	//Create node list:
	create_nodes(input_file, node_list, heuristic_value, start, goal);
	Node *root = get_node(start, node_list, 0, path_list);
	vector<int> search;

	//Run DFS:
	search = depth_first_search(root, goal, steps);
	search.push_back(goal);
	print("dfs.txt", search, steps);

	search.clear();
	steps.clear();

	//Run BFS:
	search = breadth_first_search(root, goal, steps);
	search.push_back(goal);
	print("bfs.txt", search, steps);

	search.clear();
	steps.clear();

	//Run UCS:
	vector<NextNode> options({ NextNode(vector<Node*>(), 0) });
	search = uniform_cost_search(root, goal, options, steps);
	search.push_back(goal);
	print("ucs.txt", search, steps);

	search.clear();
	steps.clear();

	//Run GBFS:
	///Cause GBFS can change root value, we need a temporary node
	Node *node = root;
	search = greedy_best_first_search(node, goal, heuristic_value, steps);
	search.push_back(goal);
	print("gbfs.txt", search, steps);

	search.clear();
	steps.clear();

	//Run Astar search:
	///Cause Astar search can change root value, we need a temporary node
	node = root;
	search = a_star_search(node, goal, heuristic_value, steps);
	search.push_back(goal);
	print("astar.txt", search, steps);

	search.clear();
	steps.clear();


	return 0;
}