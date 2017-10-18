#pragma once
#include <vector>
using namespace std;

struct Point;
struct Line;
struct Equation;
struct Space;

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

	Equation get_equation();
};

struct Equation
{
	int a;
	int b;

	Equation(int _a, int _b) :a(_a), b(_b)
	{
	}
};

struct Space
{
	int height;
	int width;

	Point start_position;
	Point goal_position;
	vector<Line> wall_list;


	Space(int _height, int _width, Point start, Point goal, vector<Line> walls) :height(_height), width(_width), start_position(start), goal_position(goal), wall_list(walls)
	{
	}
};