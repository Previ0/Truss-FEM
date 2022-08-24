#include <iostream>

#include "cmd_base.h"
#include "debug_macros.h"

CmdBase::CmdBase(const char* caller) : caller_{ caller } {

}

const char* CmdBase::GetCaller() const {
	return caller_;
}

CmdBase::~CmdBase() {
	std::cout << "CmdBase has been destroyed." << std::endl;
}

const char* CmdBase::GetCommandName() const {
	return typeid(*this).name();
}

//CmdNoAction
CmdNoAction::CmdNoAction() : CmdBase("") {

}

void CmdNoAction::Execute() const {
	DEBUG_MESSAGE(<caller_>, "Executed");
}

CmdNoAction::~CmdNoAction() {
	std::cout << "CmdNoAction has been destroyed." << std::endl;
}

//CmdPrinter
CmdPrinter::CmdPrinter() : CmdBase("print") {
	
}

void CmdPrinter::Execute() const {
	DEBUG_MESSAGE(<caller_>, "Executed");
}

CmdPrinter::~CmdPrinter() {
	std::cout << "CmdPrinter has been destroyed." << std::endl;
}

