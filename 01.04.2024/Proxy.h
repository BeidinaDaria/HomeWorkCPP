#pragma once
#include "FileManager.h"
#include <stack>

class Str {
	std::string str;
	int num;
public:
	Str():num(-1),str("") {}
	Str(std::string s, int i) :str(s), num(i) {}
	std::string getStr() { return str; }
	int getNum() { return num; }
};

class Proxy
{
	std::stack<Str> buffer;
	const int maxSize = 10;
	FileManager fs;
public:
	Proxy(std::string path) :fs(FileManager(path)) {}
	std::string read(int i);
	void write(std::string s, int j=-1);
};

