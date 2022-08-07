#include "math_functions.h"

// TO-DO
// Test CompareFloat


bool math::AreFloatsEqual(const float a, const float b,	const float epsilon)
{
	return fabs(a - b) < epsilon;
}