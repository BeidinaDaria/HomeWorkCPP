#include "Mediator.h"
#include "Visitor.h"

int main()
{
    Button* c1 = new Button;
    Textarea* c2 = new Textarea;
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);
    std::cout << "Client triggers operation A.\n";
    c1->drop();
    std::cout << "\n";
    std::cout << "Client triggers operation D.\n";
    c2->write();

    std::vector<const Component*> components;
    components.push_back(new Input);
    components.push_back(new Submit);
    std::cout << "The client code works with all visitors via the base Visitor interface:\n";
    ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
    for (const Component* comp : components) {
        comp->accept(visitor1);
    }
    std::cout << "\n";
    std::cout << "It allows the same client code to work with different types of visitors:\n";
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
    for (const Component* comp : components) {
        comp->accept(visitor2);
    }
}