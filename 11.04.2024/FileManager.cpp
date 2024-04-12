#include "FileManager.h"

std::vector<std::string> FileManager::readFile(std::string path) {
	std::ifstream in(path);
	std::string str;
	std::vector<std::string> arr;
	if (in.is_open()) {
		while (getline(in, str)) {
			arr.push_back(str);
		}
	}
	in.close();
	return arr;
}

void FileManager::writeFile(std::string path, std::vector<std::string> strs) {
	std::ofstream out(path);
	for (auto str : strs) {
		out << str << std::endl;
	}
	out.close();
}

std::vector<std::string> FileManager::split(std::string str, char sep) {
	std::vector<std::string> res;
	while (str.find_first_of(sep)) {
		res.push_back(str.substr(0, str.find_first_of(sep)));
		str.replace(str.begin(), str.begin() + str.find_first_of(sep) + 1, "");
	}
	return res;
}