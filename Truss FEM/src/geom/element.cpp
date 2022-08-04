#include <iostream>
#include "element.h"


// Element

int Element::counter{ 0 };

Element::Element() :
	i{0.0f, 0.0f},
	j{0.0f, 0.0f},
	id{++counter}
{
}

Element::Element(Vertex i, Vertex j) :
	i{i},
	j{j},
	id{ ++counter }
{
}

Element::Element(float i_x, float i_y, float j_x, float j_y) :
	i{i_x, i_y},
	j{j_x, j_y},
	id{ ++counter }
{
}

void Element::Print()
{
	std::cout <<"id: " << id << ", i(" << i.X << ", " << i.Y << "), j(" << j.X << ", " << j.Y << ")" << std::endl;
}
