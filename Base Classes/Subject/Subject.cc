export module subject;
import <vector>;
import observer;

export class Subject {
    std::vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyObservers(string action);
        virtual ~Subject() = 0;
};