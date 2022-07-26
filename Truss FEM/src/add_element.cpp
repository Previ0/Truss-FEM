#include <iostream>

#include "add_element.h"

using namespace Commands;

AddElement::AddElement(std::vector<Parser::Token> command_data) {

}

void AddElement::Execute() const {
	std::cout << "Added element" << std::endl;
	delete this; // deletes object right after its execution.
}