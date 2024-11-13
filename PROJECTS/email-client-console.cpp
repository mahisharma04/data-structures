#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Base class [Email]
class Email {
protected:
    string from;
    string to;
    string subject;
    string body;
    string type;

public:
    Email(string frm, string t, string sub, string b, string emailType)
        : from(frm), to(t), subject(sub), body(b), type(emailType) {}

    // Virtual function to be overridden by derived classes [concept of polymorphism]
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
    // Default constructor (needed for unordered_map)
    User() {}

    // Constructor for User class
    User(string uname, string pass) : username(uname), password(pass) {}

    // Function to login
    bool login(string pass) {
        return password == pass;
    }

    // Function to add emails to the inbox.
    void receiveEmail(Email* email) {
        inbox.push_back(email);  // Store pointer to the email
    }

    // Display inbox
    void showInbox() const {
        if (inbox.empty()) {
            cout << "No emails in the inbox for " << username << "." << endl;
        } else {
            cout << "===== Inbox for " << username << " =====" << endl;
            for (const Email* email : inbox) {
                email->display();  // Calls the appropriate display() method [by polymorphism]
                cout << endl;
            }
            cout << "===================================" << endl;
        }
    }

    string getUsername() const {
        return username;
    }
};

// EmailSystem class
class EmailSystem {
private:
    unordered_map<string, User> users;  // Hash table for users with usernames as keys

public:
    // Add a user to the system
    void addUser(const User& user) {
        users[user.getUsername()] = user;  // Insert user into hash table
    }

    // Find a user by username
    User* findUser(string username) {
        auto it = users.find(username);
        if (it != users.end()) return &it->second;
        return nullptr;
    }

    // Send an email
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

            // Create new email objects dynamically for each sent email
            if (emailType == "personal") {
                newEmail = new PersonalEmail(sender->getUsername(), recipientUser->getUsername(), subject, body);
            } else if (emailType == "work") {
                newEmail = new WorkMail(sender->getUsername(), recipientUser->getUsername(), subject, body);
            } else {
                cout << "Invalid email type. Email not sent." << endl;
                return;
            }

            recipientUser->receiveEmail(newEmail);  // Pass the pointer to the new email object
            cout << "Email sent to " << recipient << "!" << endl;

            // Print the email that was sent (as per your request)
            cout << "===== Email Sent =====\n"
                 << "From: " << sender->getUsername() << "\nTo: " << recipient << "\nSubject: " << subject
                 << "\nBody: " << body << "\n======================\n";
        } else {
            cout << "Recipient not found." << endl;
        }
    }

    // Display inbox for a user
    void checkInbox(User* loggedInUser) {
        loggedInUser->showInbox();
    }
};

int main() {
    EmailSystem system;
    int userCount;

    cout << "Enter number of users: ";
    cin >> userCount;

    // Add users to the system
    for (int i = 0; i < userCount; ++i) {
        string username, password;
        cout << "Enter username for user " << (i + 1) << ": ";
        cin >> username;
        cout << "Enter password for user " << (i + 1) << ": ";
        cin >> password;
        system.addUser(User(username, password));
    }

    // Outer loop to allow different users to log in and perform actions
    while (true) {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        User* loggedInUser = system.findUser(username);
        if (loggedInUser && loggedInUser->login(password)) {
            char choice = 'n';

            do {
                cout << "\nWhat would you like to do?\n";
                cout << "1. Write an email\n";
                cout << "2. Check your inbox\n";
                cout << "3. Exit\n";
                cout << "Enter your choice (1/2/3): ";
                cin >> choice;

                switch (choice) {
                    case '1':
                        system.sendEmail(loggedInUser);
                        break;
                    case '2':
                        system.checkInbox(loggedInUser);
                        break;
                    case '3':
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice, please try again.\n";
                }
            }  while (choice != '3');
        } else {
            cout << "Login failed." << endl;
        }

        // Ask if another user wants to log in (as per your request)
        char retry;
        cout << "Do you want another user to log in? (y/n): ";
        cin >> retry;

        if (retry == 'n' || retry == 'N') {
            cout << "Exiting the system." << endl;
            break;
        }
    }

    return 0;
}