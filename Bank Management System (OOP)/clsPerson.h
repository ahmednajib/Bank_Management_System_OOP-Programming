#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        this->_FirstName = FirstName;
        this->_LastName = LastName;
        this->_Email = Email;
        this->_Phone = Phone;
    }

    void SetFirstName(string FirstName)
    {
        this->_FirstName = FirstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    void SetLastName(string LastName)
    {
        this->_LastName = LastName;
    }

    string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    void SetEmail(string Email)
    {
        this->_Email = Email;
    }

    string GetEmail()
    {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    void SetPhone(string Phone)
    {
        this->_Phone = Phone;
    }

    string GetPhone()
    {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }

};


