#include "Group.h"

int Group::id = 0;

Group::Group(int id, int groupCount) {
    this->uniqueId = id;
    this->groupCount = groupCount;
    this->students = new Student[groupCount];
}

void Group::show() {
    std::cout << "Group: " << uniqueId << std::endl;
    for (int i = 0; i < groupCount; i++)
        std::cout << students[i].toString();
    std::cout << std::endl;
}
void Group::addStudent(Student& st) {
    Student* buf = new Student[groupCount + 1];
    for (int i = 0; i < groupCount; i++) {
        buf[i] = students[i];
    }
    buf[groupCount++] = st;
    delete[] students;
    students = buf;
}

void Group::removeStudentByIndex(int index) {
    if (index<0 || index>groupCount - 1) return;
    Student* buf = new Student[groupCount - 1];
    for (int i = 0; i < index; i++) {
        buf[i] = students[i];
    }
    for (int i = index + 1; i < groupCount; i++) {
        buf[i - 1] = students[i];
    }
    delete[] students;
    students = buf;
    groupCount--;
}

int Group::getStudentIndexById(int id) {
    for (int i = 0; i < groupCount; i++) {
        if (students[i].getUniqueId() == id)return i;
    }
    return -1;
}

void Group::transferStudentByIndex(int ind, Group& gIn) {
    Student& st = students[ind];
    Student s = st;
    this->removeStudentByIndex(ind);
    gIn.addStudent(s);
}