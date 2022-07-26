#ifndef COMMAND_H
#define COMMAND_H

#include "../ui/parser.h"

enum CommandName {
	ADD_ELEMENT,
	DELETE_ELEMENT
};

class Command
{
private:
	static std::vector<std::string> command_list_;
public:
	virtual ~Command();
	virtual void Execute() const = 0;

	inline static std::vector<std::string> getCommandList();
	static Command* getCommandObj(std::string command_name);

};

#endif // !COMMAND_H