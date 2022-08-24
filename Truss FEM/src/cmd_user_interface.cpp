#include <iostream>

#include "cmd_user_interface.h"
#include "debug_macros.h"

CmdUserInterface::CmdUserInterface() : lexer_{}, cmd_creator_{} {
	DEBUG_MESSAGE(CUI, "Initialized.");
}

void CmdUserInterface::NextCommand(const char* command) const {
	
}

void CmdUserInterface::NextCommand(const std::string& command) const {
	lexer_.Parse(command);
	//command_map_[command]->Execute();
}

const CmdUserInterface& CmdUserInterface::GetInstance() {
	static const CmdUserInterface instance_{};
	return instance_;
}

CmdUserInterface::~CmdUserInterface() {

}