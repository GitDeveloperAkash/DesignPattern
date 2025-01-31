#include <iostream>

using namespace std;

// 1. Product
class car{
    public:
    string name;
    string color;
    string model;
    int price;
    car(string name, string color, string model, int price){
        this->name = name;
        this->color = color;
        this->model = model;
        this->price = price;
    }
    void show(){
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

// 2. builder
class Carbuilder{
    public:
    virtual string getName() = 0;
    virtual string getColor() = 0;
    virtual string getModel() = 0;
    virtual int getPrice() = 0;
};

// 3. concrete builder
class BMWBuilder : public Carbuilder{
    public:
    string getName(){
        return "BMW";
    }
    string getColor(){
        return "Black";
    }
    string getModel(){
        return "2021";
    }
    int getPrice(){
        return 100000;
    }
};

class HondaBuilder : public Carbuilder{
    public:
    string getName(){
        return "Honda";
    }
    string getColor(){
        return "White";
    }
    string getModel(){
        return "2021";
    }
    int getPrice(){
        return 50000;
    }
};
// 4. Director
class CarDirector{
    private:
    Carbuilder *carBuilder;
    public:
    CarDirector(Carbuilder *carBuilder){
        this->carBuilder = carBuilder;
    }
    car* build(){
        return new car(carBuilder->getName(), carBuilder->getColor(), carBuilder->getModel(), carBuilder->getPrice());
    }
};
int main() {
    
    car c1("BMW", "Black", "2021", 100000); // normal way to create object
    c1.show();
    cout << endl;
    BMWBuilder bmwBuilder;
    CarDirector carDirector(&bmwBuilder);
    car *c2 = carDirector.build(); // using builder pattern to create object    
    c2->show();

    cout << endl;

    HondaBuilder hondaBuilder;
    CarDirector carDirector2(&hondaBuilder);
    car *c3 = carDirector2.build(); // using builder pattern to create object
    c3->show();
    

    return 0;
}