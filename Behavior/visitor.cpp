#include <iostream>
using namespace std;

class Item;
class Item1;
class Item2;
class Visitor;

class Item {
public:
    virtual int accept(Visitor* visitor) = 0;
};

class Visitor {
public:
    virtual int visit(Item1* item) = 0; 
    virtual int visit(Item2* item) = 0; 
};

class Item1: public Item {
public:
    int accept(Visitor* visitor) override {
        return visitor->visit(this);
    }
};

class Item2: public Item {
public:
    int accept(Visitor* visitor) override {
        return visitor->visit(this);
    }
};

class VisitorImpl: public Visitor {
public:
    int visit(Item1* item) {
        return 1;
    }
    int visit(Item2* item) {
        return 2;
    }
};

void Client() {
    Visitor* visitor = new VisitorImpl();
    Item* item1 = new Item1();
    Item* item2 = new Item2();
    cout << item1->accept(visitor) << endl;
    cout << item2->accept(visitor) << endl;
}

int main() {
    Client();

    return 0;
}



