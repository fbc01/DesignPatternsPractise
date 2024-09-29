#include <iostream>
#include <vector>
using namespace std;

class CompositeInterface {
public:
    virtual void show() = 0;
};

class Leaf: public CompositeInterface {
public:
    void show() override {
        cout << "This is Leaf" << endl;
    }
};

class CompositeConcrete: public CompositeInterface {
private:
    vector<CompositeInterface*> children;

public:
    CompositeConcrete(vector<CompositeInterface*>& children) {
        this->children = children;
    }

    void show() override {
        cout << "This is Concrete Composite" << endl;
        for (CompositeInterface* &child: children) {
            child->show();
        }
    }
};

void Client() {
    CompositeInterface* leaf1 = new Leaf();
    CompositeInterface* leaf2 = new Leaf();
    CompositeInterface* leaf3 = new Leaf();
    vector<CompositeInterface*> children = {leaf1, leaf2, leaf3};
    CompositeConcrete* node = new CompositeConcrete(children);
    node->show();
}

int main() {
    Client();

    return 0;
}