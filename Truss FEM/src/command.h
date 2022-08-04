#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>
#include "solution.h"

class Command
{
private:
	enum CommandType
	{
		EXIT = 1, // must be 1
		PRINT_SOLUTION,
		PRINT_ELEMENTS,
		ADD_ELEMENT,
		DELETE_ELEMENT_BY_ID,
		WRITE_TO_FILE,
		READ_FROM_FILE,
		// ...
		DEFAULT
	};

	struct CommandMap : public std::map<std::string, CommandType> {
		CommandMap();
		~CommandMap();
	};

	void setType(const std::string& command);

	static CommandMap commands_;
	CommandType type_;
	Solution* solution_;

public:
	Command();
	Command(Solution* solution, const std::string& command);

	int Execute();

private:

};

#endif // !COMMAND_H