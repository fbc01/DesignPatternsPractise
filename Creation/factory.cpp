// simple factory
#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    virtual void getDescription() = 0;
};

class TwoWheeler: public Vehicle {
public:
    void getDescription() override {
        cout << "This is Two Wheeler" << endl;
    }
};

class FourWheeler: public Vehicle {
public:
    void getDescription() override {
        cout << "This is Four Wheeler" << endl;
    }
};

class VehicleFactory {
public:
    Vehicle* createVehicle(int wheel) {
        if (wheel == 2) {
            return new TwoWheeler();
        }
        else if (wheel == 4) {
            return new FourWheeler();
        }
        else {
            cout << "Wrong input" << endl;
            return nullptr;
        }
    }
};

void client() {
    VehicleFactory* factory = new VehicleFactory();
    Vehicle* twoWheeler = factory->createVehicle(2);
    twoWheeler->getDescription();
    Vehicle* fourWheeler = factory->createVehicle(4);
    fourWheeler->getDescription();
}

int main() {
    client();

    return 0;
}

