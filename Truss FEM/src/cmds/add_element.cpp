#include <iostream>

#include "add_element.h"

Commands::AddElement::AddElement(std::vector<Parser::Token> tokens) : tokens_{ tokens } {

}

void Commands::AddElement::Execute() const {
	std::cout << "Added element" << std::endl;
}