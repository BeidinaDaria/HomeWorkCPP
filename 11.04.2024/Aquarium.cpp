#include "Aquarium.h"

std::vector<std::string> Aquarium::toString() {
	std::vector<std::string> res;
	res.push_back("Aquarium id: " + std::to_string(id) + ", price: " + std::to_string(price));
	for (auto el : crayfishes) {
		res.push_back(el.toString());
	}
	return res;
}

void Aquarium::addCrayfish(Crayfish c) {
	if (crayfishes.size() + 1 <= maxCount)
		crayfishes.push_back(c);
	else throw std::exception("Aquarium is full");
}

void Aquarium::delCrayfish(int crayId) {
	std::vector<Crayfish> newCrays;
	for (auto el : crayfishes) {
		if (el.getId() != crayId)
			newCrays.push_back(el);
	}
	crayfishes = newCrays;
}

Crayfish Aquarium::getCrayfishById(int crayId) {
	if (crayId == -1) return crayfishes[0];
	for (auto el : crayfishes) {
		if (el.getId() == crayId)
			return el;
	}
}