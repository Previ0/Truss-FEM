#ifndef ADD_ELEMENT_H
#define ADD_ELEMENT_H

#include "command.h"
namespace Commands {
	class AddElement : public Command
	{
	private:
		std::vector<Parser::Token> tokens_;
	public:
		AddElement(std::vector<Parser::Token> tokens);
		void Execute() const override;
	};

}

#endif // !ADD_ELEMENT_H