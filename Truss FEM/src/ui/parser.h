#ifndef PARSER_H
#define PARSER_H

#include <vector>

//Singleton

class Parser
{
public:
	enum TokenType {
		NONE, NEXT, LAST
	};

	struct Token
	{
	public:
		TokenType type;
		std::string data;
	};

private:
	class Tokenizer {
	private:
		std::vector<Token> tokens_;
	public:
		Tokenizer();
		void extractTokens(std::string& command);
		std::vector<Token>& getTokens();
		// Utils
		inline void PrintTokens();
	};

	static Parser* instance_;
	static Tokenizer* tokenizer_;

private:
	Parser();

public:
	Parser(Parser& other) = delete;
	void operator=(Parser&) = delete;
	static Parser* GetInstance();
	std::vector<Token>& Parse(std::string& command);


};

#endif // !PARSER_H