module subject_observer;
import <vector>;
import <string>;

using namespace std;


// Subject

void Subject::attach(Observer *o) { observers.emplace_back(o); }

void Subject::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(string action) {
    for ( auto &ob : observers ) ob->notify( *this, action );
}

int Subject::getLength() {return observers.size(); }

Subject::~Subject() {}


// Observer

void Observer::notify(Subject& whoNotified, string action) {}

string Observer::getName() { return ""; }