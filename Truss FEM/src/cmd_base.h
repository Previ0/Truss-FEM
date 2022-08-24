#ifndef CMD_BASE_H
#define CMD_BASE_H

#include <string>

class CmdBase
{
protected:
	const char* caller_;

	CmdBase(const char* caller);
public:
	virtual const char* GetCaller() const final;
	virtual void Execute() const = 0;
	virtual ~CmdBase();
	/*TO-DO*/ virtual void Reset() const = 0;


	/*TO-DO*/ virtual void PushOption(const std::string& option);
	/*TO-DO*/ virtual void PushStringArg(const std::string& str_arg);
	/*TO-DO*/ virtual void PushFloatArg(double d_arg);
	/*TO-DO*/ virtual void PushIntArg(int i_arg);

	//TOOLS
	virtual const char* GetCommandName() const final;
};

class CmdNoAction : public CmdBase {
public:
	CmdNoAction();
	void Execute() const override;
	void Reset() const override;

	~CmdNoAction();
};

class CmdPrinter : public CmdBase {
public:
	CmdPrinter();
	void Execute() const override;
	void Reset() const override;

	~CmdPrinter();
};

#endif // !CMD_BASE_H