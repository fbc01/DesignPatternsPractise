#include <iostream>
using namespace std;

class Interface {
public:
    virtual void get() = 0;
};

class Concrete: public Interface {
public:
    void get() override {
        cout << "this is concrete" << endl;
    }
};

class Decorator: public Interface {
private:
    Interface* delegator;

    void show() {
        cout << "this is decorator" << endl;
    }

public:
    Decorator(Interface* delegator) {
        this->delegator = delegator;
    }

    void get() override {
        // add additional handling in get only
        delegator->get();
        this->show();
    }
};

void Client() {
    Interface* delegator = new Concrete();
    Decorator* concreteDecorator = new Decorator(delegator);
    concreteDecorator->get();
}

int main() {
    Client();

    return 0;
}