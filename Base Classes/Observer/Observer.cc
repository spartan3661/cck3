export module observer;
import <string>;
import subject;

export class Observer {
    public:
        virtual void notify(Subject& whoNotified) = 0;
        virtual std::string getName() = 0;
        virtual ~Observer() = default;
};