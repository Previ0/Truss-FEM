#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <iostream>
#include <string>

namespace utils
{
	template <typename T>
	inline T PromptedInput(std::string prompt_message);



}

template<>
inline float utils::PromptedInput<float>(std::string prompt_message) {
	using namespace std;
	
	float value;
	cout << prompt_message;
	cin >> value;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	return value;
}

// Returns 
template<>
inline std::string utils::PromptedInput<std::string>(std::string prompt_message) {
	using namespace std;

	string value;
	cout << prompt_message;
	getline(cin, value);
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.clear();
	
	return value;
}




#endif // !UTILITY_FUNCTIONS_H