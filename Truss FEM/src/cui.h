#ifndef CUI_H
#define CUI_H

#include <vector>
#include "solution.h"

// Commandline user interface
// Designed as a singleton to instantiane the class object call static method 'GetInstance()'.
class CUI
{
private:
	std::vector<Solution>* solution_list_ptr_;
	Solution* current_solution_;

protected:
	static CUI* instance_;
protected:
	CUI();
	CUI(std::vector<Solution> &solution_list);
public:
	CUI(CUI& other) = delete; //cannot be cloned 
	void operator=(const CUI&) = delete;

	// Instantiates CUI class and returns a pointer to a singleton instance.
	static CUI* GetInstance(std::vector<Solution> &solution_list);

	// Takes a string as a command to be executed.
	int NextCommand(const std::string& command); //TO-DO
};

#endif // !CUI_H