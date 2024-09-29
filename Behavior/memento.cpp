#include<iostream>
using namespace std;

class ObjectMemento;
class Object;
class History;

class ObjectMemento {
private:
    string info;

public:
    ObjectMemento(string s) {
        info = s;
    }

    string get() {
        return info;
    }
};

class History {
private:
    vector<ObjectMemento*> objectMementos;

public:
    void add(ObjectMemento* objectMemento) {
        objectMementos.push_back(objectMemento);
    }
    ObjectMemento* getIndex(int index) {
        int n = objectMementos.size();
        if (index < 0 || index >= n) return nullptr; 
        while (n > index+1) {
            n--;
            objectMementos.pop_back();
        }
        return objectMementos.back();
    }
};

class Object {
private:
    string info;

public:
    Object() {
        info = "";
    }
    string get() {
        return info;
    }
    void add(string s) {
        info += s;
    } 
    ObjectMemento* createMemento() {
        return new ObjectMemento(info);
    }
    void restoreMemento(ObjectMemento* objectMemento) {
        this->info = objectMemento->get();
    }
};

void Client() {
    History* history = new History();
    Object* object = new Object();
    object->add("hello ");
    cout << object->get() << endl;
    object->add("world. ");
    cout << object->get() << endl;
    history->add(object->createMemento());
    object->add("This ");
    cout << object->get() << endl;
    object->add("Whis. ");
    cout << object->get() << endl;
    object->restoreMemento(history->getIndex(0));
    cout << object->get() << endl;
}

int main() {
    Client();

    return 0;
}