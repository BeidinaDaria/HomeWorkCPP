#include "Product.h"
#include <iostream>

void Product::show() {
	std::cout << category << " " << name << " " << price << "p." << std::endl;
}