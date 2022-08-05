#include <iostream>

#include "solution.h"
#include "utils/utility_functions.h"

Solution::Solution()
{
}

void Solution::PrintElements()
{
	for (Element e : element_list_) e.Print();
}

void Solution::AddElement()
{
	float vector4f[4];

	// Asking for input coordinates of the element.
	for (int i = 0; i < 4; ++i) {
		vector4f[i] = Utils::PromptedInput<float>(std::to_string(i) + ": "); //to_string C++11
	}

	element_list_.push_back(Element(vector4f[0], vector4f[1], vector4f[2], vector4f[3]));
}



void Solution::AddElement(float i_x, float i_y, float j_x, float j_y)
{
	element_list_.push_back(Element(i_x, i_y, j_x, j_y));
}
