
#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

// state interface
class StateInterface {
public:
    virtual void handleRequest() = 0;
};


// context interface
class ContextInterface {
public:
    virtual void setState(StateInterface* state) = 0;
    virtual void request() = 0;
};


// concrete states
class StateA: public StateInterface {
public:
    void handleRequest() override {
        cout << "Product currently in State A" << endl;
    }
};

// concrete states
class StateB: public StateInterface {
public:
    void handleRequest() override {
        cout << "Product currently in State B" << endl;
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
        currentState->handleRequest();
    }
};

// client code 
void clientCode () {
    // state management from outside of states
    StateA* stateA = new StateA();
    StateB* stateB = new StateB();

    Context* context = new Context();
    context->setState(stateA);
    context->request();
    context->setState(stateB);
    context->request();

    /*
        Output->

            Product currently in State A
            Product currently in State B
    */
}




int main() {
    
    clientCode();

    return 0;
}

