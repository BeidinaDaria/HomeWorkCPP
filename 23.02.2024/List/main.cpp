#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	List<int> list1, list2;
	list1.push_back(10);
	auto v1 = list1.end();
	cout << (++--v1 == list1.end()) << endl;
	cout << (list2.end() != list1.end()) << endl;
	cout << (list1.end() == list1.end()) << endl;
}

