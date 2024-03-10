#pragma once
#include <iostream>
class Database
{
	static Database* instance;
	std::string name;
	Database(std::string name) {
		this->name = name;
	}
public:
	static Database* getInstance(std::string name){
		if (instance == nullptr)
			instance = new Database(name);
		return instance;
	}
	void show() {
		std::cout << name << std::endl;
	}
};

Database* Database::instance = nullptr;