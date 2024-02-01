#pragma once
#include "Car.h"

class Garage {
    static int id;
    int uniqueId;
    Car* cars;
    int count;
public:
    Garage() :uniqueId(id++), cars(nullptr), count(0) {}
    Garage(int count);
    void show();
    void addCar(Car& st);
    void removeCarByIndex(int index);
    ~Garage();
};