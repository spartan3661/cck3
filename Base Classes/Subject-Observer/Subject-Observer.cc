export module subject_observer;
import <vector>;
import <string>;

export class Subject;

export class Observer {
    public:
        virtual void notify(Subject& whoNotified, std::string action) = 0;
        virtual std::string getName() = 0;
        virtual ~Observer() = default;
};

class Subject {
    std::vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyObservers(std::string action);
        int getLength();
        virtual ~Subject() = 0;
};