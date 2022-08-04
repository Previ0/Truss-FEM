#include <iostream>

#include "command.h"

// CommandMap
Command::CommandMap::CommandMap() {
	this->operator[] ("exit") = EXIT;	
	this->operator[] ("add") = EXIT;	
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
	switch (this->type_)
	{
	case EXIT:
		break;
	case ADD_ELEMENT: break;
	case DELETE_ELEMENT_BY_ID: break;

	default: 
		std::cout << "Improper command" << std::endl;
		break;
	}
}

// Initializing command map
Command::CommandMap Command::commands_{};