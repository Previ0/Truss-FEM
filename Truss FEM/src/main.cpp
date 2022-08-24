#include <iostream>
#include <string>
#include "cmd_user_interface.h"


int main() {

	const CmdUserInterface& cui = CmdUserInterface::GetInstance();

	//In place tests
	cui.NextCommand("");
	cui.NextCommand("print -element \"asdasa22sddas\" .1234 10.23 123d 9.1s323 1 2 3 4");
	CmdCreator::AddCommand(new CmdPrinter());
	std::string siema{ "print" };
	cui.NextCommand(siema);
	cui.NextCommand();
	CmdCreator::PrintCmdMap();

	getchar();
	return 0;
}