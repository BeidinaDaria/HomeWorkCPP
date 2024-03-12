#pragma once
#include "Product.h"

class Factory {
	std::string name;
public:
	Dress virtual makeDress(std::string prog) = 0;
	Shoes virtual makeShoes() = 0;
};

class StandardFactory:public Factory {
public:
	StandardDress makeDress(std::string prog) {
		if (prog == std::string("Training"))
			return StandardTrainingDress;
		return StandardCompetitionDress;
	}
	StandardShoes makeShoes() {
		return StandardShoes;
	}
};

class LatinFactory :public Factory {
public:
	LatinDress makeDress(std::string prog) {
		if (prog == std::string("Training"))
			return LatinTrainingDress;
		return LatinCompetitionDress;
	}
	LatinShoes makeShoes() {
		return LatinShoes;
	}
};