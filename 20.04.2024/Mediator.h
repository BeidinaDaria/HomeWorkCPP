#pragma once
#include <iostream>
#include <string>

class BaseComponent;
class Mediator {
public:
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent {
protected:
    Mediator* mediator;

public:
    BaseComponent(Mediator* mediator = nullptr) : mediator(mediator) {}
    void set_mediator(Mediator* mediator) {
        this->mediator = mediator;
    }
};

class Button : public BaseComponent {
public:
    void drop() {
        std::cout << "Button droped.\n";
        this->mediator->Notify(this, "A");
    }
    void click() {
        std::cout << "Button clicked.\n";
        this->mediator->Notify(this, "B");
    }
};

class Textarea : public BaseComponent {
public:
    void choose() {
        std::cout << "Textarea chosen.\n";
        this->mediator->Notify(this, "C");
    }
    void write() {
        std::cout << "Textarea written.\n";
        this->mediator->Notify(this, "D");
    }
};

class ConcreteMediator : public Mediator {
private:
    Button* but;
    Textarea* text;

public:
    ConcreteMediator(Button* c1, Textarea* c2) : but(c1), text(c2) {
        this->but->set_mediator(this);
        this->text->set_mediator(this);
    }
    void Notify(BaseComponent* sender, std::string event) const override {
        if (event == "A") {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->text->choose();
        }
        if (event == "D") {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->but->click();
            this->text->choose();
        }
    }
};