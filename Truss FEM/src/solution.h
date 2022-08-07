#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "geom/element.h"

class Solution
{
	std::vector<Element> element_list_;

public:

	Solution();

	void PrintElements();

	void AddElement();
	void AddElement(float i_x, float i_y, float j_x, float j_y);
	
private:

	// That method checks if 'element' overlapps any element that exists.
	// true  - if there is such an element in the list.
	// false - if it not in the list.
	bool IsOverlapping(const Element& element) const;
};

#endif // !SOLUTION_H