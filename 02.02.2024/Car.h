#pragma once
#include <string>
#include <iostream>

const std::string models[] = { "Lada","Audi","Aston Martin","Volkswagen","Mercedes","Toyota","Kia","BMW","Porshe","Ferrari"};
const std::string colors[] = { "red","blue","silver","white","purple","green","black","violet","brown","creme","peach"};
int random(int a, int b);

class Car {
private:
    int uniqueId;
    static int id;
    int price;
    std::string color;
    std::string model;
    float capacity;
public:
    Car(int price, std::string color, std::string model, double capacity);
    Car() :model(models[random(0, 9)]), uniqueId(id++), price(random(500000,2500000)), 
        color(colors[random(0, 9)]),capacity((float)random(10,50)/10) {}

    int getPrice() { return price; }
    std::string getColor() { return color; }
    std::string getModel() { return model; }
    float getCapacity() { return capacity; }

    void setPrice(int price) { this->price = (price >= 0) ? price : 0; }
    void setColor(std::string color) { this->color = (color != "") ? color : "red"; }
    void setModel(std::string model) { this->model = (model != "") ? model : "Audi Quattro"; }
    void setCapacity(int capacity) { this->capacity = (capacity >= 0) ? capacity : 2.2; }

    void show();
};