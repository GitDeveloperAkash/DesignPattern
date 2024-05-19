#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

class Singletonconfig
{
private:
	
	string filename;	
	ifstream ifs;
	Singletonconfig(const string& _filename)
	{		
		filename = _filename;
		ifs.open(filename);
		
	}	
	
public :
	string getValOf(const string& _key)
	{
		string line;
		string RetVal;
		/*if(ifs.is_open())
			cout << " file " << filename << " is already opened " << endl;
		else
			cout << " file " << filename << " is not opened " << endl;*/
		while(getline(ifs,line))
		{
			string Key;
			string saperator = ":";
			Key = line.substr(0,line.find(saperator));			
			if(Key == _key)
			{
				RetVal = line.substr(line.find(saperator)+1,line.length());
				break;			
			}				
		}
		ifs.seekg(0, std::ios::beg);
		return RetVal;
	}
	

	static Singletonconfig& getconfig(string& _filename)
	{
		static Singletonconfig instanse(_filename);
		return instanse;
	}
	Singletonconfig(Singletonconfig const&) = delete;
	void operator=(Singletonconfig const&) = delete;
};

int main()
{
	string configFile("Properties.config");
		
	while(1)
	{
		cout << Singletonconfig::getconfig(configFile).getValOf("NAME") << " is " << Singletonconfig::getconfig(configFile).getValOf("AGE") << " years Old" << endl;
		sleep(5);
	}

}