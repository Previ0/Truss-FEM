#include "vertex.h"

// Point
Point::Point(float x, float y) :
	X{ x },
	Y{ y }
{

}


// Vertex
Vertex::Vertex() :
	Point(0.0f, 0.0f),
	x_blocked_{false},
	y_blocked_{false}
{

}

Vertex::Vertex(float x, float y) :
	Point(x, y),
	x_blocked_{ false },
	y_blocked_{ false }
{

}