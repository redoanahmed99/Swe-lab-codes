#include <iostream>

using namespace std;


// Product --> Notification
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


// Creator --> Factory (Factory Method)
class NotificationFactory {
public:
    virtual Notification* createNotification() = 0;
    virtual ~NotificationFactory() {}
};


// Email Factory
class EmailFactory : public NotificationFactory {
public:
    Notification* createNotification() override {
        return new EmailNotification();
    }
};


// SMS Factory
class SMSFactory : public NotificationFactory {
public:
    Notification* createNotification() override {
        return new SMSNotification();
    }
};


// WhatsApp Factory
class WhatsAppFactory : public NotificationFactory {
public:
    Notification* createNotification() override {
        return new WhatsAppNotification();
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


    notification->send(message);


    delete notification;
    delete notificationFactory;


    return 0;
}