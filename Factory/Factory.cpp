#include <iostream>
#include <string>
using namespace std;




class Car
{
public:
	virtual void make_tyres() = 0;
	virtual void make_body() = 0;
};

class swift : public Car
{
public:
	swift()
	{
		make_tyres();
		make_body();
		cout << " swift is build with default version" << endl;
	}
	void make_tyres()
	{
		cout << " swift's tyre created with 19 inches " << endl;
	}

	void make_body()
	{
		cout << " swift's body created with steel " << endl;
	}

};

class verna : public Car
{
public:
	verna()
	{
		make_tyres();
		make_body();
		cout << " verna is build with default version" << endl;
	}
	void make_tyres()
	{
		cout << " Verna's tyre created with 20 inches " << endl;
	}

	void make_body()
	{
		cout << " Verna's body created with steel " << endl;
	}
};

class honda_city : public Car
{
public:
	honda_city()
	{
		make_tyres();
		make_body();
		cout << " honda_city is build with default version" << endl;
	}
	void make_tyres()
	{
		cout << " honda_city's tyre created with 22 inches " << endl;
	}

	void make_body()
	{
		cout << " honda_city's body created with steel " << endl;
	}
};

typedef enum CarType
{
	SWIFT=0,
	VERNA,
	HONDA_CITY
}CarType;

typedef enum BikeType
{
	Apache=0,
	BMW
}BikeType;


class carFactory 
{
	 Car* make_swift()
	{
		Car* __car;
		__car =  new swift();
		return __car;
	}
	 Car* make_verna()
	{
		return new verna();
	}
	Car* make_hondaCity()
	{
		return new honda_city();
	}
public:
	Car* make_car(CarType _car)
	{		
		Car* TempCar;
		if(_car == SWIFT)
			TempCar =  make_swift();
		else if (_car == VERNA)
			TempCar = make_verna(); 
		else if (_car == HONDA_CITY)
			TempCar = make_hondaCity(); 
		return TempCar;
	}
	
};




int main(int argc, char const *argv[])
{

	// auto swift = Factory::make_car(SWIFT);
	// auto Verna = Factory::make_car(VERNA);
	// auto HondaCity = Factory::make_car(HONDA_CITY);
	carFactory _cf;

	_cf.make_car(SWIFT);
	_cf.make_car(VERNA);
	
	return 0;
}
