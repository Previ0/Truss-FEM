#ifndef CLI_H
#define CLI_H

#include <map>
#include "parser.h"
#include "command.h"

enum CommandName;

typedef std::map<std::string, int> CommandMap;

// Command Line Interpreter class designed as a singlton

class CLI
{
private:
	static CLI* instance_;
	Parser* parser_;
	Command* command_;
	const static CommandMap kCommands_;

	CLI();
	inline void ExecuteCommand();
	inline Command* CreateCommand(std::vector<Parser::Token>& tokens);

public:
	CLI(CLI& other) = delete; // not clonable - defined due to sigleton requirements
	
	static CLI * GetInstance(); // defined due to singleton requirements
	void SendCommand(std::string &command);
	static Command* getCommandObj(std::vector<Parser::Token>& command_data);


	void operator=(const CLI&) = delete;
};

#endif // !CLI_H