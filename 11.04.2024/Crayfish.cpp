#include "Crayfish.h"

std::string Crayfish::toString() {
	return "Id: " + std::to_string(id) + ", weight: " + std::to_string(weight) + "\n";
}