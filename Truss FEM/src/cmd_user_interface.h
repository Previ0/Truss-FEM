#ifndef CMD_USER_INTERFACE_H
#define CMD_USER_INTERFACE_H

#include <unordered_map>
#include "cmd_base.h"
#include "parser.h"

class CmdUserInterface
{
public:
	CmdUserInterface(CmdUserInterface& other) = delete;
	void operator=(const CmdUserInterface& other) = delete;

	static const CmdUserInterface& GetInstance();

	void NextCommand(const char* command ="") const;
	void NextCommand(const std::string& command) const; 
	void AddCommand(const CmdBase* command_obj) const;

	~CmdUserInterface();

	//TOOLS
	void PrintCmdMap() const;

protected:
	
	CmdUserInterface();


private:
	static std::unordered_map<std::string ,const CmdBase*> command_map_;
	//static Parser parser_;
};

#endif // !CMD_USER_INTERFACE_H