#include "Student.h"

int random(int a, int b) { return a + rand() % (b - a + 1); }
int Student::id = 0;

Student::Student(std::string name) {
    this->uniqueId = this->id++;
    this->name = name;
    countMarks = rand() % 10 + 1;
    marks = new int[countMarks];
    for (int i = 0; i < countMarks; i++) {
        marks[i] = rand() % 5 + 1;
    }
}

Student::Student(std::string name, int count) {
    this->uniqueId = this->id++;
    this->name = name;
    countMarks = (count < 0) ? 0 : count;
    if (count > 1) {
        marks = new int[count];
        srand(time(NULL));
        for (int i = 0; i < countMarks; i++) {
            marks[i] = rand() % 5 + 1;
        }
    }
}

Student::Student(Student& st) {
    this->uniqueId = st.uniqueId;
    this->name = st.name;
    countMarks = (st.countMarks < 0) ? 0 : st.countMarks;
    if (countMarks >= 1) {
        marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++) {
            marks[i] = st.marks[i];
        }
    }
}

std::string Student::toString() {
    std::string marks = "";
    for (int i = 0; i < countMarks; i++) {
        marks += std::to_string(this->marks[i]) + ", ";
    }
    return "id:" + std::to_string(uniqueId) + ", name:" + name + ", marks:" + marks + "\n";
}

void Student::addMark(int mark) {
    if (mark > 1 && mark < 6) {
        int* buf = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++) {
            buf[i] = marks[i];
        }
        buf[countMarks++] = mark;
        delete[] marks;
        marks = buf;
    }
}

void Student::removeMarkByIndex(int index) {
    if (index<0 || index>countMarks - 1) return;
    int* buf = new int[countMarks - 1];
    for (int i = 0; i < index; i++) {
        buf[i] = marks[i];
    }
    for (int i = index + 1; i < countMarks; i++) {
        buf[i - 1] = marks[i];
    }
    delete[] marks;
    marks = buf;
    countMarks--;
}

double Student::avMark() {
    int sum = 0;
    for (int i = 0; i < countMarks; i++) {
        sum += marks[i];
    }
    return (double)sum / countMarks;
}

void Student::changeMark(int index, int mark) {
    if (index<0 || index>countMarks)return;
    marks[index] = mark;
}

Student& Student::operator=(Student& st) {
    this->uniqueId = st.uniqueId;
    this->name = st.name;
    countMarks = (st.countMarks < 0) ? 0 : st.countMarks;
    if (countMarks >= 1) {
        marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++) {
            marks[i] = st.marks[i];
        }
    }
    return *this;
}

void Student::copy(Student& st) {
    st.uniqueId = this->uniqueId;
    st.name = this->name;
    st.countMarks = (this->countMarks < 0) ? 0 : this->countMarks;
    if (st.countMarks >= 1) {
        st.marks = new int[st.countMarks];
        for (int i = 0; i < st.countMarks; i++) {
            st.marks[i] = this->marks[i];
        }
    }
}