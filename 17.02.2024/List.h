#pragma once
#include "Record.h"

class List{
	int count=0;
	Record* data=nullptr;
public:
	List() {
		int c = random(1, 10);
		for (int i = 0; i < c; i++)
			addRecord(d[random(0, 4)]);
	}
	void addRecord(std::string str);
	void delRecord(int id);
	void show();
};

