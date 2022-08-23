#ifndef CMD_USER_INTERFACE_H
#define CMD_USER_INTERFACE_H


#include "cmd_base.h"
#include "parser.h"

// Class 'CmdUserInterface' provides Commandline user interface

class CmdUserInterface
{
public:
	CmdUserInterface(CmdUserInterface& other) = delete;
	void operator=(const CmdUserInterface& other) = delete;

	static const CmdUserInterface& GetInstance();

	void NextCommand(const char* command = "") const;
	void NextCommand(const std::string& command) const; 
	void AddCommand(CmdBase* command_obj) const;

	static bool isCommand(const std::string& command_name);
	~CmdUserInterface();

	//TOOLS
	void PrintCmdMap() const;

protected:
	
	CmdUserInterface();


private:
	static std::unordered_map<std::string, CmdBase*> command_map_;
	static Lexer lexer_;
};




#endif // !CMD_USER_INTERFACE_H