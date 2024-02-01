#include "Garage.h"

int Garage::id = random(1,1000);

Garage::Garage(int count) {
    this->uniqueId = id;
    this->count = count;
    this->cars = new Car[count];
}

void Garage::show() {
    std::cout << "Garage: " << uniqueId << std::endl;
    for (int i = 0; i < count; i++)
        cars[i].show();
    std::cout << std::endl;
}

void Garage::addCar(Car& st) {
    Car* buf = new Car[count + 1];
    for (int i = 0; i < count; i++) {
        buf[i] = cars[i];
    }
    buf[count++] = st;
    delete[] cars;
    cars = buf;
}

void Garage::removeCarByIndex(int index) {
    if (index<0 || index>count - 1) return;
    Car* buf = new Car[count - 1];
    for (int i = 0; i < index; i++) {
        buf[i] = cars[i];
    }
    for (int i = index + 1; i < count; i++) {
        buf[i - 1] = cars[i];
    }
    delete[] cars;
    cars = buf;
    count--;
}

Garage::~Garage() {
    if (cars == nullptr) return;
    delete[] cars;
    count = 0;
    cars = nullptr;
}