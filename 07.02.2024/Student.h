#pragma once
#include <string>
#include <iostream>

const std::string names[] = { "Grace","Max","Julie","John","Zoe","Jane","Allen","James" };
int random(int a, int b);

class Student {
    static int id;
    int uniqueId = 0;
    std::string name = "noname";
    int* marks = nullptr;
    int countMarks = 0;
public:
    Student() :name(names[random(0, 8)]), uniqueId(id++), marks(new int[10]), countMarks(random(1, 10)) {
        for (int i = 0; i < countMarks; i++)
            marks[i] = random(2, 5);
    }
    Student(std::string name);
    Student(std::string name, int count);
    Student(Student& st);
    int getUniqueId() { return uniqueId; }
    std::string toString();
    void addMark(int mark);
    void removeMarkByIndex(int index);
    double avMark();
    void changeMark(int index, int mark);
    Student& operator=(Student& st);
    ~Student() {
        if (marks == nullptr) return;
        delete[] marks;
        countMarks = 0;
    }
    void copy(Student& st);
};