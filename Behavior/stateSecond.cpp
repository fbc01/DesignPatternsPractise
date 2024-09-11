
#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

class ContextInterface;
class StateInterface;
class StateA;
class StateB;
class StateC;

// state interface
class StateInterface {
public:
    virtual void handleRequest(ContextInterface* context) = 0;
};


// context interface
class ContextInterface {
public:
    virtual void setState(StateInterface* state) = 0;
    virtual void request() = 0;
};

// concrete states
class StateC: public StateInterface {
public:
    void handleRequest(ContextInterface* context) override {
        cout << "Product currently in State C no more transition" << endl;
    }
};

// concrete states
class StateB: public StateInterface {
public:
    void handleRequest(ContextInterface* context) override {
        cout << "Product currently in State B changing to State C" << endl;
        StateC* stateC = new StateC();
        context->setState(stateC);
    }
};

// concrete states
class StateA: public StateInterface {
public:
    void handleRequest(ContextInterface* context) override {
        cout << "Product currently in State A changing to State B" << endl;
        StateB* stateB = new StateB();
        context->setState(stateB);
    }
};


// context
class Context: public ContextInterface {
private:
    StateInterface* currentState;

public:
    void setState(StateInterface* state) override {
        currentState = state;
    }

    void request() override {
        currentState->handleRequest(this);
    }
};

// client code 
void clientCode () {
    // state management from inside of states
    StateA* stateA = new StateA();

    Context* context = new Context();
    context->setState(stateA);
    context->request();
    context->request();
    context->request();
    context->request();

    /*
        Output ->
            Product currently in State A changing to State B
            Product currently in State B changing to State C
            Product currently in State C no more transition
            Product currently in State C no more transition
    */
}




int main() {
    
    clientCode();

    return 0;
}

