#include <string>
#include <iostream>

#include "command_list.h"
#include "cli.h"



const CommandMap CLI::kCommands_ = {
	{ "addel", ADD_ELEMENT },
	{ "delel", DELETE_ELEMENT }
};

CLI* CLI::instance_ = nullptr;

CLI::CLI() : parser_{ Parser::GetInstance() }, command_{ nullptr } {

}

inline void CLI::ExecuteCommand() {
	command_->Execute();
}

CLI* CLI::GetInstance() {

	if (instance_ == nullptr) {
		instance_ = new CLI();
	}

	return instance_;
}

void CLI::SendCommand(std::string& command) {
	command_ = CreateCommand(parser_->Parse(command));
	this->ExecuteCommand();
}

inline Command* CLI::CreateCommand(std::vector<Parser::Token>& tokens) {
	return CLI::getCommandObj(tokens);
}

Command* CLI::getCommandObj(std::vector<Parser::Token>& command_data) {

	auto name = kCommands_.find(command_data[0].data);
	switch (name->second) {

		using namespace Commands;
		case ADD_ELEMENT:	 return new AddElement(command_data);
		case DELETE_ELEMENT: return new DeleteElement(command_data);
	}


	return nullptr;
}