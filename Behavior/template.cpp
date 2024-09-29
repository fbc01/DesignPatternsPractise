#include <iostream>
using namespace std;

class Template {
public:
    void step1() {
        cout << "This is ";
    }
    virtual void step2() = 0;
    void step3() {
        cout << ". And This is ";
    }
    virtual void step4() = 0;
    void algorithm() {
        step1();
        step2();
        step3();
        step4();
    }
};

class Impl1: public Template {
public:
    void step2() override {
        cout << "Impl1";
    }
    void step4() override {
        cout << "Impl1 obj." << endl;
    }
};

class Impl2: public Template {
public:
    void step2() override {
        cout << "Impl2";
    }
    void step4() override {
        cout << "Impl2 obj." << endl;
    }
};

void Client() {
    Template* impl1 = new Impl1();
    Template* impl2 = new Impl2();
    impl1->algorithm();
    impl2->algorithm();
}

int main() {
    Client();

    return 0;
}

