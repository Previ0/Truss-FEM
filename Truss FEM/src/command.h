#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "parser.h"

// abstract Class providing basic interface for specific commands.
class Command
{

protected:
	 Command();

public:
	virtual ~Command();
	virtual void Execute() const = 0;
private:
	
};

#endif // !COMMAND_H