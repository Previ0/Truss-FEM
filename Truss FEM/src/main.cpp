#include <iostream>
#include "geom/point.h"
#include "ui/cli.h"
#include "ui/parser.h"
// https://www.linkedin.com/pulse/what-general-c-project-structure-like-herbert-elwood-gilliland-iii
// https://google.github.io/styleguide/cppguide.html

int main() {
	CLI* cli = CLI::getInstance();
	std::string add = "AddElement  sadfasd asdffff ffdfd";
	cli->Execute();


	return 0;
}
