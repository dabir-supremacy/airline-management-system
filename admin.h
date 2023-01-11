/*COMPILED BY MUHAMMAD TALHA SYED,i210277, AI-J
THIS CLASS FOCUSES ON ADMIN LOGIN FUNCTIONALITY*/







#pragma once
#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include"customer_services.h"
using namespace std;

class admin{
protected:
    string userName;//USER NAME
    string userPassword;//USER PASSWROD
    int loginAttempt = 0;//LOGIN ATTEMPTS
    int x;// SELECTOR VARIABLE
    
    
public:
    //login function
    void login() {


        while (loginAttempt < 5)
        {//gets credentials here
            cout << "Please enter your user name: ";
            cin >> userName;
            cout << "Please enter your user password: ";
            cin >> userPassword;
           
            
            //checks for correct name and password
            if (userName == "Admin" && userPassword == "admin")
            {
                cout << "Welcome Admin!\n";
                break;
            }

            else
            {
                cout << "Invalid login attempt. Please try again.\n" << '\n';
                loginAttempt++;
            }
        }//number of login attempts: 5
        if (loginAttempt == 5)
        {
            cout << "Too many invalid login attempts! The program will now terminate.";

        }

        cout << "Thank you for logging in.\n";
    }
    
    

    };



