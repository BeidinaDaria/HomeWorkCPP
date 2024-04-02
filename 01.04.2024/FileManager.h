#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileManager
{
	std::string path;
public:
	FileManager(std::string p) :path(p) {}
	void setPath(std::string path) {
		this->path = path;
	}
	std::string readFile(int i=0);
	void writeFile(std::string str, int i=-1);
	std::vector<std::string> split(std::string str, char sep);
};



