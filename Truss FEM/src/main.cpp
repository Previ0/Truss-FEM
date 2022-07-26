#include <iostream>
#include "geom/point.h"
#include "cli.h"

// https://www.linkedin.com/pulse/what-general-c-project-structure-like-herbert-elwood-gilliland-iii
// https://google.github.io/styleguide/cppguide.html

int main() {
	CLI* cli = CLI::GetInstance();
	std::string command;
	getline(std::cin, command);
	cli->SendCommand(command);
	return 0;
}
