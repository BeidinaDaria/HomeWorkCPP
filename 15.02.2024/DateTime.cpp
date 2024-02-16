#include "DateTime.h"

DateTime::DateTime(std::string str) {
	if (str.empty()) return;
	year = stoi(str.substr(0, str.find('-')));
	str.replace(0, str.find('-')+1, "");
	month = stoi(str.substr(0, str.find('-')));
	str.replace(0, str.find('-')+1, "");
	day = stoi(str.substr(0, str.find('T')));
	str.replace(0, str.find('T')+1, "");
	hour = stoi(str.substr(0, str.find(':')));
	str.replace(0, str.find(':') + 1, "");
	minute = stoi(str.substr(0, str.find(':')));
	str.replace(0, str.find(':') + 1, "");
	sec = stoi(str.substr(0, str.find('.')));
	str.replace(0, str.find('.') + 1, "");
}

void DateTime::show() {
	std::cout << day << '.' << month << '.' << year << ' ' << hour << ':' << minute << ':' << sec << std::endl;
}