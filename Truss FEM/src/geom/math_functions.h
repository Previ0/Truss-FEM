#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <limits>

namespace math {

	// Returns:
	// true  - If floats(a, b) are approximately equal (it means that absolute difference is less then given epsilon.
	// false - If floats(a, b) are not approximately equal.
	bool AreFloatsEqual(
		const float a,
		const float b,
		const float epsilon = std::numeric_limits<float>::epsilon()
	);


}

#endif // !MATH_FUNCTIONS_H

