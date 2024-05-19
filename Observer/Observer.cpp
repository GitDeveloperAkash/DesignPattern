#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static string PLAYSTATION	= "PlayStation";
static string FOOTBALL		= "football";
static string COLDDRINK		= "colddrink";


class Person {
    string Name;
    string ItemNeed;
public:
	Person(string _name)
	{
		Name = _name;
	}
	void want_to_buy(string _item)
	{
		ItemNeed = _item;
	}
	string requiredItem()
	{
		return ItemNeed;
	}
	string name()
	{
		return Name;
	}
};

class NotificationManager
{
	vector<Person*> subscribers;
public:
	void NOTIFY(vector<string> itemList)
	{
		for(auto subscriber : subscribers)
		{
			for(auto item : itemList)
			{
				if(item == subscriber->requiredItem())
					cout << item << " is available for " << subscriber->name() << endl;
			}
		}	
	}
	void add_subscription(Person& newPerson)
	{
		auto it = std::find(subscribers.begin(), subscribers.end(), &newPerson);
		if(it == subscribers.end())
			subscribers.push_back(&newPerson);
	}
	void remove_subscription(Person& OldPerson)
	{
		auto it = std::find(subscribers.begin(), subscribers.end(), &OldPerson);
		subscribers.erase(it);
	}
	void display_subscribers()
	{
		for(auto sub : subscribers)
			cout << sub->name() << endl;
	}
};

class Store : public NotificationManager
{
	vector<string> availableItems;
public:
	void add_item_in_Store(string _item)
	{
		availableItems.push_back(_item);
		NOTIFY(availableItems);
	}
	void display_all_items()
	{
		for(auto item : availableItems)
		{
			cout << item << endl;
		}
	}

};



int main(int argc, char const *argv[])
{
	Store MarketStore;
	Person Person1("Aakash");

	Person1.want_to_buy(PLAYSTATION);
	MarketStore.add_subscription(Person1);
	//MarketStore.remove_subscription(Person1);
	MarketStore.add_item_in_Store(PLAYSTATION);
	//MarketStore.add_item_in_Store(FOOTBALL);
	//MarketStore.display_all_items();
	
	return 0;
}