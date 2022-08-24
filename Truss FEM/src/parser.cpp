#include <iostream>

#include "cmd_user_interface.h"
#include "parser.h"
#include "debug_macros.h"

// TOKEN
const std::map<TokenType, const char*> Token::token_type_map = {
	{TokenType::kWhitespace,	"WHITESPACE"		},
	{TokenType::kCommand,		"COMMAND"			},
	{TokenType::kStringLiteral, "STRING_LITERAL"	},
	{TokenType::kArgument,		"ARGUMENT"			},
	{TokenType::kOption,		"OPTION"			},
	{TokenType::kInteger,		"INTEGER"			},
	{TokenType::kFloatingPoint, "FLOATING_POINT"	},

};

const char* Token::getTokenTypeString(TokenType type) {
	return token_type_map.at(type);
}

// Lexer
Lexer::Lexer() {
	DEBUG_MESSAGE(Lexer, "instantiated.");
}

const std::vector<Token>& Lexer::Parse(std::string_view data) {

	DEBUG_MESSAGE(Lexer, "parsing has started");

	Token temp;

	for (auto ch : data) {
		
		switch (ch)
		{
		case '.':
			if (temp.type == TokenType::kInteger || temp.type == TokenType::kWhitespace) {
				temp.type = TokenType::kFloatingPoint;
			}
			temp.text.append(1, ch);
			break;

		case '-':
			if (temp.type == TokenType::kWhitespace) {
				temp.type = TokenType::kOption;
			}
			//temp.text.append(1, ch);
			break;

		case '\"':
			if (temp.type == TokenType::kWhitespace) {
				temp.type = TokenType::kStringLiteral;
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
			if (temp.type == TokenType::kWhitespace) {
				temp.type = TokenType::kInteger;
			}
			temp.text.append(1, ch);
			break;
		case ' ':
		case '\t':
		case '\r':
		case '\n':
		case '\v':
		case '\f':
			if (temp.type != TokenType::kWhitespace) {
				if (CmdCreator::IsCommand(temp.text))
					temp.type = TokenType::kCommand;
				pushToken(temp);

			}
			break;

		default: 
			if (temp.type == TokenType::kWhitespace) {
				temp.type = TokenType::kArgument;
			}
			if (temp.type == TokenType::kInteger || temp.type == TokenType::kFloatingPoint) {
				temp.type = TokenType::kArgument;
			}
			temp.text.append(1, ch);
			break;
		}
	}
	pushToken(temp);
	
	PrintTokens();
	return tokens_;
}

 bool Lexer::isCommand(Token& token) {
	if (token.type == TokenType::kArgument&&
		CmdCreator::IsCommand(token.text))
	{
		return true;
	}
	return false;
}

void Lexer::pushToken(Token& token) {
	if (token.type != TokenType::kArgument) {
		tokens_.push_back(token);
		token.type = TokenType::kWhitespace;
		token.text.erase();
	}
}

void Lexer::PrintTokens() const {

	for (auto token : tokens_) {
		std::cout << "[ " << Token::getTokenTypeString(token.type) << ", " << token.text << " ]" << std::endl;
	}
}
