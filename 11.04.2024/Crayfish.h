#pragma once
#include <iostream>
#include <string>
class Crayfish{
	int id;
	double weight;
public:
	Crayfish(int id, double weight) :id(id), weight(weight) {}
	std::string toString();
	int getId() { return id; }
};