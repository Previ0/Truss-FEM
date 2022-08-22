#include <iostream>

#include "cmd_base.h"

CmdBase::CmdBase(const char* caller) : caller_{ caller } {

}

const char* CmdBase::GetCaller() const {
	return caller_;
}

CmdBase::~CmdBase() {
	std::cout << "CmdBase has been destroyed." << std::endl;
}

std::string CmdBase::GetCommandName() const {
	return typeid(*this).name();
}

//CmdNoAction
CmdNoAction::CmdNoAction() : CmdBase("") {

}

void CmdNoAction::Execute() const {
	std::cout << "Command [CmdNoAction] has been invoked" << std::endl;
}

CmdNoAction::~CmdNoAction() {
	std::cout << "CmdNoAction has been destroyed." << std::endl;
}

//CmdPrinter

CmdPrinter::CmdPrinter() : CmdBase("print") {
	
}

void CmdPrinter::Execute() const {
	std::cout << "Command [CmdPrint] has been invoked" << std::endl;
}

CmdPrinter::~CmdPrinter() {
	std::cout << "CmdPrinter has been destroyed." << std::endl;
}

