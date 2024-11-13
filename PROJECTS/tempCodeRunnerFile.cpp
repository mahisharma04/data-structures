#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class Email
class Email {
protected:
    string from;
    string to;
    string subject;
    string body;
    string type;  // Email type, either "Personal" or "Work"

public:
    Email(string frm, string t, string sub, string b, string emailType)
        : from(frm), to(t), subject(sub), body(b), type(emailType) {}

    // Virtual function to be overridden by derived classes
    virtual void display() const {
        cout << "Email from " << from << " to " << to << endl;
    }

    virtual ~Email() {}
};

// Derived class: PersonalEmail
class PersonalEmail : public Email {
public:
    PersonalEmail(string frm, string t, string sub, string b)
        : Email(frm, t, sub, b, "Personal") {}

    // Override display function for PersonalEmail
    void display() const override {
        cout << "===== [Personal Email] =====\n"
             << "From: " << from << "\nTo: " << to << "\nSubject: " << subject
             << "\nBody: " << body << "\n============================" << endl;
    }
};

// Derived class: WorkMail
class WorkMail : public Email {
public:
    WorkMail(string frm, string t, string sub, string b)
        : Email(frm, t, sub, b, "Work") {}

    // Override display function for WorkMail
    void display() const override {
        cout << "===== [Work Email] =====\n"
             << "From: " << from << "\nTo: " << to << "\nSubject: " << subject
             << "\nBody: " << body << "\n============================" << endl;
    }
};

// User class
class User {
private:
    string username;
    string password;
    vector<Email*> inbox;  // Storing pointers to Email objects

public:
    User(string uname, string pass) : username(uname), password(pass) {}

    bool login(string uname, string pass) {
        return username == uname && password == pass;
    }

    void receiveEmail(Email* email) {
        inbox.push_back(email);  // Store pointer to the email
    }

    void showInbox() const {
        if (inbox.empty()) {
            cout << "No emails in the inbox for " << username << "." << endl;
        } else {
            cout << "===== Inbox for " << username << " =====" << endl;
            for (const Email* email : inbox) {
                email->display();  // Calls the appropriate display() method
                cout << endl;
            }
            cout << "===================================" << endl;
        }
    }

    string getUsername() const { return username; }
};

// EmailSystem class
class EmailSystem {
private:
    vector<User> users;  // Store User objects directly

public:
    void addUser(const User& user) {
        users.push_back(user);
    }

    User* findUser(string username) {
        for (auto& user : users) {
            if (user.getUsername() == username) return &user;
        }
        return nullptr;
    }

    void sendEmail(User* sender) {
        string recipient, subject, body, emailType;
        cout << "Enter recipient username: ";
        cin >> recipient;

        User* recipientUser = findUser(recipient);
        if (recipientUser) {
            cout << "Enter subject: ";
            cin.ignore();
            getline(cin, subject);
            cout << "Enter body: ";
            getline(cin, body);
            cout << "Enter email type (personal/work): ";
            cin >> emailType;

            Email* newEmail = nullptr;
            if (emailType == "personal") {
                newEmail = new PersonalEmail(sender->getUsername(), recipientUser->getUsername(), subject, body);
            } else if (emailType == "work") {
                newEmail = new WorkMail(sender->getUsername(), recipientUser->getUsername(), subject, body);
            } else {
                cout << "Invalid email type. Email not sent." << endl;
                return;
            }

            recipientUser->receiveEmail(newEmail);  // Pass the pointer to the email
            cout << "Email sent to " << recipient << "!" << endl;

            recipientUser->showInbox();
        } else {
            cout << "Recipient not found." << endl;
        }
    }
};

// Main function
int main() {
    EmailSystem system;
    int userCount;

    cout << "Enter number of users: ";
    cin >> userCount;

    for (int i = 0; i < userCount; ++i) {
        string username, password;
        cout << "Enter username for user " << (i + 1) << ": ";
        cin >> username;
        cout << "Enter password for user " << (i + 1) << ": ";
        cin >> password;
        system.addUser(User(username, password));
    }

    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    User* loggedInUser = system.findUser(username);
    if (loggedInUser && loggedInUser->login(username, password)) {
        system.sendEmail(loggedInUser);
    } else {
        cout << "Login failed." << endl;
    }

    return 0;
}
