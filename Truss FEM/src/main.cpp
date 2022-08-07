#include <iostream>

#include "solution.h"
#include "geom/math_functions.h"
#include "cui.h"
#include "utils/utility_functions.h"

// It's a program for calculating static mechanics of 2d Truss structures.

int main() {
	using namespace std;

	vector<Solution> solution_list;
	CUI* cui = CUI::GetInstance(solution_list);
	string command = "";

	// Welcome message
	cout << "Truss - FEM" << endl;
	cout << endl;

	// Passing commands until "exit" value
	do{
		command = utils::PromptedInput<string>("Command: ");
	} while (cui->NextCommand(command));
	
	return 0;
}
