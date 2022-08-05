#include <iostream>

#include "command.h"

// CommandMap
Command::CommandMap::CommandMap() {
	this->operator[] ("exit") = EXIT;	
	this->operator[] ("prts") = PRINT_SOLUTION;	
	this->operator[] ("addel") = ADD_ELEMENT;	
}

Command::CommandMap::~CommandMap() {}

// Command
Command::Command() : type_{ DEFAULT }, solution_{ nullptr } {}

Command::Command(Solution* solution, const std::string& command) :
	type_{ commands_[command] }, solution_{ solution }
{}

void Command::setType(const std::string& command) {
	type_ = commands_[command];
}


int Command::Execute() {

	// Selecting what action to take
	switch (this->type_)
	{
	case EXIT:
		return 0; //must be 0

	case PRINT_SOLUTION:
		solution_->PrintElements();
		break;

	case ADD_ELEMENT:
		solution_->AddElement();
		break;

	case DELETE_ELEMENT_BY_ID:
		break;

	default: 
		std::cout << "Improper command" << std::endl;
		return DEFAULT;
	}

	return this->type_;
}

// Initializing command map
Command::CommandMap Command::commands_{};