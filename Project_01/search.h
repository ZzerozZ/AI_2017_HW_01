#pragma once
#include "node.h"
#include "helper.h"
using namespace std;



/*
Get new node from node list and start position(root_value)
*/
Node* get_node(int root_value, vector<Node*> node_list, int _cost, vector<int> path);

/*
Depth-first search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed
*/
vector<int> depth_first_search(Node *root, int goal_index, vector<int> &step_data);

/*
Breadth-first search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed
*/
vector<int> breadth_first_search(Node *root, int goal_index, vector<int> &step_data);

/*
Uniform-cost search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed
*/
vector<int> uniform_cost_search(Node * root, int goal_index, vector<NextNode> &options, vector<int>& step_data);


/*
Greedy best-first search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed
*/
vector<int> greedy_best_first_search(Node *root, int goal_index, vector<int> heuristic_value, vector<int> &step_data);


/*
A star search
- Return value is the path to goal, not include goal value
- step_data will be contain value of any node which browsed
*/
vector<int> a_star_search(Node *root, int goal_index, vector<int> heuristic_value, vector<int> &step_data);