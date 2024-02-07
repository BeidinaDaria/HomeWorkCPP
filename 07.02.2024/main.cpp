#include "School.h"

int main() {
	srand(time(NULL));
	School s1(random(1,100),10);
	s1.show();

	int out, in, id;
	std::cout << "Enter numbers of groups for output and input of student and the id of the student: ";
	std::cin >> out;
	std::cin >> in;
	std::cin >> id;
	s1.transfer(out, in, id);
	s1.show();
}