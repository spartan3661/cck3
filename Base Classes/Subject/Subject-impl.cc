module subject;
import <vector>;
import observer;

using namespace std;


void Subject::attach(Observer *o) { observers.emplace_back(o); }

void Subject::detach(Observer *o) {}

void Subject::notifyObservers(string action) {
    for ( auto &ob : observers ) ob->notify( *this, action );
}

Subject::~Subject() {}