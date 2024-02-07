#pragma once
#include "Group.h"

class School {
    int num;
    Group* groups;
    int groupCount;
public:
    School() :num(random(1,1000)), groups(nullptr), groupCount(0) {}
    School(int id, int groupCount);
    void show();
    void transfer(int gOut, int gIn, int studentId);
    ~School() {
        if (groups == nullptr) return;
        delete[] groups;
        groupCount = 0;
        groups = nullptr;
    }
    int getGroupIndexById(int id);
};