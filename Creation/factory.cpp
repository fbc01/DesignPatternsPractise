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
    virtual Vehicle* createVehicle() = 0;
};

class TwoWheelerFactory: public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* twoWheeler = new TwoWheeler();
        return twoWheeler;
    }
};

class FourWheelerFactory: public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        Vehicle* fourWheeler = new FourWheeler();
        return fourWheeler;
    }
};

void client() {
    VehicleFactory* factory = new TwoWheelerFactory();
    Vehicle* vehicle = factory->createVehicle();
    vehicle->getDescription();
    factory = new FourWheelerFactory();
    vehicle = factory->createVehicle();
    vehicle->getDescription();
}

int main() {
    client();

    return 0;
}

