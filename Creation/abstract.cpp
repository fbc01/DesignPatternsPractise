// abstract factory
#include <iostream>
using namespace std;

class Interface1 {
public:
    virtual void get() = 0;
};

class Interface2 {
public:
    virtual void show() = 0;
};

class AbstractFactory {
public:
    virtual Interface1* createInterface1() = 0;
    virtual Interface2* createInterface2() = 0;
};

class Concrete1: public Interface1 {
public:
    void get() override {
        cout << "This is Concrete1" << endl;
    }
};

class Concrete2: public Interface1 {
public:
    void get() override {
        cout << "This is Concrete2" << endl;
    }
};

class Concrete3: public Interface2 {
public:
    void show() override {
        cout << "This is Concrete3" << endl;
    }
};

class Concrete4: public Interface2 {
public:
    void show() override {
        cout << "This is Concrete4" << endl;
    }
};

class ConcreteAbstract1: public AbstractFactory {
public:
    Interface1* createInterface1() override {
        return new Concrete1();
    }

    Interface2* createInterface2() override {
        return new Concrete4();
    }
};

class ConcreteAbstract2: public AbstractFactory {
public:
    Interface1* createInterface1() override {
        return new Concrete2();
    }

    Interface2* createInterface2() override {
        return new Concrete3();
    }
};

void Client() {
    AbstractFactory* concreteAbstract1 = new ConcreteAbstract1();
    Interface1* object1 = concreteAbstract1->createInterface1();
    Interface2* object2 = concreteAbstract1->createInterface2();
    object1->get();
    object2->show();

    AbstractFactory* concreteAbstract2 = new ConcreteAbstract2();
    object1 = concreteAbstract2->createInterface1();
    object2 = concreteAbstract2->createInterface2();
    object1->get();
    object2->show();
}

int main() {
    Client();

    return 0;
}

