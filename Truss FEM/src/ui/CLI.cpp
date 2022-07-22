#include <string>
#include <iostream>

#include "parser.h"

#include "cli.h"

CLI* CLI::instance_ = nullptr;

CLI::CLI() {
}

CLI* CLI::getInstance() {

	if (instance_ == nullptr) {
		instance_ = new CLI();
	}
	return instance_;
}

void CLI::Command(std::string &command) {
	std::cout << "[ " << command << " ] - " << "command has been executed." << std::endl;
}

//void CLI::Command(std::string command) {
//	std::cout << "[ " << command << " ] - " << "command has been executed." << std::endl;
//}
