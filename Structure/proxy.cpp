#include <iostream>
using namespace std;

class Interface {
public:
    virtual void get() = 0;
};

class RealObject: public Interface {
public:
    void get() override {
        cout << "Real Object" << endl;
    }
};

/*
class ProxyObject: public Interface {
private:
    RealObject* realObject;

public:
    ProxyObject() {
        this->realObject = new RealObject();
    }

    void get() override {
        realObject->get();
    }
};
*/
class ProxyObject: public Interface {
private:
    unique_ptr<RealObject> realObject;

public:
    ProxyObject() {
        realObject = make_unique<RealObject>();
    }

    void get() override {
        realObject->get();
    }
};

void Client() {
    ProxyObject* proxy = new ProxyObject();
    proxy->get();
    proxy->get();
}

int main() {
    Client();

    return 0;
}