#include "Builder.h"
#include <iostream>

void House::show() {
	std::cout << "House: windows - " << windows << ", doors - " << doors << ", rooms - " << rooms <<
		", garages - " << garages << ", swimming pools - " << swimpools << ", statues - " << statues <<
		", square of garden - " << gardensquare << "." << std::endl;
}