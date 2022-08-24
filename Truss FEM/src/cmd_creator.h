#ifndef CMD_CREATOR_H
#define CMD_CREATOR_H

#include <vector>
#include <queue>
#include <unordered_map>
#include "cmd_base.h"
#include "parser.h"

class CmdCreator
{
public:

	CmdCreator();

	static bool IsCommand(const std::string& command_name);
	static void AddCommand(CmdBase* command_obj);
	static void PrintCmdMap();

private:
	/*TO-DO*/ void Create(std::vector<Token>& tokens_);
	bool Init();

	std::queue<CmdBase*> queue_;
	static std::unordered_map<std::string, CmdBase*> command_pool_;
};

#endif // !CMD_CREATOR_H