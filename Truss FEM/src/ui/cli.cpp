#include <string>
#include <iostream>
#include "../cmds/add_element.h"

#include "cli.h"

CLI* CLI::instance_ = nullptr;
Parser* CLI::parser_ = Parser::GetInstance();

CLI::CLI() {
}

inline void CLI::Execute() {
	command_->Execute();
	delete command_;
}

CLI* CLI::getInstance() {

	if (instance_ == nullptr) {
		instance_ = new CLI();
	}
	return instance_;
}

void CLI::SetCommand(std::string& command) {
	command_ = CreateCommand(parser_->Parse(command));
	std::cout << "[ " << command << " ] - " << "command has been created." << std::endl;
}

Command* CLI::CreateCommand(std::vector<Parser::Token>& tokens) {
	Command* temp = nullptr;
	std::string command_name = tokens[0].data;

	for (std::string c : Command::getCommandList())
	if (command_name == c) temp = new Command::getCommandObj(command_name);
	// ...

	return temp;
}

//void CLI::Command(std::string command) {
//	std::cout << "[ " << command << " ] - " << "command has been executed." << std::endl;
//}
