/** 
Interface Segregation Principle (ISP): 

Clients should not be forced to depend on interfaces they do not use. 

This principle advocates for breaking down large interfaces into smaller, 
more specific ones, tailored to the needs of the clients.


**/

#include <iostream>
using namespace std;

/* this is wrong
class Machine
{
public :
	virtual void print() = 0;
	virtual void scan() = 0;
	virtual void fax() = 0;
}
*/

class Printer
{
public:
	virtual void print() = 0;
};

class Faxer
{
public:
	virtual void fax() = 0;
};

class Scaner
{
public:
	virtual void scan() = 0;
};

class Normalprinter : Printer
{
public:
	void print()
	{
		cout << " Data is Printing " << endl;
	}
};

class Advanceprinter : Printer, Faxer, Scaner 	
{
public:
	void print()
	{
		cout << " Data is Printing " << endl;
	}
	void fax()
	{
		cout << " Data is faxing " << endl;
	}
	void scan()
	{
		cout << " Data is Scaning " << endl;
	}
};

int main(int argc, char const *argv[])
{
	Normalprinter _printer;
	_printer.print();	

	Advanceprinter _AP;
	_AP.print();
	_AP.scan();
	_AP.fax();
	return 0;
}