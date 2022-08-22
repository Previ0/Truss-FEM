#include <iostream>
#include <unordered_map>
#include <string>
#include "cmd_user_interface.h"
#include "parser.h"

void Print(std::string_view siema) {
	std::cout << siema << std::endl;
}

int main() {

	//const CmdUserInterface& cui = CmdUserInterface::GetInstance();
	//cui.NextCommand("");
	//cui.NextCommand("print");
	//cui.AddCommand(new CmdPrinter());
	//std::string siema{ "print" };
	//cui.NextCommand(siema);
	//cui.NextCommand();
	//cui.PrintCmdMap();
	//Parser parser;
	//std::string siema = "prints";
	//parser.NextCommand(siema);


	Lexer lexer_;

	lexer_.Parse("add -element \"asdasa22sddas\" .1234 10.23 123d 9.1s323 1 2 3 4");


	getchar();
	return 0;
}