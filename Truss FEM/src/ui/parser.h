#ifndef PARSER_H
#define PARSER_H

//Singleton
//
//enum TokenType{
//
//};
//
//struct Token {
//	TokenType type;
//	std::string data;
//};

class Parser
{
private:
	static Parser* instance_;
	//std::vector<Token*> tokens_;

private:
	Parser();

public:
	Parser(Parser& other) = delete;
	void operator=(Parser&) = delete;
	static Parser* GetInstance();
};

#endif // !PARSER_H