
#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

// observer interface
class Observer {
    public:
        virtual string getId() = 0;
        virtual void update(string msg) = 0;
};

// subject interface
class Subject {
    public:
        virtual void addObserver(Observer* observer) = 0;
        virtual void removeObserver(Observer* observer) = 0;
        virtual void notifyObservers() = 0;
};



// concrete subject
class WeatherStation : public Subject {
    private:
        double temparature;
        list<Observer*> observers;
    
    public:
        WeatherStation() {
            temparature = 0;
        }

        void addObserver(Observer* observer) {
            for (list<Observer*>:: iterator itr = begin(observers); itr != end(observers); itr++) {
                if ((*itr)->getId() == observer->getId()) {
                    return;
                }
            }
            observers.push_back(observer);
        }

        void removeObserver(Observer* observer) {
            for (list<Observer*>:: iterator itr = begin(observers); itr != end(observers); itr++) {
                if ((*itr)->getId() == observer->getId()) {
                    observers.erase(itr);
                    return;
                }
            }
        }

        void notifyObservers() {
            for (list<Observer*>:: iterator itr = begin(observers); itr != end(observers); itr++) {
                (*itr)->update(to_string(temparature));
            }
        }

        void setTemparature (double value) {
            temparature = value;
            this->notifyObservers();
        }
};


// concrete observer 1 
class TelevisionDisplay : public Observer {
    private:
        string id;

    public:
        TelevisionDisplay(string id) {
            this->id = id;
        }

        string getId() {
            return id;
        }

        void update(string msg) {
            cout << "TV shows current temp as " << msg << " degree celcius" << endl;
        } 
};

// concrete observer 2
class PhoneDisplay : public Observer {
    private:
        string id;

    public:
        PhoneDisplay(string id) {
            this->id = id;
        }

        string getId() {
            return id;
        }

        void update(string msg) {
            cout << "Phone shows current temp as " << msg << " degree celcius" << endl;
        } 
};


int main() {
    WeatherStation* weatherStation = new WeatherStation();
    Observer* televisionDisplay = new TelevisionDisplay("MyTV");
    Observer* phoneDisplay = new PhoneDisplay("MyPhone");

    weatherStation->addObserver(televisionDisplay);
    weatherStation->addObserver(phoneDisplay);

    weatherStation->setTemparature(37);
    weatherStation->setTemparature(40);
    weatherStation->removeObserver(phoneDisplay);
    weatherStation->setTemparature(42);

    /*
        Output : 
            TV shows current temp as 37.000000 degree celcius
            Phone shows current temp as 37.000000 degree celcius
            TV shows current temp as 40.000000 degree celcius
            Phone shows current temp as 40.000000 degree celcius
            TV shows current temp as 42.000000 degree celcius
    */

    return 0;
}

