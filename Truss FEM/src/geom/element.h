#ifndef ELEMENT_H
#define ELEMENT_H

#include "vertex.h"

// Class "Element" descirbing a truss element used in FEM(Finite element method).

class Element
{
	Vertex i; // starting point of an element
	Vertex j; // ending point of an element
	int id;
	static int counter;
public:
	Element();
	Element(Vertex i, Vertex j);
	Element(float i_x, float i_y, float j_x, float j_y);

	void Print();

	bool operator== (const Element& other);
};

#endif // !ELEMENT_H