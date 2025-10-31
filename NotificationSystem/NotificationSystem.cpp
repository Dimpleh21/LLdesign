#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class INotification{
    public:
        virtual string getContent() const =0;
        virtual ~INotification(){};
};

class SimpleNotification : public INotification {
    private:
        string message;
    public:
        SimpleNotification(const string& msg) : message(msg) {}
        string getContent() const override {
            return "Notification: " + message;
        }   
};

class INotificationDecorator : public INotification {
    protected:
        INotification* currNotification;
    public:
        INotificationDecorator(INotification* notification) : currNotification(notification) {
        }
        virtual ~INotificationDecorator() {
            delete currNotification;
        }
};

class TimeStampDecorator : public INotificationDecorator {
    public:
        TimeStampDecorator(INotification* notification) : INotificationDecorator(notification) {}
        string getContent() const override {
            return currNotification->getContent() + "[2024-06-01 10:00:00]";
        }

};

class SignatureDecorator : public INotificationDecorator {
    string sig;
    public:
        SignatureDecorator(INotification* notification, const string& signature) : INotificationDecorator(notification) {
            sig = signature;
        }
        string getContent() const override {
            return currNotification->getContent() + sig;
        }
};

class IObserver{
    public:
        virtual void update() =0;
        virtual ~IObserver(){};
};

class IObservable{
    public:
    virtual void addObserver(IObserver* observer) =0;
    virtual void removeObserver(IObserver* observer) =0;
    virtual void notifyObservers() =0;
};

class NotificationObservable : public IObservable {
    private:
        INotification* currNotification;
        vector<IObserver*> observers;
    public:
        NotificationObservable(INotification* notification) : currNotification(notification) {}
        void addObserver(IObserver* observer) override {
            observers.push_back(observer);
        }

        void removeObserver(IObserver* observer) override {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notifyObservers() override {
            for (auto observer : observers) {
                observer->update();
            }
        }

        void setNotification(INotification* notification) {
            if(notification!= nullptr){
                delete currNotification;
            }
            currNotification = notification;
            notifyObservers();
        }

        INotification* getNotification() const {
            return currNotification;
        }

        string getNotificationContent() const {
            return currNotification->getContent();
        }

        ~NotificationObservable() {
            delete currNotification;
        }
};

//singleton class
//Notification service

class NotificationService{
    private:
        static NotificationService* instance;
        NotificationObservable* observable;
        vector<INotification*> notificationHistory;
        NotificationService() {
            observable = new NotificationObservable(nullptr);
        }
    public:
        static NotificationService* getInstance(){
            if(instance==nullptr){
                instance = new NotificationService();
            }
            return instance;
        }

        NotificationObservable* getObservable() const {
            return observable;
        }

        void sendNotification(INotification* notification) {
            observable->setNotification(notification);
            notificationHistory.push_back(notification);
        }   
        ~NotificationService() {
            delete observable;
        }

};
NotificationService* NotificationService::instance = nullptr;

class Logger : public IObserver {
    private:
        NotificationObservable* notificationObservable;
    public:
        Logger(){
            this->notificationObservable = NotificationService::getInstance()->getObservable();
            notificationObservable->addObserver(this);
        }
        Logger(NotificationObservable* obs) : notificationObservable(obs) {
            notificationObservable->addObserver(this);
        }
        void update() override {
            cout << "Logger: Notification updated: " << notificationObservable->getNotificationContent() << endl;
        }
};

//Abstract class for strategies

class INotificationStrategy {
    public:
        virtual void sendNotification(string content) =0;
        virtual ~INotificationStrategy(){};
};


class EmailStrategy: public INotificationStrategy {
    private:
        string EmailId;
    public:
        EmailStrategy(const string& email) : EmailId(email) {}
        void sendNotification(string content) override {
            cout << " sending Email Notification to " << EmailId << ": " << content << endl;
        }
};

class SMSStrategy: public INotificationStrategy {
    private:
        string PhoneNumber;
    public:
    SMSStrategy(const string& phone) : PhoneNumber(phone) {}
    void sendNotification(string content) override {
        cout << " sending SMS Notification to " << PhoneNumber << ": " << content << endl;
    }    

};
class PopUpStrategy : public INotificationStrategy{
    public:
        void sendNotification(string content) override {
            cout << " showing Pop-Up Notification: " << content << endl;
        }
};

class NotificationEngine : public IObserver {
    private:
        NotificationObservable* observable;
        vector<INotificationStrategy*> strategies;
    public:
        NotificationEngine(){
            this->observable = NotificationService::getInstance()->getObservable();
            observable->addObserver(this);
        }
        NotificationEngine(NotificationObservable* obs) : observable(obs) {
            observable->addObserver(this);
        }
        void addStrategy(INotificationStrategy* strategy) {
            strategies.push_back(strategy);
        }
        void update() override {
            INotification* notification = observable->getNotification();
            for(auto strategy: strategies){
                strategy->sendNotification(notification->getContent());
            }
        }

};

int main() {
    NotificationService* service = NotificationService::getInstance();
    Logger* logger = new Logger();
    NotificationEngine* engine = new NotificationEngine();
    engine->addStrategy(new EmailStrategy("example@example.com"));
    engine->addStrategy(new SMSStrategy("123-456-7890"));
    engine->addStrategy(new PopUpStrategy());

    //create notification using decorators
    INotification* notification = new SimpleNotification("System Update Available");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, " - Admin Team");

    service->sendNotification(notification);
    delete logger;
    delete engine;
    return 0;
}