#include "structure.h"

Equation Line::get_equation()
{
	int a, b;
	if (start.x - end.x != 0)
	{
		a = (start.y - end.y) / (start.x - end.x);
		b = (start.y * (start.x - end.x) - start.x * (start.y - end.y)) / (start.x - end.x);
	}
	else
	{
		a = -100001;
		b = this->start.x;
	}
	
	return Equation(a, b);
}
