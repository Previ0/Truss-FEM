#ifndef CLI_H
#define CLI_H

//singleton

class CLI
{
private:
	static CLI* instance_;
private:
	CLI();

public:
	CLI(CLI& other) = delete; //not clonable
	void operator=(const CLI&) = delete;
	static CLI * getInstance();
	void Command(std::string &command);
	/*void Command(std::string command);*/
};

#endif // !CLI_H