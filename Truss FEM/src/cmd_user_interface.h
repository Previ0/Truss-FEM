#ifndef CMD_USER_INTERFACE_H
#define CMD_USER_INTERFACE_H

#include "cmd_creator.h"
#include "parser.h"

// Class 'CmdUserInterface' provides Commandline user interface
class CmdUserInterface {
public:
	CmdUserInterface(CmdUserInterface& other) = delete;
	void operator=(const CmdUserInterface& other) = delete;

	~CmdUserInterface();

	static const CmdUserInterface& GetInstance();

	void NextCommand(const char* command = "") const;
	void NextCommand(const std::string& command) const; 

protected:
	CmdUserInterface();

private:
	mutable CmdCreator cmd_creator_;
	mutable Lexer lexer_;
};




#endif // !CMD_USER_INTERFACE_H