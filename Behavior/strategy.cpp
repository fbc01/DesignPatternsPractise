#include <iostream>
using namespace std;

class Strategy {
public:
    virtual void get() = 0;
};

class StrategyImpl1: public Strategy {
public:
    void get() override {
        cout << "This is Strategy 1" << endl;
    }
};

class StrategyImpl2: public Strategy {
public:
    void get() override {
        cout << "This is Strategy 2" << endl;
    }
};

class StrategyImpl3: public Strategy {
public:
    void get() override {
        cout << "This is Strategy 3" << endl;
    }
};

class Context {
private:
    Strategy* strategy;
public:
    Context() {}

    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }
    void show() {
        this->strategy->get();
    }
};

void Client() {
    Context* context = new Context();
    context->setStrategy(new StrategyImpl1());
    context->show();
    context->setStrategy(new StrategyImpl2());
    context->show();
    context->setStrategy(new StrategyImpl3());
    context->show();
}

int main() {
    Client();

    return 0;
}

