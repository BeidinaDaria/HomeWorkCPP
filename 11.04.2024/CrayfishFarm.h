#pragma once
#include "Aquarium.h"
#include "FileManager.h"
class CrayfishFarm
{
	std::vector<Aquarium> aquariums;
public:
	CrayfishFarm();
	void update();
	void save();
	void transfer(int outIndex, int inIndex, int id = -1);
};