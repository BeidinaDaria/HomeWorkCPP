#pragma once
#include "Crayfish.h"
#include <vector>
class Aquarium
{
	int id;
	int maxCount;
	double price;
	std::vector<Crayfish> crayfishes;
public:
	Aquarium(int id, int maxCount, int price) :id(id), maxCount(maxCount), price(price) {}
	std::vector<std::string> toString();
	int getId() { return id; }
	void addCrayfish(Crayfish c);
	void delCrayfish(int crayId);
	Crayfish getCrayfishById(int crayId = -1);
};