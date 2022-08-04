#ifndef CUI_H
#define CUI_H

#include <vector>
#include "solution.h"

// Class description

class CUI
{
private:
	std::vector<Solution>* solution_list_ptr_;
	Solution* current_;
protected:
	static CUI* instance_;
protected:
	CUI();
	CUI(std::vector<Solution> &solution_list);
public:
	CUI(CUI& other) = delete; //cannot be cloned 
	void operator=(const CUI&) = delete;
	static CUI* GetInstance(std::vector<Solution> &solution_list);
	int NextCommand(const std::string& command); //TO-DO
};

#endif // !CUI_H