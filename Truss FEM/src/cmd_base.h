#ifndef CMD_BASE_H
#define CMD_BASE_H

class CmdBase
{
protected:
	const char* caller_;

	CmdBase(const char* caller);
public:
	virtual const char* GetCaller() const final;
	virtual void Execute() const = 0;
	virtual ~CmdBase();

	//TOOLS
	virtual std::string GetCommandName() const final;
};


class CmdNoAction : public CmdBase {
public:
	CmdNoAction();
	void Execute() const override;

	~CmdNoAction();
};

class CmdPrinter : public CmdBase {
public:
	CmdPrinter();
	void Execute() const override;

	~CmdPrinter();
};

#endif // !CMD_BASE_H