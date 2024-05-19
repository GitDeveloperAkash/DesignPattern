/**
Open/Closed Principle (OCP): 

Software entities (classes, modules, functions, etc.)
should be open for extension but closed for modification. 

This means that you should be able to extend the behavior
of a class without modifying its source code.

**/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum PaymentType
{
    DEBIT_CARD = 0,
    CREDIT_CARD,
    CASH
};

class Payment
{
public:
	virtual void make_payment(int amount) = 0;
};


class CreditCard : public Payment 
{
public:
	void make_payment(int amount)
	{
		cout << " payment of amount " << amount << " is done by CreditCard" << endl;
	}
};


class DebitCard : public Payment 
{
public:
	void make_payment(int amount)
	{
		cout << " payment of amount " << amount << " is done by DebitCard" << endl;
	}
};

class Cash : public Payment 
{
public:
	void make_payment(int amount)
	{
		cout << " payment of amount " << amount << " is done by Cash" << endl;
	}
};

class PaymentProcessor 
{
	Payment *MyPayment;
public:
	PaymentProcessor(enum PaymentType type)
	{
		switch(type)
		{
		case CREDIT_CARD:
				MyPayment = new CreditCard();
		break;

		case DEBIT_CARD :
				MyPayment = new DebitCard();
		break;

		case CASH :
				MyPayment = new Cash();
		break;
		
		}
	}
	void ProcessPayment(int amount)
	{
		MyPayment->make_payment(amount);
	}
};
int main()
{
	PaymentProcessor pp(CASH);

	pp.ProcessPayment(177);
}