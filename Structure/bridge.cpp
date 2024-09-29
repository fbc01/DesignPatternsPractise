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

class BridgeInterface {
public:
    virtual void generate() = 0;
};

class Bridge: public BridgeInterface {
private:
    unique_ptr<Interface1> object1;
    unique_ptr<Interface2> object2;

public:
    Bridge(unique_ptr<Interface1> object1, unique_ptr<Interface2> object2) {
        this->object1 = move(object1);
        this->object2 = move(object2);
    }

    void generate() override {
        object1->get();
        object2->show();
    }
};

class Concrete1: public Interface1 {
private:
    string id;

public:
    Concrete1(string id) {
        this->id = id;
    }

    void get() override {
        cout << "this is get of " << id << endl;
    }
};

class Concrete2: public Interface2 {
private:
    string id;

public:
    Concrete2(string id) {
        this->id = id;
    }

    void show() override {
        cout << "this is show of " << id << endl;
    }
};

void Client() {
    unique_ptr<BridgeInterface> bridge1 = make_unique<Bridge>(
        make_unique<Concrete1>("A"), 
        make_unique<Concrete2>("C")
    );
        
    unique_ptr<BridgeInterface> bridge2 = make_unique<Bridge>(
        make_unique<Concrete1>("B"), 
        make_unique<Concrete2>("D")
    );
    bridge1->generate();
    bridge2->generate();
}

int main() {
    Client();

    return 0;
}