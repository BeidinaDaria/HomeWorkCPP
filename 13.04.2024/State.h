#include <iostream>

class State {
public:
    virtual void getState() = 0;
};

class Create : public State {
public:
    void getState() override {
        std::cout << "Created" << std::endl;
    }
};

class Ready : public State {
public:
    void getState() override {
        std::cout << "Ready" << std::endl;
    }
};

class Launch : public State {
public:
    void getState() override {
        std::cout << "Launching" << std::endl;
    }
};

class Expectation : public State {
public:
    void getState() override {
        std::cout << "Expecting" << std::endl;
    }
};

class Finish : public State {
public:
    void getState() override {
        std::cout << "Finished" << std::endl;
    }
};