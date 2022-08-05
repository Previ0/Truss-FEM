#include <string>

#include "cui.h"
#include "command.h"



CUI* CUI::instance_{ nullptr };

CUI::CUI() :
	solution_list_ptr_{ nullptr },
	current_{ nullptr }
{

}

CUI::CUI(std::vector<Solution> &solution_list) :
	solution_list_ptr_{ &solution_list },
	current_{ nullptr }
{
	// Creating Empty solution
	if (solution_list_ptr_->size() == 0) {
		solution_list_ptr_->push_back(Solution());
	}
	current_ = &solution_list[0];
}

CUI* CUI::GetInstance(std::vector<Solution> &solution_list)
{
	// Creating instance of CUI - singleton
	if (instance_ == nullptr) {
		instance_ = new CUI(solution_list);
	}
	return instance_;
}

int CUI::NextCommand(const std::string& command) {
	// TO-DO - Parser, that's why Command is an object
	Command temp{current_ ,command};
	return temp.Execute();
}