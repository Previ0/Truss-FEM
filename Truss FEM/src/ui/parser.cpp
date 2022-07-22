#include <vector>
#include <string>

#include "parser.h"

Parser* Parser::instance_ = nullptr;

Parser::Parser() {
	//tokens_ = std::vector<Token*>();
}

Parser* Parser::GetInstance() {

	if (instance_ == nullptr) {
		instance_ = new Parser();
	}

	return instance_;
}

