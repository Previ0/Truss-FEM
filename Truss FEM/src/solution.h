#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "geom/element.h"

class Solution
{
	std::vector<Element> element_list_;

public:
	// Constructors
	Solution();

	// Methods
	void PrintElements();

	// TESTING METHODS
	void add_element(float i_x, float i_y, float j_x, float j_y);
	

};

#endif // !SOLUTION_H