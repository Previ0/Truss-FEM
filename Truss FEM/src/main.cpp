#include <iostream>

#include "solution.h"
#include "cui.h"
#include "utils/utility_functions.h"

// It's a program for calculating static mechanics of 2d Truss structures.

int main() {
	std::vector<Solution> solution_list;
	CUI* cui = CUI::GetInstance(solution_list);
	std::string command = "";

	// Welcome message
	std::cout << "Truss - FEM" << std::endl;
	std::cout << std::endl;

	// Passing commands until "exit" value
	do{
		command = Utils::PromptedInput<std::string>("Command: ");
	} while (cui->NextCommand(command));
	
	return 0;
}
