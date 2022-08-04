#include "solution.h"

Solution::Solution()
{
}

void Solution::PrintElements()
{
	for (Element e : element_list_) e.Print();
}






// TESTING METHODS
void Solution::add_element(float i_x, float i_y, float j_x, float j_y)
{
	element_list_.push_back(Element(i_x, i_y, j_x, j_y));
}

