#include "file_processing.h"

Space create_space(string input_file)
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
	
	fin >> temp1 >> temp2;
	Point start(temp1, temp2);

	fin >> temp1 >> temp2;
	Point goal(temp1, temp2);

	fin.close();


	return Space(height, width, start, goal, walls);
}
