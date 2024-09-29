#include<iostream>
using namespace std;

class Locker {
private:
    int val;
public:
    Locker() {
        val = 1;
    }
    int getVal() {
        return val;
    }
    void setVal(int x) {
        val = x;
    }
};

class Command {
public:
    virtual void execute() = 0;
    virtual void reverseExecute() = 0;
};

class AddToItself: public Command {
private:
    Locker* locker;

public:
    AddToItself(Locker* locker) {
        this->locker = locker;
    }

    void execute() {
        int val = locker->getVal();
        val *= 2;
        locker->setVal(val);
    }
    void reverseExecute() {
        int val = locker->getVal();
        val /= 2;
        locker->setVal(val);
    }
};

class MultiplyToItself: public Command {
private:
    Locker* locker;

public:
    MultiplyToItself(Locker* locker) {
        this->locker = locker;
    }

    void execute() {
        int val = locker->getVal();
        val *= val;
        locker->setVal(val);
    }
    void reverseExecute() {
        int val = locker->getVal();
        val = (int)sqrt(val);
        locker->setVal(val);
    }
};

void Client() {
    Locker* locker = new Locker();
    Command* addToItselfCommand = new AddToItself(locker);
    Command* multiplyToItselfCommand = new MultiplyToItself(locker);
    vector<Command*> listOfCommands;
    
    listOfCommands.push_back(addToItselfCommand);
    listOfCommands.push_back(multiplyToItselfCommand);
    listOfCommands.push_back(addToItselfCommand);
    listOfCommands.push_back(multiplyToItselfCommand);

    for (int i=0; i<4; i++) {
        listOfCommands[i]->execute();
        cout << locker->getVal() << endl;
    }

    for (int i=3; i>=0; i--) {
        // undo operation
        listOfCommands[i]->reverseExecute();
        cout << locker->getVal() << endl;
    }
}

int main() {
    Client();

    return 0;
}