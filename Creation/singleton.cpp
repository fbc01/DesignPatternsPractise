#include <iostream>
#include <mutex>
using namespace std;

mutex mtx;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance() {
        // Double-check locking
        if (instance == nullptr) {
            lock_guard<mutex> lockGuard(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void show() {
        cout << "This is singleton" << endl;
    }
};

Singleton* Singleton::instance = nullptr;

void Client() {
    Singleton* instance = Singleton::getInstance();
    instance->show();
}

int main() {
    Client();
    return 0;
}