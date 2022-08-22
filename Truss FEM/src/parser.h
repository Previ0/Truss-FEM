#ifndef PARSER_H
#define PARSER_H

#include <string_view>
#include <string>
#include <vector>
#include <map>



enum class TokenType {
	WHITESPACE,			//0
	COMMAND,			//1
	STRING_LITERAL,		//2
	ARGUMENT,			//3
	OPTION,				//4
	INTEGER,			//5
	FLOATING_POINT,		//6
};

struct Token {	
	TokenType type{ TokenType::WHITESPACE };
	std::string text{};

	static const char* getTokenTypeString(TokenType type);
	static std::map<TokenType, const char*> token_type_map;
};

class Lexer {
public: //Methods
	Lexer();
	void Parse(std::string_view data);

private: //Methods
	void pushToken(Token& temp);

	void PrintTokens() const;

private: //Members
	const std::string_view input_string_;
	std::vector<Token> tokens_;
};

#endif // !PARSER_H