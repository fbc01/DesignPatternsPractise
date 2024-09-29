#include <iostream>
using namespace std;

class Interface {
public:
    virtual void get() = 0;
};

class Concrete1: public Interface {
public:
    void get() override {
        cout << "this is concrete 1" << endl;
    }
};

class Concrete2: public Interface {
public:
    void get() override {
        cout << "this is concrete 2" << endl;
    }
};

class Concrete3: public Interface {
public:
    void get() override {
        cout << "this is concrete 3" << endl;
    }
};

class Facade {
private:
    Concrete1* concrete1;
    Concrete2* concrete2;
    Concrete3* concrete3;

public:
    Facade() {
        concrete1 = new Concrete1();
        concrete2 = new Concrete2();
        concrete3 = new Concrete3();
    }

    void get(int id) {
        switch (id) {
            case 1:
                concrete1->get();
                return;
            case 2:
                concrete2->get();
                return;
            case 3:
                concrete3->get();
                return;
            default:
                cout << "Invalid id" << endl;
                return;
        }
    }
};


void Client() {
    Facade* facade = new Facade();
    facade->get(1);
    facade->get(2);
    facade->get(3);
}

int main() {
    Client();

    return 0;
}