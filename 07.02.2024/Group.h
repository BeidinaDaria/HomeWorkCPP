#pragma once
#include "Student.h"

class Group {
    static int id;
    int uniqueId;
    Student* students;
    int groupCount;
public:
    Group() :uniqueId(id++), groupCount(random(1,10)) {
        students = new Student[groupCount];
    }
    Group(int id, int groupCount);
    int getId() { return uniqueId; }
    void show();
    void changeMark(int ind, int index, int mark) {students[ind].changeMark(index, mark);}
    void addStudent(Student& st);
    void removeStudentByIndex(int index);
    ~Group() {
        if (students == nullptr) return;
        delete[] students;
        groupCount = 0;
        students = nullptr;
    }
    void transferStudentByIndex(int ind, Group& g);
    int getStudentIndexById(int id);
};