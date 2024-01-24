#include <iostream>

class Car {
private:
    int price;
    std::string color;
    std::string model;
    double capacity;
public:
    Car(int price = 0, std::string color = "red", std::string model = "Audi Quattro", double capacity = 2.2) {
        this->price = (price >= 0) ? price : 0;
        this->color = (color != "") ? color : "red";
        this->model = (model != "") ? model : "Audi Quattro";
        this->capacity = (capacity >= 0) ? capacity : 2.2;
    }

    int getPrice() { return price; }
    std::string getColor() { return color; }
    std::string getModel() { return model; }
    double getCapacity() { return capacity; }

    void setPrice(int price){ this->price = (price >= 0) ? price : 0; }
    void setColor(std::string color) { this->color = (color != "") ? color : "red"; }
    void setModel(std::string model) { this->model = (model != "") ? model : "Audi Quattro"; }
    void setCapacity(int capacity) { this->capacity = (capacity >= 0) ? capacity : 2.2; }

    void show() {
        std::cout << model << " color:" << color << " engine capacity:" 
            << capacity << "l price:" << price << std::endl;
    }
};

int main()
{
    Car c1;
    c1.show();

    Car c2(1500000, "silver", "Audi 80", 1.9);
    c2.setPrice(-300);
    std::cout << c2.getPrice() << std::endl;

    Car c3(1000000, "white", "Audi 90", 2.3);
    c2.setColor("silver");
    std::cout << c2.getColor() << std::endl;

    Car c4(1000000, "grey", "Audi A4", 1.9);
    c2.setCapacity(3);
    std::cout << c2.getCapacity() << std::endl;

    c1.setModel("Audi A5 Sportback");
    std::cout << c1.getModel() << std::endl;
}