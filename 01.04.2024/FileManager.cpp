#include "FileManager.h"

std::string FileManager::readFile(int i) {
	std::ifstream in(path);
	std::string str;
	int j = 0;
	if (in.is_open()) {
		while (getline(in, str)&&(j<i)) {
			j++;
		}
	}
	in.close();
	if (i == j) return str;
	return "";
}

void FileManager::writeFile(std::string input, int i) {
	std::vector<std::string> strs;
	std::ifstream in(path);
	std::string str;
	int j = -1;
	if (in.is_open()) {
		while (getline(in, str)) {
			j++;
			if (j == i)
				strs.push_back(input);
			else strs.push_back(str);
		}
	}
	strs.push_back(input); 
	in.close();
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
