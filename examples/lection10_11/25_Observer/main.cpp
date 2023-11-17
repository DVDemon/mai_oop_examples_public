#include <iostream>
#include <vector>
#include <algorithm>

// Abstract Observer class
class Observer {
public:
    virtual void update(int value) noexcept = 0;
};

// Concrete Observer classes
class ConcreteObserverA : public Observer {
public:
    void update(int value) noexcept override {
        std::cout << "ConcreteObserverA: Reacted to the event with value " << value << std::endl;
    }
};

class ConcreteObserverB : public Observer {
public:
    void update(int value) noexcept override {
        std::cout << "ConcreteObserverB: Reacted to the event with value " << value << std::endl;
    }
};

// Abstract Subject class
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject class
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    int subjectState;

public:
    int getState() {
        return subjectState;
    }

    void setState(int state) {
        subjectState = state;
        notify();
    }

    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(subjectState);
        }
    }
};

int main() {
    ConcreteObserverA observerA;
    ConcreteObserverB observerB;

    ConcreteSubject subject;

    subject.attach(&observerA);
    subject.attach(&observerB);

    subject.setState(15);  // Both observers will be notified

    subject.detach(&observerA);

    subject.setState(20);  // Only observerB will be notified

    return 0;
}