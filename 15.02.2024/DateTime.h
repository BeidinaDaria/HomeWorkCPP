#pragma once
#include <iostream>
#include <string>
class DateTime{
	int year=1970, month=1, day=1, hour=0, minute=0, sec=0;
public:
	DateTime(std::string str);
	void show();
};

