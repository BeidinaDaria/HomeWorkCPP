#pragma once
#include <iostream>
#include <vector>

class Input;
class Submit;

class Visitor {
public:
    virtual void visitConcreteInput(const Input* element) const = 0;
    virtual void visitConcreteSubmit(const Submit* element) const = 0;
};

class Component {
public:
    virtual ~Component() {}
    virtual void accept(Visitor* visitor) const = 0;
};

class Input : public Component {
public:
    void accept(Visitor* visitor) const override {
        visitor->visitConcreteInput(this);
    }
    std::string exclusiveMethodOfConcreteInput() const {
        return "Input";
    }
};

class Submit : public Component {
public:
    void accept(Visitor* visitor) const override {
        visitor->visitConcreteSubmit(this);
    }
    std::string specialMethodOfConcreteSubmit() const {
        return "Submit";
    }
};

class ConcreteVisitor1 : public Visitor {
public:
    void visitConcreteInput(const Input* element) const override {
        std::cout << element->exclusiveMethodOfConcreteInput() << " + ConcreteVisitor1\n";
    }

    void visitConcreteSubmit(const Submit* element) const override {
        std::cout << element->specialMethodOfConcreteSubmit() << " + ConcreteVisitor1\n";
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void visitConcreteInput(const Input* element) const override {
        std::cout << element->exclusiveMethodOfConcreteInput() << " + ConcreteVisitor2\n";
    }
    void visitConcreteSubmit(const Submit* element) const override {
        std::cout << element->specialMethodOfConcreteSubmit() << " + ConcreteVisitor2\n";
    }
};