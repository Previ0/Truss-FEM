#include <iostream>

#include "delete_element.h"

using namespace Commands;

DeleteElement::DeleteElement(std::vector<Parser::Token> command_data) {

}

void DeleteElement::Execute() const {
	std::cout << "Deleted element" << std::endl;
	delete this;
}