#include <iostream>
using namespace std;

class Interface {
public:
    virtual void get() = 0;
};

class Adaptee: public Interface {
public:
    void get() override {
        cout << "this is adaptee" << endl;
    }
};

class TargetInterface {
public:
    virtual void generate() = 0;
};

class Adapter: public TargetInterface {
private:
    Interface* adaptee;
public:
    Adapter() {
        adaptee = new Adaptee();
    }

    void generate() override {
        adaptee->get();
    }
};

void Client() {
    Adapter* concreteAdapter = new Adapter();
    concreteAdapter->generate();
}

int main() {
    Client();

    return 0;
}