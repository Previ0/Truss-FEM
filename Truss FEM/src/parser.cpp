#include <iostream>

#include "parser.h"

// TOKEN

std::map<TokenType, const char*> Token::token_type_map = {
	{TokenType::WHITESPACE,		"WHITESPACE"},
	{TokenType::COMMAND,		"COMMAND"},
	{TokenType::STRING_LITERAL, "STRING_LITERAL"},
	{TokenType::ARGUMENT,		"ARGUMENT"},
	{TokenType::OPTION,			"OPTION"},
	{TokenType::INTEGER,		"INTEGER"},
	{TokenType::FLOATING_POINT, "FLOATING_POINT"},

};

const char* Token::getTokenTypeString(TokenType type) {
	return token_type_map[type];
}

// Lexer

Lexer::Lexer() {

}

void Lexer::Parse(std::string_view data) {
	std::cout << "Parsing started..." << std::endl;
	Token temp;

	for (auto ch : data) {
		
		switch (ch)
		{
		case '.':
			if (temp.type == TokenType::INTEGER || temp.type == TokenType::WHITESPACE) {
				temp.type = TokenType::FLOATING_POINT;
			}
			temp.text.append(1, ch);
			break;

		case '-':
			if (temp.type == TokenType::WHITESPACE) {
				temp.type = TokenType::OPTION;
			}
			temp.text.append(1, ch);
			break;

		case '\"':
			if (temp.type == TokenType::WHITESPACE) {
				temp.type = TokenType::STRING_LITERAL;
			}
			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (temp.type == TokenType::WHITESPACE) {
				temp.type = TokenType::INTEGER;
			}
			temp.text.append(1, ch);
			break;
		case ' ':
		case '\t':
		case '\r':
		case '\n':
		case '\v':
		case '\f':
			if (temp.type != TokenType::WHITESPACE)
				pushToken(temp);
			break;

		default: 
			if (temp.type == TokenType::WHITESPACE) {
				temp.type = TokenType::ARGUMENT;
			}
			if (temp.type == TokenType::INTEGER || temp.type == TokenType::FLOATING_POINT) {
				temp.type = TokenType::ARGUMENT;
			}
			temp.text.append(1, ch);
			break;
		}
	}
	pushToken(temp);
	
	PrintTokens();
}

void Lexer::pushToken(Token& token) {
	std::cout << "Token pushed" << std::endl;
	if (token.type != TokenType::WHITESPACE) {
		tokens_.push_back(token);
		token.type = TokenType::WHITESPACE;
		token.text.erase();
	}
}


void Lexer::PrintTokens() const {

	for (auto token : tokens_) {
		std::cout << "[ " << Token::getTokenTypeString(token.type) << ", " << token.text << " ]" << std::endl;
	}
}
