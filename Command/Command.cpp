#include <iostream>
#include <string>
using namespace std;

enum ACTION
{
	DEPOSIT=0,
	WITHDROW,
	TRANSFER
};

class BankAccount
{
	string name;
	int balance;
public:
	BankAccount(string _name)
	{
		name = _name;
		balance=0;
	}

	bool withdrow(int amount)
	{
		if(balance < amount)
		{
			cout << " unsufficiant balance" << endl;
			return false;
		}
		else
		{
			balance -= amount;
			cout << amount << " rs has withdrow, Total Balance is "<< balance << endl;
			return true;
		}
	}
	bool deposit(int amount)
	{		
		balance += amount;
		cout << amount << " rs has deposited, Total Balance is "<< balance << endl;
			return true;		
	}

};


class command
{

public:
	virtual bool execute() = 0;
};

class UniBankCommand : public command
{
	BankAccount* Ba;
	int ammount;	
	ACTION Action;
public:
	UniBankCommand(BankAccount* ba, ACTION _action, int _ammount)
	{
		Ba = ba;
		Action = _action;
		ammount = _ammount;
	}
	bool execute()
	{
		bool RetVal=false;
		switch(Action)
		{
		case ACTION::DEPOSIT:
				RetVal = Ba->deposit(ammount);
			break;
		
		case ACTION::WITHDROW:
				RetVal =Ba->withdrow(ammount);
			break;
		}

		return RetVal;
	}

};
/*
class MultiBankCommand : public UniBankCommand
{
	UniBankCommand* Bank1;
	UniBankCommand* Bank2;
	ACTION action;
public:

};

*/
int main(int argc, char const *argv[])
{
	BankAccount *ba1;
	ba1 = new BankAccount("AxisAcount");
	
	UniBankCommand cmd1(ba1, ACTION::DEPOSIT, 5000000);
	UniBankCommand cmd2(ba1, ACTION::WITHDROW, 64340);
	cmd1.execute();	
	cmd2.execute();
	

	
	
	
	return 0;
}