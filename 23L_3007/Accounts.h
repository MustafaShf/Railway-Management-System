#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int adminKey = 3421;



class UserSignin {
private:
    string userId;
    string userEmail;
    string password;
    string userContact;


public:
    // Default constructor
    UserSignin() : userId(""), password(""), userEmail(""), userContact("") {}

    // Parameterized constructor
    UserSignin(const string& uid, const string& pass, const string& uc, const string& ue) : userId(uid), password(pass), userEmail(ue), userContact(uc) {}

    // Copy constructor
    UserSignin(const UserSignin& other) : userId(other.userId), password(other.password), userEmail(other.userEmail), userContact(other.userContact) {}

    // Destructor
    ~UserSignin() {}

    // Getter for userId
    string getUserId() const {
        return userId;
    }

    // Setter for userId
    void setUserId(const string& value) {
        userId = value;
    }

    // Getter for userEmail
    string getUserEmail() const {
        return userEmail;
    }

    // Setter for userEmail
    void setUserEmail(const string& value) {
        userEmail = value;
    }

    // Getter for password
    string getPassword() const {
        return password;
    }

    // Setter for password
    void setPassword(const string& value) {
        password = value;
    }

    // Getter for userContact
    string getUserContact() const {
        return userContact;
    }

    // Setter for userContact
    void setUserContact(const string& value) {
        userContact = value;
    }



    //Functions:

    void userLogin()
    {
        bool isTrue = true;
        int choice = 0;
        int count = 0;
        string id, pass, mail, contact;

        do {

            cout << "\n Welcome to User Login\n\n\n";
            cout << "\t Press 1 if you want to Login" << endl;
            cout << "\t Press 2 if you don't have an Account and want to Sign up " << endl;
            cout << "\t Press 3 if you are a User and forgot your password " << endl;
            cout << "\t Press 0 if you are done and want to EXIT the User Login Section" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 0)
            {
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
            }

            else if (choice == 1) {
                cout << "\t\t\t Please enter the User details: " << endl;
                cout << "\t\t\t USERNAME: ";
                cin >> userId;
                cout << "\t\t\t PASSWORD: ";
                cin >> password;

                ifstream input("records.txt");
                while (input >> id >> pass >> mail >> contact) {
                    if (id == this->userId && pass == this->password) {
                        count = 1;
                    }
                }
                input.close();
                if (count == 1) {
                    cout << "Welcome! " << this->userId << "\n Your LOGIN is successful. Thanks for logging in!" << endl;
                }
                else {
                    cout << "\n LOGIN ERROR! Please check your username and password." << endl;
                    this->userLogin();
                }

            }

            else if (choice == 2) {
                this->userRegistration();
            }

            else if (choice == 3) {
                this->forgot();
            }
            else {
                cout << "\t\t\t Please select from the options given above" << endl << endl;
            }

        } while (isTrue);


    }



    void userRegistration()
    {
        bool isTrue = true;
        int choice = 0;

        do {

            cout << "\n Welcome to User Registration \n\n\n";
            cout << "\t Press 1 if you want to Sign Up" << endl;
            cout << "\t Press 2 if you already have an Account and want to Sign in " << endl;
            cout << "\t Press 3 if you are a User and forgot your password " << endl;
            cout << "\t Press 0 if you are done and want to EXIT the User Registration Section" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 0)
            {
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
            }

            else if (choice == 1)
            {
                cout << "\t\t\t Please enter the User details: " << endl;
                cout << "\t\t\t Enter the username: ";
                cin >> userId;
                cout << "\t\t\t Enter the password: ";
                cin >> password;
                cout << "\t\t\t Enter the user email: ";
                cin >> this->userEmail;
                cout << "\t\t\t Enter the contact number: ";
                cin >> this->userContact;
                ofstream f1("records.txt", ios::app);
                f1 << userId << ' ' << password << ' ' << userEmail << ' ' << userContact << endl;

                cout << "\n\t\t\t Registration is successful! \n";

            }

            else if (choice == 2) {
                this->userLogin();
            }
            else if (choice == 3) {
                this->forgot();
            }
            else {
                cout << "\t\t\t Please select from the options given above" << endl << endl;
            }

        } while (isTrue);


    }


    void forgot()
    {
        bool isTrue = true;
        int choice = 0;

        do {

            cout << "\n Welcome to User Forgot Password\n\n\n";
            cout << "\t Press 1 to search your id by Name or email " << endl;
            cout << "\t Press 2 if you already have an Account and want to Sign in " << endl;
            cout << "\t Press 3 if you don't have an Account and want to Sign up " << endl;
            cout << "\t Press 0 if you are done and want to EXIT the User Forgot Password Section" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 0)
            {
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
            }

            else if (choice == 1)
            {
                int count = 0;
                string sId, spass, smail, scontact;
                cout << "\t\t\t You forgot the password? No worries." << endl;

                cout << "\n\t\t\t Enter the username you remembered: ";
                cin >> this->userId;
                ifstream f2("records.txt");
                while (f2 >> sId >> spass >> smail >> scontact) {
                    if (sId == userId || smail == userId) {
                        count = 1;
                        this->password = spass;
                        this->userContact = scontact;
                        this->userEmail = smail;
                    }
                }
                f2.close();
                if (count == 1) {
                    cout << "\n\n Your account is found! \n";
                    //    cout << "\n\n Your password is: " << spass;
                    cout << "\n\n Your password is: " << this->password;

                }
                else {
                    cout << "\n\t Sorry! Your account is not found!" << endl;
                }

            }

            else if (choice == 2) {
                this->userLogin();
            }
            else if (choice == 3) {
                this->userRegistration();
            }
            else {
                cout << "\t\t\t Please select from the options given above" << endl << endl;
            }

        } while (isTrue);


    }
};

class AdminSignin {
private:
    string adminId;
    string adminpassword;


public:
    // Default constructor
    AdminSignin() : adminId(""), adminpassword("") {}

    // Parameterized constructor
    AdminSignin(const string& aid, const string& pass) : adminId(aid), adminpassword(pass) {}

    // Copy constructor
    AdminSignin(const AdminSignin& other) : adminId(other.adminId), adminpassword(other.adminpassword) {}

    // Destructor
    ~AdminSignin() {}

    // Getter for adminId
    string getAdminId() const {
        return adminId;
    }

    // Setter for adminId
    void setAdminId(const string& value) {
        adminId = value;
    }

    // Getter for adminpassword
    string getAdminPassword() const {
        return adminpassword;
    }

    // Setter for adminpassword
    void setAdminPassword(const
        string& value) {
        adminpassword = value;
    }


    //Functions:

    void adminLogin()
    {

        bool isTrue = true;
        int choice = 0;
        int count = 0;
        string id, pass;

        do {

            cout << "\n Welcome to ADMIN Login\n\n\n";
            cout << "\t Press 1 if you want to Login" << endl;
            cout << "\t Press 2 if you don't have an Account and want to Sign up " << endl;
            cout << "\t Press 3 if you are an Admin and forgot your password " << endl;
            cout << "\t Press 0 if you are done and want to EXIT the ADMIN Login Section" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 0)
            {
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
            }

            else if (choice == 1)
            {

                cout << "\t\t\t Please enter the Admin name and password: " << endl;
                cout << "\t\t\t ADMIN NAME: ";
                cin >> adminId;
                cout << "\t\t\t PASSWORD: ";
                cin >> adminpassword;
                ifstream input("admin.txt");
                while (input >> id >> pass) {
                    if (id == adminId && pass == adminpassword) {
                        count = 1;
                        adminpassword = pass;
                    }
                }
                input.close();
                if (count == 1) {
                    cout << "Welcome! " << adminId << "\n Your LOGIN is successful. Thanks for logging in!" << endl;
                }
                else {
                    cout << "\n LOGIN ERROR! Please check your username and password." << endl;
                    this->adminLogin();
                }
            }

            else if (choice == 2) {
                this->adminRegistration();
            }

            else if (choice == 3) {
                this->Forgot();
            }
            else {
                cout << "\t\t\t Please select from the options given above" << endl << endl;
            }

        } while (isTrue);

    }


    void adminRegistration()
    {


        bool isTrue = true;
        int choice = 0;
        int count = 0;
        string id, pass;

        do {

            cout << "\n Welcome to ADMIN Registration\n\n\n";
            cout << "\t Press 1 if you want to Sign up" << endl;
            cout << "\t Press 2 if you have an Account and want to Sign in " << endl;
            cout << "\t Press 3 if you are an Admin and forgot your password " << endl;
            cout << "\t Press 0 if you are done and want to EXIT the ADMIN Registration Section" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 0)
            {
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
            }

            else if (choice == 1)
            {

                cout << "\t\t\t Please enter the ADMIN details: " << endl;
                cout << "\t\t\t Enter the Admin name: ";
                cin >> adminId;
                cout << "\t\t\t Enter the password: ";
                cin >> adminpassword;

                ofstream f1("admin.txt", ios::app);
                f1 << adminId << ' ' << adminpassword << ' ' << endl;

                cout << "\n\t\t\t Registration is successful! \n";
                f1.close();

            }

            else if (choice == 2) {
                this->adminLogin();
            }

            else if (choice == 3) {
                this->Forgot();
            }
            else {
                cout << "\t\t\t Please select from the options given above" << endl << endl;
            }

        } while (isTrue);


    }


    void Forgot() {


        bool isTrue = true;
        int choice = 0;

        do {

            cout << "\n Welcome to ADMIN Forgot Password\n\n\n";
            cout << "\t Press 1 to search your id by Name " << endl;
            cout << "\t Press 2 if you already have an Account and want to Sign in " << endl;
            cout << "\t Press 3 if you don't have an Account and want to Sign up " << endl;
            cout << "\t Press 0 if you are done and want to EXIT the User Forgot Password Section" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 0)
            {
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
            }

            else if (choice == 1)
            {
                int count = 0;
                string sId, spass;
                cout << "\t\t\t You forgot the password? No worries." << endl;

                cout << "\n\t\t\t Enter the username you remembered: ";
                cin >> this->adminId;
                ifstream f2("admin.txt");
                while (f2 >> sId >> spass) {
                    if (sId == adminId) {
                        count = 1;
                        // // cout << endl << "Check: " << spass << endl;
                        this->adminpassword = spass;

                    }

                }
                f2.close();
                if (count == 1) {
                    cout << "\n\n Your account is found! \n";
                    //    //  cout << "\n\n Your password is: " << spass;
                    cout << "\n\n Your password is: " << this->adminpassword;

                }
                else {
                    cout << "\n\t Sorry! Your account is not found!" << endl;
                    this->Forgot();
                }

            }

            else if (choice == 2) {
                this->adminLogin();
            }
            else if (choice == 3) {
                this->adminRegistration();
            }
            else {
                cout << "\t\t\t Please select from the options given above" << endl << endl;
            }

        } while (isTrue);

    }
};



bool CheckAdminId(const int a)
{
    return(a == adminKey);


}

class Accounts :public UserSignin, public AdminSignin
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
        bool isTrue = true; // For outer loop
        bool istrue = true; // For 2nd loop.i.e. User and Admin
        bool isFalse = true;// For within the Admin
        while (isTrue)
        {


            cout << "Welcome to Accounts (Main Menu):\n\n\n";
            cout << "\t Press 1 if you are a User" << endl;
            cout << "\t Press 2 if you are an Admin" << endl;
            cout << "\t Press 0 to EXIT" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> this->inputChoice;
            cout << endl;

            switch (this->inputChoice)
            {
            case 0:
                cout << "\t\t\t Thank you!" << endl << endl;
                isTrue = false;
                break;
            case 1:
                istrue = true;
                while (istrue) {
                    cout << "\n Welcome!\n\n\n";
                    cout << "\t Press 1 to LOGIN as a User" << endl;
                    cout << "\t Press 2 to REGISTER as a User" << endl;
                    cout << "\t Press 3 if you are a User and forgot your Password" << endl;
                    cout << "\t Press 0 to EXIT to the Main Menu" << endl;
                    cout << "\n\t\t\t Please enter your choice: ";
                    cin >> this->inputChoice;
                    cout << endl;

                    switch (this->inputChoice)
                    {
                    case 0:
                        cout << "\t\t\t Thank you!" << endl << endl;
                        istrue = false;
                        break;
                    case 1:
                        this->userLogin();
                        break;
                    case 2:
                        this->userRegistration();
                        break;
                    case 3:
                        this->forgot();
                        break;

                    default:
                        cout << "\t\t\t Please select from the options given above" << endl << endl;
                        break;
                    }
                }
                break;
            case 2:
                istrue = true;
                while (istrue) {
                    cout << "\n Welcome!\n\n\n";
                    cout << "\t Press 1 to LOGIN as an ADMIN" << endl;
                    cout << "\t Press 2 to REGISTER as an Admin" << endl;
                    cout << "\t Press 3 if you are an Admin and forgot your Password" << endl;
                    cout << "\t Press 0 to EXIT to the Main Menu" << endl;
                    cout << "\n\t\t\t Please enter your choice: ";
                    cin >> this->inputChoice;
                    cout << endl;

                    switch (this->inputChoice)
                    {
                    case 0:
                        cout << "\t\t\t Thank you!" << endl << endl;
                        istrue = false;
                        break;
                    case 1:
                        isFalse = true;
                        while (isFalse) {
                            int a = 0;
                            cout << endl << "Enter the Admin Key:";
                            cin >> a;
                            if (CheckAdminId(a))
                            {
                                this->adminLogin();
                                isFalse = false;
                            }
                            else {
                                cout << endl << "The entered key is not correct. Again!";

                            }
                        }
                        break;
                    case 2:
                        isFalse = true;
                        while (isFalse) {
                            int a = 0;
                            cout << endl << "Enter the Admin Key:";
                            cin >> a;
                            if (CheckAdminId(a))
                            {
                                this->adminRegistration();
                                isFalse = false;
                            }
                            else {
                                cout << endl << "The entered key is not correct. Again!";

                            }
                        }
                        break;
                    case 3:
                        isFalse = true;
                        while (isFalse) {
                            int a = 0;
                            cout << endl << "Enter the Admin Key:";
                            cin >> a;
                            if (CheckAdminId(a))
                            {
                                this->Forgot();
                                isFalse = false;
                            }
                            else {
                                cout << endl << "The entered key is not correct. Again!";

                            }
                        }
                        break;

                    default:
                        cout << "\t\t\t Please select from the options given above" << endl << endl;
                        break;
                    }
                }
                break;
            default:
                cout << "\t\t\t Please select from the options given above" << endl << endl;
                break;
            }
        }

    }
};
