#include<iostream>
#include<string>


using namespace std;

class Mediator;

class Component {
    private:
        string componentId;
    
    protected:
        Mediator* mediator;

    public:
        Component(string id) {
            componentId = id;
        }

        void setMediator (Mediator* mediator) {
            this->mediator = mediator;
        }

        string getId() const {
            return componentId;
        }

        bool isEqual (Component* component) const {
            return component->getId() == this->getId();
        }

        virtual void respondA() = 0;

        virtual void respondB() = 0;

        virtual void triggerA() = 0;

        virtual void triggerB() = 0;


};

class Mediator {
    public:
        virtual void listen(Component* component, string event) = 0;
};


class ConcreteComponent1: public Component {
    public:
        ConcreteComponent1(string id) : Component(id) {}

        void triggerA() override {
            cout << this->getId() << " sent event A to Mediator" << endl;
            this->mediator->listen(this, "A"); 
        }

        void triggerB() override {
            cout << this->getId() << " sent event B to Mediator" << endl;
            this->mediator->listen(this, "B"); 
        }

        void respondA() override {
            cout << this->getId() << " is responding to event A" << endl;
        }

        void respondB() override {
            cout << this->getId() << " is responding to event B" << endl;
        }
};

class ConcreteComponent2: public Component {
    public:
        ConcreteComponent2(string id) : Component(id) {}

        void triggerA() override {
            cout << this->getId() << " sent event A to Mediator" << endl;
            this->mediator->listen(this, "A"); 
        }

        void triggerB() override {
            cout << this->getId() << " sent event B to Mediator" << endl;
            this->mediator->listen(this, "B"); 
        }

        void respondA() override {
            cout << this->getId() << " is responding to event A" << endl;
        }

        void respondB() override {
            cout << this->getId() << " is responding to event B" << endl;
        }
};


class ConcreteMediator : public Mediator {
    private:
        ConcreteComponent1* component1_;
        ConcreteComponent2* component2_;

    public:
        ConcreteMediator(ConcreteComponent1* component1, ConcreteComponent2* component2) {
            this->component1_ = component1;
            this->component2_ = component2;
        }

        void listen(Component* component, string event) override {
            if (component1_->isEqual(component)) {
                if (event == "A") {
                    this->component2_->respondB();
                }
                else if (event == "B") {
                    this->component2_->respondA();
                }
                else {
                    cout << "event operation not found" << endl;
                }
            }
            else if (component2_->isEqual(component)) {
                if (event == "A") {
                    this->component1_->respondB();
                }
                else if (event == "B") {
                    this->component1_->respondA();
                }
                else {
                    cout << "event operation not found" << endl;
                }
            }
        }
};


void client() {
    ConcreteComponent1* component1 = new ConcreteComponent1("component1");
    ConcreteComponent2* component2 = new ConcreteComponent2("component2");

    ConcreteMediator* mediator = new ConcreteMediator(component1, component2);
    component1->setMediator(mediator);
    component2->setMediator(mediator);

    component1->triggerA();
    component2->triggerB();

    /*
    Output ->

        component1 sent event A to Mediator
        component2 is responding to event B
        component2 sent event B to Mediator
        component1 is responding to event A
    */
}

int main() {
    client();

    return 0;
}
