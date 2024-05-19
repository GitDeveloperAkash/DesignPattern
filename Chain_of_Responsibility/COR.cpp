#include<iostream>
#include <string>
using namespace std;


class Client
{
	string userName;
	string userPassword;

	string dbName;
	string dbPassword;

	string subscriberName;

public:
	string get_userName(){
		return userName;
	}
	string get_userPassword(){
		return userPassword;
	}
	string get_dbName(){
		return dbName;
	}
	string get_dbPassword(){
		return dbPassword;
	}
	string get_subscriberName(){
		return subscriberName;
	}

	void set_userName(string _username){
		userName = _username;
	}
	void set_userPassword(string _userPassword){
		userPassword = _userPassword;
	}
	void set_dbName(string _dbName){
		dbName = _dbName;
	}
	void set_dbPassword(string _dbPassword){
		dbPassword = _dbPassword;
	}
	void set_subscriberName(string _subscriberName){
		subscriberName = _subscriberName;
	}
};

class Validation
{

protected:	
	Validation* _Validation;
public:
	
	virtual string HandleRequest(Client _client) = 0;	
	void set_Chain(Validation* _validation)
	{
		_Validation = _validation;
	}

};

class UserValidation : public Validation
{
public:
	string HandleRequest(Client _client)
	{		
		//cout << "UserValidation::HandleRequest userName " << _client.get_userName() << ", serPassword " << _client.get_userPassword() << endl;
		if(_client.get_userName() == "av6540" && _client.get_userPassword() == "Qaz@123")
			return _Validation->HandleRequest(_client);
		else
			return "User Validation failed";	
	}
};

class DBValidation : public Validation
{
	string HandleRequest(Client _client)
	{		
		//cout << "DBValidation::HandleRequest DBName " << _client.get_dbName() << ", DbPass " << _client.get_dbPassword() << endl;
		if(_client.get_dbName() == "lnpdb" && _client.get_dbPassword() == "Qwe@123")
			return _Validation->HandleRequest(_client);
		else
			return "DB Validation failed";
	}
};

class SubscriberValidation : public Validation
{
	string HandleRequest(Client _client)
	{		
		//cout << "SubscriberValidation::HandleRequest subscriberName " << _client.get_subscriberName() << endl;
		if(_client.get_subscriberName() == "DBuser_av6540" )
			return "All Validation Completed";
		else
			return "Subscriber Validation Failed";
	}
};

class ValidationHandler
{
	Validation* _UserValidation;
	Validation* _DBValidation;
	Validation* _SubscriberValidation;
	
public:
	ValidationHandler()
	{	

		_UserValidation = new UserValidation;
		_DBValidation = new DBValidation;
		_SubscriberValidation = new SubscriberValidation;

		_UserValidation->set_Chain(_DBValidation);
		_DBValidation->set_Chain(_SubscriberValidation);
	}
	string HandleRequest(Client _client)
	{
		return _UserValidation->HandleRequest(_client);
	}
};


int main(int argc, char const *argv[])
{
	Client C1;

	C1.set_userName("av6540");
	C1.set_userPassword("Qaz@123");
	C1.set_dbName("lnpdb");
	C1.set_dbPassword("Qwe@123");
	C1.set_subscriberName("DBuser_av6540");

	ValidationHandler _validator;

	string result = _validator.HandleRequest(C1);

	cout << result << endl;

	return 0;
}