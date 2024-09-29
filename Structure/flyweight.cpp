#include <iostream>
using namespace std;

class FlyweightInterface {
public:
    virtual void get() = 0;
};

class FlyweightConcrete: public FlyweightInterface {
public:
    void get() override {
        cout << "This is flyweight object" << endl;
    }
};

// in java we should have abstract class and flyweight referance in that
class MainClass {
private:
    FlyweightInterface* flyweightObject;
    int uniqueId;

public:
    MainClass(FlyweightInterface* flyweightObject, int uniqueId) {
        this->flyweightObject = flyweightObject;
        this->uniqueId = uniqueId;
    }
    void printId() {
        cout << uniqueId << endl;
    }
    void get() {
        flyweightObject->get();
    }
};

void Client() {
    FlyweightInterface* concreteFlyweight = new FlyweightConcrete();
    MainClass* object1 = new MainClass(concreteFlyweight, 1);
    MainClass* object2 = new MainClass(concreteFlyweight, 2);
    object1->get();
    object1->printId();
    object2->get();
    object2->printId();
}

int main() {
    Client();

    return 0;
}