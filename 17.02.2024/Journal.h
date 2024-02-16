#pragma once
#include "List.h"

class Journal{
	int count=0;
	List* data;
public:
	Journal(int count) { this->count = abs(count); data = new List[count]; }
	void showByIndex(int index);
	void addRecord(int ind, std::string str = d[random(0, 4)]);
	void delRecord(int indPage,int indRec);
	void show();
};

