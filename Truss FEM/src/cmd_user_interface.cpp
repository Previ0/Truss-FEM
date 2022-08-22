#include <iostream>

#include "cmd_user_interface.h"

std::unordered_map<std::string,const CmdBase*> CmdUserInterface::command_map_ = {};

CmdUserInterface::CmdUserInterface() {
	std::cout << "[ CmdUserInterface ] initialized." << std::endl;
	
	AddCommand(new CmdNoAction());
	AddCommand(new CmdPrinter());

}

void CmdUserInterface::AddCommand(const CmdBase* command_obj) const {
	if (command_map_.find(command_obj->GetCaller()) == command_map_.end()) {
	command_map_[command_obj->GetCaller()] = command_obj;
	}
	else {
		std::cout << "Caller with specified name \"" << command_obj->GetCaller() << "\" already exists.\n";
	}
}

void CmdUserInterface::NextCommand(const char* command) const {
	command_map_[command]->Execute();
}

void CmdUserInterface::NextCommand(const std::string& command) const {
	command_map_[command]->Execute();
}

const CmdUserInterface& CmdUserInterface::GetInstance() {
	static CmdUserInterface instance_{};
	return instance_;
}



CmdUserInterface::~CmdUserInterface() {
	for (auto& it : command_map_) {
		delete it.second;
	}
}


// Tools

void CmdUserInterface::PrintCmdMap() const {
	for (auto const& pair : command_map_) {
		std::cout << "{ \"" << pair.first << "\" : " << pair.second->GetCommandName() << " }" << std::endl;
	}
}