#pragma once
#include <vector>
using namespace std;

struct Point;
struct Line;
struct Equation;
struct Map;
enum LastMove;


struct Point
{
	int x;
	int y;

	Point(int _x, int _y) :x(_x), y(_y)
	{
	}
};

struct Line
{
	Point start;
	Point end;

	Line(Point p1, Point p2):start(p1), end(p2)
	{}

	/*Get equation which include start and end*/
	Equation get_equation();
};

/*Hàm số bậc nhất: y = ax + b*/
struct Equation
{
	int a;
	int b;

	Equation(int _a, int _b) :a(_a), b(_b)
	{
	}
};

struct Map
{
	int height;
	int width;

	Point start_position;
	Point goal_position;
	vector<Line> wall_list;


	Map(int _height, int _width, Point start, Point goal, vector<Line> walls) :height(_height), width(_width), start_position(start), goal_position(goal), wall_list(walls)
	{
	}
};

/*Hướng di chuyển gần đây nhất*/
enum LastMove
{
	horizontal,
	vertical,
	left_crossover,
	right_crossover
};