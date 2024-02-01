#include "Car.h"

int Car::id = 100;

int random(int a, int b) { return a + rand() % (b - a + 1); }

Car::Car(int price, std::string color, std::string model, double capacity) {
    this->price = (price >= 0) ? price : 0;
    this->color = (color != "") ? color : "red";
    this->model = (model != "") ? model : "Audi Quattro";
    this->capacity = (capacity >= 0) ? capacity : 2.2;
    this->uniqueId = this->id++;
}

void Car::show() {
    std::cout << "ID:"<<uniqueId<<"\t"<<model << "\tcolor:" << color << "\tengine capacity:"
        << capacity << "\tprice:" << price << std::endl;
}