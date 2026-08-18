#include <iostream>

using namespace std;


// Product 1 --> Notification
class Notification {
public:
    virtual void send(string& message) = 0;
    virtual ~Notification() {}
};


// Email Notification
class EmailNotification : public Notification {
public:
    void send(string& message) override {
        cout << "Sending Email: " << message << endl;
    }
};


// SMS Notification
class SMSNotification : public Notification {
public:
    void send(string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};


// WhatsApp Notification
class WhatsAppNotification : public Notification {
public:
    void send(string& message) override {
        cout << "Sending WhatsApp Message: " << message << endl;
    }
};


// Product 2 --> Notification Logger
class NotificationLogger {
public:
    virtual void log(string& message) = 0;
    virtual ~NotificationLogger() {}
};


// Email Logger
class EmailLogger : public NotificationLogger {
public:
    void log(string& message) override {
        cout << "Email Log: " << message << endl;
    }
};


// SMS Logger
class SMSLogger : public NotificationLogger {
public:
    void log(string& message) override {
        cout << "SMS Log: " << message << endl;
    }
};


// WhatsApp Logger
class WhatsAppLogger : public NotificationLogger {
public:
    void log(string& message) override {
        cout << "WhatsApp Log: " << message << endl;
    }
};


// Abstract Factory
class NotificationFactory {
public:
    virtual Notification* createNotification() = 0;
    virtual NotificationLogger* createLogger() = 0;
    virtual ~NotificationFactory() {}
};


// Email Factory
class EmailFactory : public NotificationFactory {
public:

    Notification* createNotification() override {
        return new EmailNotification();
    }

    NotificationLogger* createLogger() override {
        return new EmailLogger();
    }
};


// SMS Factory
class SMSFactory : public NotificationFactory {
public:

    Notification* createNotification() override {
        return new SMSNotification();
    }

    NotificationLogger* createLogger() override {
        return new SMSLogger();
    }
};


// WhatsApp Factory
class WhatsAppFactory : public NotificationFactory {
public:

    Notification* createNotification() override {
        return new WhatsAppNotification();
    }

    NotificationLogger* createLogger() override {
        return new WhatsAppLogger();
    }
};


int main() {

    string type;
    string message;


    cout << "Enter notification type (email/sms/whatsapp): ";
    cin >> type;

    cout << "Enter your message: ";
    cin.ignore();
    getline(cin, message);


    NotificationFactory* notificationFactory;


    if (type == "email") {

        notificationFactory = new EmailFactory();

    } else if (type == "sms") {

        notificationFactory = new SMSFactory();

    } else if (type == "whatsapp") {

        notificationFactory = new WhatsAppFactory();

    } else {

        cout << "Invalid notification type!" << endl;
        return 0;
    }


    Notification* notification =
        notificationFactory->createNotification();

    NotificationLogger* logger =
        notificationFactory->createLogger();


    notification->send(message);

    logger->log(message);


    delete notification;
    delete logger;
    delete notificationFactory;


    return 0;
}