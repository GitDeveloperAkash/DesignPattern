#include <iostream>

using namespace std;

typedef class person
{
public:
	string name;
	int age;
	int  weight;
	
	person(string _name, int _age, int _weight)
	{
		name = _name;
		age = _age;
		weight = _weight;
	}
}Person;

typedef class USperson
{
public:
	string name;
	int age;
	int  weight;
	
	USperson(string _name, int _age, int _weight)
	{
		name = _name;
		age = _age;
		weight = _weight;
	}
}USPerson;

int pound_to_Kg(int weight)
{
	return weight *0.453592;
}

void showAge(int weight)
{
	cout << "this person has " << weight << " kg of weight" << endl;
}
int main()
{
	Person Aakash("Aakash",28,65);
	USPerson Denial("Denial",28,80);
	showAge(Aakash.weight);
	showAge(pound_to_Kg(Denial.weight));
	
	return 0;
}