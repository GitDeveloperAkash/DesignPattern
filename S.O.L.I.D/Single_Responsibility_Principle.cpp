/**
 Single Responsibility Principle (SRP):
 
 A class should have only one reason to change,
 meaning it should have only one responsibility 
 or job within the system. 
 
 This principle encourages developers
 to keep classes focused and cohesive.
**/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

class book
{
  string name;
  string author;  
  int pages;
  vector<string> entry;

public:
  string intro;
  book(string _name,  string _author, int _pages)
  {
    name = _name;
    author = _author;
    pages = _pages;
    intro = " The book " + name + " is written by " + author + " and it has " + to_string(pages) + " pages ";
  }
  bool addEntry(string _entry)
  {
    entry.push_back(_entry);

    return true;
  }
  string get_book_name() 
  {
    return name;
  }
  
  void display()
  {
    
    cout << intro << endl;
    for(auto line : entry)
    {
      cout << line << endl;
    }

    cout << "================= END ===============" << endl;
  }
  vector<string> get_data()
  {
    return entry;
  }
};
// shelf class follow single responsibility principle
// because it has single independently responsibility to save the books as same as shelf keeps the all types of books only
class shelf
{
public:  
 
  shelf()
  {    
    
  }

  bool add_in_shelf(class book new_book)
  {
    ofstream output;
    output.open(new_book.get_book_name(),fstream::out);      
    if(!output.is_open())
    {
      cout << "error in opening file name : " << new_book.get_book_name() << endl;
      return false;
    }
    output<< new_book.intro << endl;
    for(auto line : new_book.get_data())
    {
      output << line << endl; 
    }
    output.close();
    return true;
  }
  bool show_content(class book new_book)
  {
    ifstream input;
    input.open(new_book.get_book_name());
    if(!input.is_open())
    {
      cout << "error in opening file name : " << new_book.get_book_name() << endl;
      return false;
    }
    string line;
    while(getline(input, line))
    {
      cout << line << endl;
    }
    input.close();
    return true;
  }

};
int main()
{
  book first_book("Design Pettern", "Aakash", 70);

  first_book.addEntry("i am the authour for the book");
  first_book.addEntry("i start learning design pattern");
  first_book.addEntry("let see where it goes");

  book second_book("Design Pettern2", "Binny", 80);

  second_book.addEntry("i am the authour for the book also");
  second_book.addEntry("i am learning quickly");
  second_book.addEntry("it is going very well");

  shelf MyShelf;
  MyShelf.add_in_shelf(first_book);
  MyShelf.add_in_shelf(second_book);
  
  MyShelf.show_content(first_book);
  MyShelf.show_content(second_book);

  cout << "working " << endl; 
}
