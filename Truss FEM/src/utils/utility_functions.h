#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <iostream>
#include <string>

namespace Utils
{
	template <typename T>
	inline T PromptedInput(std::string prompt_message);



}

template<>
inline float Utils::PromptedInput<float>(std::string prompt_message) {
	float value;
	std::cout << prompt_message;
	std::cin >> value;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();

	return value;
}

template<>
inline std::string Utils::PromptedInput<std::string>(std::string prompt_message) {
	std::string value;
	std::cout << prompt_message;
	std::getline(std::cin, value);
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	
	return value;
}




#endif // !UTILITY_FUNCTIONS_H