#include "Point.h"
#include <iostream>

Point::Point() : x{ 0.0f }, y{ 0.0f }
{

};

Point::Point(float x, float y) : x{ x }, y{ y }
{

}
void Point::print()
{
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}
;