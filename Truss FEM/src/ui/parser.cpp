#include <string>
#include <iostream>

#include "parser.h"

//Tokenizer
Parser::Tokenizer::Tokenizer() {

}

void Parser::Tokenizer::extractTokens(std::string& command) {
	std::string temp = "";
	Token token;

	// Token creation
	for (char ch : command) {
		if (ch == ' ' || ch == '\0') {
			token = { NONE, temp };
			Tokenizer::tokens_.push_back(token);
			temp = "";
		}
		else {
			temp.push_back(ch);
		}
	}
	token = { NONE, temp };
	Tokenizer::tokens_.push_back(token);
}

inline std::vector<Parser::Token>& Parser::Tokenizer::getTokens() {
	return tokens_;
}

// Tokenizer - Utils

inline void Parser::Tokenizer::PrintTokens() {
	for (Token e : Tokenizer::tokens_) {
		std::cout << e.type << ", " << e.data << ", size: " << e.data.length()  << std::endl;
	}
}


//Parser

Parser* Parser::instance_ = nullptr;
Parser::Tokenizer* Parser::tokenizer_ = nullptr;

Parser::Parser() {
	//tokenizer_ = std::vector<Token>{};
}

Parser* Parser::GetInstance() {

	if (instance_ == nullptr) instance_ = new Parser();
	if (tokenizer_ == nullptr) tokenizer_ = new Parser::Tokenizer();

	return instance_;
}

std::vector<Parser::Token>& Parser::Parse(std::string& command) {
	tokenizer_->extractTokens(command);
	tokenizer_->PrintTokens();

	return tokenizer_->getTokens();
}

