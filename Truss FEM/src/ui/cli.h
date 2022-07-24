#ifndef CLI_H
#define CLI_H

#include "parser.h"

//singleton

class CLI
{
private:
	static CLI* instance_;
	static Parser* parser_;
private:
	CLI();
	void Execute(std::vector<Parser::Token>& tokens);

public:
	CLI(CLI& other) = delete; //not clonable
	void operator=(const CLI&) = delete;
	static CLI * getInstance();
	void Command(std::string &command);
	/*void Command(std::string command);*/
};

#endif // !CLI_H
