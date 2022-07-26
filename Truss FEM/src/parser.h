#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

//Singleton


class Parser
{
public:
	enum TokenType {
		COMMAND_NAME, STR_VALUE, NUM_VALUE, FLOAT_VALUE, OPTION
	};

	struct Token
	{
		TokenType type;
		std::string data;
	};

private:
	class Tokenizer {
	private:
		
	public:
		Tokenizer();
		void extractTokens(std::string& command);
	};

	static Parser* instance_;
	static Tokenizer* tokenizer_;
	static std::vector<Token> tokens_;

private:
	Parser();
	bool AreTokensCorrect();

public:
	Parser(Parser& other) = delete;
	void operator=(Parser&) = delete;
	static Parser* GetInstance();
	std::vector<Token>& Parse(std::string& command);
	std::vector<Token> getTokens();
	//utils
	inline void PrintTokens();

};

#endif // !PARSER_H