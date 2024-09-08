
#include <iostream>
#include <string>

using namespace std;

class AirplaneColleague {
    public:
        virtual void requestTakeOff() = 0;
        virtual void requestLanding() = 0;
        virtual void notifyAirTrafficControl(string msg) = 0;
};

class CentralControlMediator {
    public:
        virtual void requestTakeOff(AirplaneColleague* airplane) = 0;
        virtual void requestLanding(AirplaneColleague* airplane) = 0;
};


class CentralControlConcrete : public CentralControlMediator {
    public:
        void requestTakeOff(AirplaneColleague* airplane) {
            airplane->notifyAirTrafficControl("Request Take off Clearance");
        }

        void requestLanding(AirplaneColleague* airplane) {
            airplane->notifyAirTrafficControl("Request Landing Clearance");
        }
};

class Airplane : public AirplaneColleague {
    private:
        CentralControlMediator* centralControlMediator;

    public:
        Airplane(CentralControlMediator* centralControlMediator) {
            this->centralControlMediator = centralControlMediator;
        }

        void requestTakeOff() {
            centralControlMediator->requestTakeOff(this);
        }

        void requestLanding() {
            centralControlMediator->requestLanding(this);
        }

        void notifyAirTrafficControl(string msg) {
            cout << "Commercial plane = " << msg << endl;
        }
};

int main() {
    CentralControlConcrete* centralControlConcrete = new CentralControlConcrete();
    Airplane* airplane1 = new Airplane(centralControlConcrete);
    Airplane* airplane2 = new Airplane(centralControlConcrete);

    airplane1->requestTakeOff();
    airplane2->requestLanding();

    return 0;
}

