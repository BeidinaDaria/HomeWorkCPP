#pragma once
#include <iostream>
#include <string>

const std::string d[] = {
	"Lorem ipsum dolor sit amet,",
	"consectetur adipiscing elit,",
	"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
	"Ut enim ad minim veniam,",
	"quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
};
int random(int a, int b);

class Record{
	int id;
	static int idCount;
	std::string data;
public:
	Record():id(idCount++),data(d[random(0,4)]) {}
	Record(std::string text) :id(idCount++), data(text) {}
	void show();
	int getId() { return id; }
};

