#include <iostream>

#include "cmd_creator.h"
#include "debug_macros.h"

std::unordered_map<std::string, CmdBase*> CmdCreator::command_pool_{};

CmdCreator::CmdCreator() {
	static const bool init = Init();
	DEBUG_MESSAGE(Command Creator, "Instatiated.");
}

void CmdCreator::Create(std::vector<Token>& tokens) {
	/*TO-DO*/
	// KArgument case.

	for (auto& token : tokens) {
		switch (token.type)
		{
		case TokenType::kCommand:
			queue_.push(command_pool_[token.text]);
			break;

		case TokenType::kOption:
			queue_.back()->PushOption(token.text);
			break;

		case TokenType::kStringLiteral:
			queue_.back()->PushStringArg(token.text);
			break;

		case TokenType::kFloatingPoint:
			queue_.back()->PushFloatArg(std::stod(token.text));
			break;

		case TokenType::kInteger:
			queue_.back()->PushIntArg(std::stoi(token.text));
			break;

		case TokenType::kArgument:
			/*TO-DO*/
			break;

		default:
			DEBUG_MESSAGE(Command Creator, "Unsuccessful command creation.");
			while (!queue_.empty()) {
				queue_.front()->Reset();
				queue_.pop();
			}
			return;
		}
	}
	tokens.clear();
}

bool CmdCreator::IsCommand(const std::string& command_name) {
	return command_pool_.count(command_name) > 0;
}

void CmdCreator::AddCommand(CmdBase* command_obj) {
	const auto& caller = command_obj->GetCaller();
	
	if (IsCommand(caller) == 0) {
		command_pool_[caller] = command_obj;
		DEBUG_MESSAGE(Command Creator, "New command added <" << caller << ">.");
	}
	else {
		DEBUG_MESSAGE(Command Creator, "Caller <" << caller << "> name already exists.");
	}
	
}

void CmdCreator::PrintCmdMap() {
	std::cout << "===== Command List =====" << std::endl;
	for (auto const& pair : command_pool_) {
		std::cout << "<" << pair.first << "> - " << pair.second->GetCommandName() << std::endl;
	}
}

bool CmdCreator::Init() {
	DEBUG_MESSAGE(Command Creator, "Initialized.");
	AddCommand(new CmdNoAction());
	AddCommand(new CmdPrinter());

	return true;
}