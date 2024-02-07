#include "School.h"

School::School(int num, int groupCount) {
    this->num = num;
    this->groupCount = groupCount;
    this->groups = new Group[groupCount];
}

void School::show() {
    std::cout << "School: " << num << std::endl;
    for (int i = 0; i < groupCount; i++){
        groups[i].show();
        std::cout << std::endl;
    }
}

int School::getGroupIndexById(int id) {
    for (int i = 0; i < groupCount; i++) {
        if (groups[i].getId() == id) return i;
    }
    return -1;
}

void School::transfer(int numOut, int numIn, int studentId) {
    int gOut = getGroupIndexById(numOut);
    int gIn = getGroupIndexById(numIn);
    if ((gOut == -1) || (gIn == -1)) return;
    int index = groups[gOut].getStudentIndexById(studentId);
    if (index == -1) return;
    groups[gOut].transferStudentByIndex(index, groups[gIn]);
}
