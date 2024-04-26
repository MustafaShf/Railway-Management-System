#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Signin {
private:
    string userId;
    string password;

public:
    // Default constructor
    Signin() : userId(""), password("") {}

    // Parameterized constructor
    Signin(const string& uid, const string& pass) : userId(uid), password(pass) {}

    // Copy constructor
    Signin(const Signin& other) : userId(other.userId), password(other.password) {}

    // Destructor
    ~Signin() {}

    // Getter for userId
    string getUserId() const {
        return userId;
    }

    // Getter for password
    string getPassword() const {
        return password;
    }

    // Setter for userId
    void setUserId(const string& uid) {
        userId = uid;
    }

    // Setter for password
    void setPassword(const string& pass) {
        password = pass;
    }



    //Functions:

    void userLogin() 
    {
        /////////////////////////////NEED MORE//////////////////////////
        int count = 0;
        string id, pass;
        cout << "\t\t\t Please enter the username and password: " << endl;
        cout << "\t\t\t USERNAME: ";
        cin >> userId;
        cout << "\t\t\t PASSWORD: ";
        cin >> password;
        ifstream input("records.txt");
        while (input >> id >> pass) {
            if (id == userId && pass == password) {
                count = 1;
            }
        }
        input.close();
        if (count == 1) {
            cout << userId << "\n Your LOGIN is successful. Thanks for logging in!" << endl;
        }
        else {
            cout << "\n LOGIN ERROR! Please check your username and password." << endl;
            this->userLogin();
        }
    }

    void adminLogin()
    {
        int count = 0;
        string id, pass;
        cout << "\t\t\t Please enter the Admin name and password: " << endl;
        cout << "\t\t\t USERNAME: ";
        cin >> userId;
        cout << "\t\t\t PASSWORD: ";
        cin >> password;
        ifstream input("records.txt");
        while (input >> id >> pass) {
            if (id == userId && pass == password) {
                count = 1;
            }
        }
        input.close();
        if (count == 1) {
            cout << userId << "\n Your LOGIN is successful. Thanks for logging in!" << endl;
        }
        else {
            cout << "\n LOGIN ERROR! Please check your username and password." << endl;
            this->userLogin();
        }
    }

    void forgot() {
        int option;
        cout << "\t\t\t You forgot the password? No worries." << endl;
        cout << "Press 1 to search your id by Name or email" << endl;
        cout << "Press 2 to go back to the main menu" << endl;
        cout << "\t\t\t Enter your choice: ";
        cin >> option;
        switch (option) {
        case 1: {
            int count = 0;
            string sId, spass;
            cout << "\n\t\t\t Enter the username you remembered: ";
            cin >> this->userId;
            ifstream f2("records.txt");
            while (f2 >> sId >> spass) {
                if (sId == userId) {
                    count = 1;
                    this->password = spass;
                }
            }
            f2.close();
            if (count == 1) {
                cout << "\n\n Your account is found! \n";
                //    cout << "\n\n Your password is: " << spass;
                cout << "\n\n Your password is: " << this->password;
                ;

            }
            else {
                cout << "\n\t Sorry! Your account is not found!" << endl;
            }
            break;
        }
        case 2: {
            break;
        }
        default: {
            cout << "\t\t\t Wrong choice! Please try again." << endl;
            this->forgot();
            break;
        }
        }
    }
}; 

    class Signup {
    private:
        string userId;
        string password;

    public:
        // Default constructor
        Signup() : userId(""), password("") {}

        // Parameterized constructor
        Signup(const string& uid, const string& pass) : userId(uid), password(pass) {}

        // Copy constructor
        Signup(const Signup& other) : userId(other.userId), password(other.password) {}

        // Destructor
        ~Signup() {}

        // Getter for userId
        string getUserId() const {
            return userId;
        }

        // Getter for password
        string getPassword() const {
            return password;
        }

        // Setter for userId
        void setUserId(const string& uid) {
            userId = uid;
        }

        // Setter for password
        void setPassword(const string& pass) {
            password = pass;
        }

        void userRegistration() {
            cout << "\t\t\t Enter the username: ";
            cin >> userId;
            cout << "\t\t\t Enter the password: ";
            cin >> password;
            ofstream f1("records.txt", ios::app);
            f1 << userId << ' ' << password << endl;

            cout << "\n\t\t\t Registration is successful! \n";
        }
        void adminRegistration() {

            cout << "\t\t\t Enter the Admin name: ";
            cin >> userId;
            cout << "\t\t\t Enter the password: ";
            cin >> password;
            ofstream f1("records.txt", ios::app);
            f1 << userId << ' ' << password << endl;
            cout << "\n\t\t\t Registration is successful! \n";
        }

        void Forgot() {
            int option;
            cout << "\t\t\t You forgot the password? No worries." << endl;
            cout << "Press 1 to search your id by Name or email" << endl;
            cout << "Press 2 to go back to the main menu" << endl;
            cout << "\t\t\t Enter your choice: ";
            cin >> option;
            switch (option) {
            case 1: {
                int count = 0;
                string sId, spass;
                cout << "\n\t\t\t Enter the username you remembered: ";
                cin >> this->userId;
                ifstream f2("records.txt");
                while (f2 >> sId >> spass) {
                    if (sId == userId) {
                        count = 1;
                        this->password = spass;
                    }
                }
                f2.close();
                if (count == 1) {
                    cout << "\n\n Your account is found! \n";
                    //    cout << "\n\n Your password is: " << spass;
                    cout << "\n\n Your password is: " << this->password;
                    ;

                }
                else {
                    cout << "\n\t Sorry! Your account is not found!" << endl;
                }
                break;
            }
            case 2: {
                break;
            }
            default: {
                cout << "\t\t\t Wrong choice! Please try again." << endl;
                this->Forgot();
                break;
            }
            }
        }
        };


        class Accounts :public Signin , public Signup
        {
        private:
            int inputChoice;

        public:
            // Default constructor
            Accounts() : inputChoice(0) {}

            // Parameterized constructor
            Accounts(int choice) : inputChoice(choice) {}

            // Copy constructor
            Accounts(const Accounts& other) : inputChoice(other.inputChoice) {}

            // Destructor
            ~Accounts() {}

            // Getter for inputChoice
            int getInputChoice() const {
                return inputChoice;
            }

            // Setter for inputChoice
            void setInputChoice(int choice) {
                inputChoice = choice;
            }

            void WhatType_ofAccount() {
                cout << "Welcome to Accounts\n\n\n";
                cout << "\t Press 1 to LOGIN as a User" << endl;
                cout << "\t Press 2 to LOGIN as an Admin" << endl;
                cout << "\t Press 3 to REGISTER as a User" << endl;
                cout << "\t Press 4 to REGISTER as an Admin" << endl;
                cout << "\t Press 5 if you are a User and forgot your Password" << endl;
                cout << "\t Press 6 if you are an ADMIN and forgot your Password" << endl;
                cout << "\t Press 7 to EXIT" << endl;
                cout << "\n\t\t\t Please enter your choice: ";
                cin >> this->inputChoice;
                cout << endl;

                switch (this->inputChoice) {
                case 1:
                    this->userLogin();
                    break;
                case 2:
                    this->adminLogin();
                    break;
                case 3:
                    this->userRegistration();
                    break;
                case 4:
                    this->adminRegistration();
                    break;
                case 5:
                    this->forgot();
                    break;
                case 6:
                        this->Forgot();
                        break;
                case 7:
                    cout << "\t\t\t Thank you!" << endl << endl;
                    break;
                default:
                    cout << "\t\t\t Please select from the options given above" << endl << endl;
                    this->WhatType_ofAccount();
                    break;
                }
            }
        };


        int main() {

            Accounts A1;
            A1.WhatType_ofAccount();
            return 0;
        }
