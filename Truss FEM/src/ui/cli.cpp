#include <string>
#include <iostream>

#include "cli.h"

CLI* CLI::instance_ = nullptr;
Parser* CLI::parser_ = Parser::GetInstance();

CLI::CLI() {
}

void CLI::Execute(std::vector<Parser::Token>& tokens) {
	//To-do
	tokens.clear();
}

CLI* CLI::getInstance() {

	if (instance_ == nullptr) {
		instance_ = new CLI();
	}
	return instance_;
}

void CLI::Command(std::string &command) {

	Execute(parser_->Parse(command));
	std::cout << "[ " << command << " ] - " << "command has been executed." << std::endl;
}

//void CLI::Command(std::string command) {
//	std::cout << "[ " << command << " ] - " << "command has been executed." << std::endl;
//}
