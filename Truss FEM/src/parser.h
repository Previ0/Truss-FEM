#ifndef PARSER_H
#define PARSER_H

#include <string_view>
#include <string>
#include <vector>
#include <map>

enum class TokenType {
	kWhitespace,		//0
	kCommand,			//1
	kStringLiteral,		//2
	kArgument,			//3
	kOption,			//4
	kInteger,			//5
	kFloatingPoint,		//6
};

struct Token {
public:
	const static std::map<TokenType, const char*> token_type_map;

	static const char* getTokenTypeString(TokenType type);
	
	TokenType type{ TokenType::kWhitespace };
	std::string text{};
};

class Lexer {
public:
	Lexer();

	const std::vector<Token>& Parse(std::string_view data);

private:
	void pushToken(Token& temp);
	void PrintTokens() const;
	static bool isCommand(Token& token);

	std::vector<Token> tokens_;
	const std::string_view input_string_;
};

#endif // !PARSER_H