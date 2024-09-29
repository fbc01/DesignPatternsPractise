#include <iostream>
#include <string>

using namespace std;


class PrototypeInterface{
public:
    virtual PrototypeInterface* clone() = 0;
    virtual void draw() = 0;
};

class CirclePrototype : public PrototypeInterface {
private:
    int radius;

public:
    CirclePrototype(int radius) {
        // computationally heavy process
        this->radius = radius;
    }

    void draw() override {
        cout << "color area of " << this->radius << " circle" << endl;
    }

    PrototypeInterface* clone() override {
        PrototypeInterface* clonedCircle = new CirclePrototype(this->radius);
        return clonedCircle;
    }

};

void client() {
    PrototypeInterface* circleWithRadiusFive = new CirclePrototype(5);
    PrototypeInterface* circleWithRadiusFiveCloneOne = circleWithRadiusFive->clone();
    PrototypeInterface* circleWithRadiusFiveCloneTwo = circleWithRadiusFive->clone();
    circleWithRadiusFiveCloneOne->draw();
    circleWithRadiusFiveCloneTwo->draw();
}

int main() {
    client();

    return 0;
}