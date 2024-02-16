#include "Journal.h"

void Journal::showByIndex(int index) {
	if (index < 0 || index >= count) return;
	data[index].show();
}

void Journal::addRecord(int ind, std::string str) {
	if (ind<0 || ind>=count) return;
	data[ind].addRecord(str);
}
void Journal::delRecord(int indPage, int indRec) {
	if (indPage < 0 || indPage >= count) return;
	data[indPage].delRecord(indRec);
}

void Journal::show() {
	for (int i = 0; i < count; i++) {
		std::cout << "Page: " << i << std::endl;
		data[i].show();
	}
}