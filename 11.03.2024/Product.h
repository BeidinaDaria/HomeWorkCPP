#pragma once
#include <iostream>

class Dress {
	std::string type;
public:
	void virtual show() = 0;
};

class StandardDress :public Dress {};

class LatinDress :public Dress {};

class StandardTrainingDress :public StandardDress {
public:
	void show() {
		std::cout << "It's a standard training dress"<< std::endl;
	}
};

class LatinTrainingDress :public LatinDress {
public:
	void show() {
		std::cout << "It's a latin training dress"<< std::endl;
	}
};

class StandardCompetitionDress :public StandardDress {
public:
	void show() {
		std::cout << "It's a standard competition dress" << std::endl;
	}
};

class LatinCompetitionDress :public LatinDress {
public:
	void show() {
		std::cout << "It's a latin competition dress" << std::endl;
	}
};

class Shoes {
	std::string params;
public:
	void virtual show() = 0;
};

class StandardShoes:public Shoes {
public:
	void show() {
		std::cout << "Standard shoes." << std::endl;
	}
};

class LatinShoes:public Shoes {
public:
	void show() {
		std::cout << "Latin shoes." << std::endl;
	}
};