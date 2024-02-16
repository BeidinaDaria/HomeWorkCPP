#include "Record.h"

int Record::idCount = 0;

void Record::show() {
	std::cout << id << std::endl;
	std::cout << data << std::endl << std::endl;
}
int random(int a, int b) { return a + rand() % (b - a + 1); }