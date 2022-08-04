#include <iostream>

#include "solution.h"
#include "cui.h"

int main() {
	std::vector<Solution> solution_list;
	CUI* cui = CUI::GetInstance(solution_list);
	std::string command = "";

	// Passing commands until "exit" value
	do{
		std::cin >> command;
	} while (cui->NextCommand(command));
	
	return 0;
}
