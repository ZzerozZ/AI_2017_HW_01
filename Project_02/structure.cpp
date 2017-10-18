#include "structure.h"

Equation Line::get_equation()
{
	int a = (start.y - end.y) / (start.x - end.x);
	int b = (start.y * (start.x - end.x) - start.x * (start.y - end.y)) / (start.x - end.x);


	return Equation(a, b);
}
