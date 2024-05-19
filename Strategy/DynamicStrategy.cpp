#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <memory>
using namespace std;

/** Json Formate
{
	"name": "Aakash",
	"age": 28,
	"city": "Modinagar",  
},

xml formate
<name>Aakash</name>
<age>28</age>
<city>Modinagar</city>

**/

enum DataType
{
	xml=0,
	json
};

class Data
{
protected:
	map<string, string> datalist;
public:
	virtual void insert_list(map<string, string> _datalist)
	{
		for(auto pair : _datalist)
		{
			datalist[pair.first] = pair.second;
		}
	}
	virtual  string get_list() = 0;
};

class xmlData : public Data
{
public:
	string get_list()
	{
		ostringstream Oss;

		for(auto pair : datalist)
		{
			Oss << createStartTag(pair.first);
			Oss << pair.second;
			Oss << createEndTag(pair.first) << endl;
		}

		return Oss.str();
	}
	string createStartTag(string val)
	{
		return "<"+val+">";
	}	
	string createEndTag(string val)
	{
		return "</"+val+">";
	}

};

class jsonData : public Data
{
public:
	string get_list()
	{
		ostringstream Oss;

		Oss << createStartTag();
		for(auto pair : datalist)
		{
			Oss << "    " << "\"" << pair.first << "\"" << " : " << "\"" << pair.second << "\"" << endl;
		}
		Oss << createEndTag();
		return Oss.str();
	}
	string createStartTag()
	{
		ostringstream oss;
		oss  << "{" << endl;
		return oss.str();
	}	
	string createEndTag()
	{
		ostringstream oss;
		oss  << endl << "}";
		return oss.str();
	}
};

class FormateProcessor
{
	unique_ptr<Data> dataStrategy;	

public:
	void FormateType(DataType _dataType)
	{		
		switch(_dataType)
		{
		case DataType::xml :
					dataStrategy = make_unique<xmlData>();
			break;

		case DataType::json :
					dataStrategy = make_unique<jsonData>();
			break;
		}
	}
	void appendList(map<string, string> _datalist)
	{
		dataStrategy->insert_list(_datalist);
	}
	void showList()
	{
		cout << dataStrategy->get_list() << endl;
	}
};

int main(int argc, char const *argv[])
{
	map<string, string> Mylist{
								{"name", "Aakash"}, 
								{"age", "28"}, 
								{"city", "Modinagar"}
							  };

	FormateProcessor Fp;
	Fp.

	Fp.FormateType(xml);
	Fp.appendList(Mylist);
	Fp.showList();

	Fp.FormateType(json);
	Fp.appendList(Mylist);
	Fp.showList();


	return 0;
}