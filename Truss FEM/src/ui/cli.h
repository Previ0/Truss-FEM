#ifndef CLI_H
#define CLI_H

#include "parser.h"
#include "../cmds/command.h"

//singleton

class CLI
{
private:
	static CLI* instance_;
	static Parser* parser_;
	Command* command_;
private:
	CLI();
	inline void Execute();
	Command* CreateCommand(std::vector<Parser::Token>& tokens);

public:
	CLI(CLI& other) = delete; //not clonable
	void operator=(const CLI&) = delete;
	static CLI * getInstance();
	void SetCommand(std::string &command);
	/*void Command(std::string command);*/
};

#endif // !CLI_H
