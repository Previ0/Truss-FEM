#include <iostream>

#include "parser.h"

//Tokenizer
Parser::Tokenizer::Tokenizer() {

}

void Parser::Tokenizer::extractTokens(std::string& command) {
	std::string temp = "";
	Token token;
	TokenType type = COMMAND_NAME;

	// Token creation
	for (char ch : command) {
		if (ch == ' ' || ch == '\0') {
			if (temp.empty()) continue;
			if (temp[0] == '-') type = OPTION;
			//if () 
			token = { type, temp };
			tokens_.push_back(token);
			temp = "";
		}
		else {
			temp.push_back(ch);
		}
	}
	token = { COMMAND_NAME, temp };
	tokens_.push_back(token);
}

inline void Parser::PrintTokens() {
	for (Token e : tokens_) {
		std::cout << e.type << ", " << e.data << ", size: " << e.data.length()  << std::endl;
	}
}

//Parser

Parser* Parser::instance_ = nullptr;
Parser::Tokenizer* Parser::tokenizer_ = nullptr;
std::vector<Parser::Token> Parser::tokens_;

Parser::Parser() {

}

bool Parser::AreTokensCorrect() {
	int i = { 0 }; // Command token counter

	for (Token e : tokens_) {
		if (e.type = COMMAND_NAME) i++;
	}
	return (i == 0 || i > 1) ? false : true;
}

Parser* Parser::GetInstance() {
	if (instance_ == nullptr) instance_ = new Parser();
	if (tokenizer_ == nullptr) tokenizer_ = new Parser::Tokenizer();

	return instance_;
}

std::vector<Parser::Token>& Parser::Parse(std::string& command) {
	tokenizer_->extractTokens(command);
	Parser::PrintTokens();
	//if (!Parser::areTokensCorrect()) {
	//	return;// -> throw an error
	//}


	return tokens_;
}

std::vector<Parser::Token> Parser::getTokens() { return tokens_; }