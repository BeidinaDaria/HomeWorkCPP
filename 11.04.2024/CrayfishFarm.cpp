#include "CrayfishFarm.h"
CrayfishFarm::CrayfishFarm() {
	std::vector<std::string> strs = FileManager::readFile("price.csv");
	std::vector<std::string> sp, crs;
	int i = 0;
	for (std::string str : strs) {
		sp = FileManager::split(str, ';');
		aquariums.push_back(Aquarium(std::stoi(sp[0]), std::stoi(sp[1]), std::stoi(sp[2])));
		crs = FileManager::readFile(sp[0] + ".csv");
		for (std::string s : crs) {
			sp = FileManager::split(s, ';');
			aquariums[i].addCrayfish(Crayfish(std::stoi(sp[0]), std::stod(sp[1])));
		}
		i++;
	}
}

void CrayfishFarm::update() {
	aquariums.clear();
	std::vector<std::string> strs = FileManager::readFile("price.csv");
	std::vector<std::string> sp, crs;
	int i = 0;
	for (std::string str : strs) {
		sp = FileManager::split(str, ';');
		aquariums.push_back(Aquarium(std::stoi(sp[0]), std::stoi(sp[1]), std::stoi(sp[2])));
		crs = FileManager::readFile(sp[0] + ".csv");
		for (std::string s : crs) {
			sp = FileManager::split(s, ';');
			aquariums[i].addCrayfish(Crayfish(std::stoi(sp[0]), std::stod(sp[1])));
		}
		i++;
	}
}

void CrayfishFarm::save() {
	std::vector<std::string> strs;
	std::vector<std::string> sp, crs;
	for (Aquarium aq : aquariums) {
		sp=aq.toString();
		strs.push_back(sp[0]);
		crs.clear();
		for (int i = 1; i < sp.size(); i++) {
			crs.push_back(sp[i]);
		}
		FileManager::writeFile(std::to_string(aq.getId()) + ".csv", crs);
	}
	FileManager::writeFile("price.csv", strs);
}

void CrayfishFarm::transfer(int outIndex, int inIndex, int id) {
	Crayfish c = aquariums[outIndex].getCrayfishById(id);
	aquariums[outIndex].delCrayfish(c.getId());
	aquariums[inIndex].addCrayfish(c);
}