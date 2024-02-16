#include "List.h"

void List::addRecord(std::string str) {
	Record* buf = new Record[count + 1];
	for (int i = 0; i < count; i++)
		buf[i] = data[i];
	if (data != nullptr)delete[] data;
	buf[count] = Record(str);
	count++;
	data = new Record[count];
	for (int i = 0; i < count; i++)
		data[i] = buf[i];
}

void List::delRecord(int id) {
	int index = -1;
	for (int i=0;i<count;i++)
		if (data[i].getId() == id) {
			index = i;
			break;
		}
	if (index == -1) return;
	Record* buf = new Record[count - 1];
	for (int i = 0; i < index; i++)
		buf[i] = data[i];
	for (int i = index + 1; i < count; i++)
		buf[i - 1] = data[i];
	count--;
	data = new Record[count];
	for (int i = 0; i < count; i++)
		data[i] = buf[i];
}

void List::show() {
	for (int i = 0; i < count; i++) {
		data[i].show();
	}
}