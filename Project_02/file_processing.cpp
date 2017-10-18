#include "file_processing.h"

Map create_map(string input_file)
{
	fstream fin(input_file, ios::in);

	int count, temp1, temp2, temp3, temp4;/*Temporary variable*/

	int height, width;
	fin >> height >> width;
	vector<Line> walls;

	fin >> count;

	for (int i = 0; i < count; i++)
	{
		fin >> temp1 >> temp2 >> temp3 >> temp4;
		walls.push_back(Line(Point(temp1, temp2), Point(temp3, temp4)));
	}
	
	//Add map's borders:
	walls.push_back(Line(Point(0, 0), Point(0, height)));
	walls.push_back(Line(Point(0, 0), Point(width, 0)));
	walls.push_back(Line(Point(height, 0), Point(height, width)));
	walls.push_back(Line(Point(0, width), Point(height, width)));


	fin >> temp1 >> temp2;
	Point start(temp1, temp2);

	fin >> temp1 >> temp2;
	Point goal(temp1, temp2);

	fin.close();


	return Map(height, width, start, goal, walls);
}