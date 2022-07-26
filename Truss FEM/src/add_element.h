#ifndef ADD_ELEMENT_H
#define ADD_ELEMENT_H

#include "command.h"

namespace Commands {
	class AddElement : public Command
	{
	private:
	public:
		AddElement(std::vector<Parser::Token> command_data);
		void Execute() const override;
	};

}

#endif // !ADD_ELEMENT_H