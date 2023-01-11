/*Compiled By Muhammad Talha Syed, i210277, AI-J
Basic Implementation Algorithm elaboration:
This class works on the basis of simple CHATBOT implementation modified to meet the needs our Projet. The is as follows:
1. The program will display a Menu for the user to access various options
2. Through conditional statements specific functions for a specific option
3. There is another menu for Admin navigation.
Aforementioned was the overview.
Towards the speciality of the program:
    - There are 5 things of significance in this class
            1. Reading and Writing complaints
            2. Reading and Writing suggestions
            3. Reading and Writing remarks/compliments
            4. Giving access to Admin
            5. Navigating through the weather menu.*/



#pragma once
#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>
#include"admin.h"
#include"weather.h"
using namespace std;
class customer_services {
protected:
    admin obj_admin;//object from admin class to get the login() function
    int x=0;//comparison variable
    string suggestion[100];//suggestion array
    string complaint[100];//complaint array
    string compliments[100];//remarks array
    string complain;//complain variable to get complaint
    string suggest;//variable to get suggestion
    string comply;// variale to get remarks
    int y=0;//comparison variable
    string a;//option sleector
    weather obj;//object for the weather class menu
    int c_number = 999+rand() % 999999;//random set variables
    int com_number = 999+rand() % 999999;//for complaint number,
    int feed_number = 999+rand() % 999999;// suggestion number and user number
public:

    
    //FIRST DESIGNED INTERFACE, WELCOME PAGE
    void display_screen() {
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                               Welcome Amadeus Altea Suite                                |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                Customer Services Section!                                |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << "|                                                                                          |" << endl;
        cout << " ------------------------------------------------------------------------------------------" << endl;
        cout << "Continue, enter 'go'" << endl;
        cin >> a;//continues program 
        if (a == "go") {
            menu();//menu function declared below
        }
        else {
            cout << "Wrong input, terminated";// any other input then "go" terminatess the program
        }
    }//SECOND DESIGNED INTERFACE, FOR USER NAVIGATION
    void menu() {
        cout << "            |  Select one of the following options:    |" << endl;
        cout << "            |                                          |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         For complaints press 1           |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         For suggestions press 2          |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         For compliments  press 3         |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         For admin login  press 4         |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         For weather details press 5      |" << endl;
        cout << "            | --------------------------------------   |" << endl;

        cin >> x;//selector input
        if (x == 1) {
            write_complain();//writer function for complaints
            cout << "Thank you for your complain, you complaint number is: " << c_number << endl;
            if (c_number < 10000 && c_number>11000)//You just won a free trip to Hawaii!
            {
                cout << "Congratulations! You have earned our special number! Which is " << c_number << "!" << endl << "You are now given a free flight to Hawaii!" << endl;
            }
            
        }
        else if(x==2)
        {
            write_suggestion();//writer function for suggestion
            cout << "Thank you for suggesting improvements, your feedback number is: " << com_number << endl;
            if (com_number < 10000 && com_number>11000)//You just won a free trip to Abu Dhabi!
            {
                cout << "Congratulations! You have earned our special number! Which is " << com_number << "!" << endl << "You are now given a free flight to Abu Dhabi!" << endl;
            }
        }
        else if(x==3) {
            write_compliment();//writer function for remarks
            cout << "Thank you for your remarks, your customer number is: " << feed_number << endl;
            if (feed_number < 10000 && feed_number>11000)//You just won a free trip to Qatar!
            {
                cout << "Congratulations! You have earned our special number! Which is " << feed_number << "!" << endl << "You are now given a free flight to Qatar!" << endl;
            }
        }
        else if (x == 4)//option for the admin login screen
        {
            obj_admin.login();
            showcase_menu();
        }
        else if (x == 5)//option 5 to go to the weather menu
        {
            obj.open_menu();
        }

    }
    void showcase_menu()//THIRD DESIGNED INTERFACE, FOR THE ADMIN
    {
        cout << "            |  Select one of the following options:    |" << endl;
        cout << "            |                                          |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         Press 1 to read complaints       |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         Press 2 to read suggestions      |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cout << "            |         Press 3 to read compliments      |" << endl;
        cout << "            | --------------------------------------   |" << endl;
        cin >> y;
        if (y == 1) {

            read_complain();//complaint reader function
        }
        else if (y == 2) {

            read_suggestions();//suggestion reader function
        }
        else if (y == 3) {

            read_compliments();// remark reader function
        }



    }


//WRITER FUNCTIONS DEFINITIONS  
    void write_complain()
    {
        this->complain = complain;
        cout << "Enter complain: " << endl;
        getline(cin, complain);
        complain = *complaint;
        cin.ignore();
        ofstream outfile("complaint.dat", ios::binary);
        outfile.write(reinterpret_cast<char*>(complaint), sizeof(int));
        

    }
    
    void write_suggestion() {
        this->suggest = suggest;
        cout << "Enter Suggestion: " << endl;
        getline(cin, suggest);
        suggest = *suggestion;
        cin.ignore();
        ofstream outfile("suggestion.dat", ios::binary);
        outfile.write(reinterpret_cast<char*>(suggestion), sizeof(int));
    }
 
    void write_compliment()
    {
        this->comply = comply;
        cout << "Enter compliments: " << endl;
        getline(cin, comply);
        comply = *compliments;
        cin.ignore();
        ofstream outfile("compliment.dat", ios::binary);
        outfile.write(reinterpret_cast<char*>(compliments), sizeof(int));

    }


    //DISPLAYER FUNCTION FOR COMPLAINT
    void show_complain() {
        cout << "Complain: " << *complaint << "." << endl;
    }
    //READER FUNCTION FOR COMPLAINT
    void read_complain() {

        ifstream infile("complian.dat", ios::binary);
        infile.read(reinterpret_cast<char*>(complaint), sizeof(int));
        show_complain();

    }
    //DISPLAYER FUNCTION FOR SUGGESTION
    void show_suggestion() {
        cout << "Suggestion: " << *suggestion << "." << endl;

    }
    //READER FUNCTION FOR SUGGESTION
    void read_suggestions() {

        ifstream infile("suggestion.dat", ios::binary);
        infile.read(reinterpret_cast<char*>(suggestion), sizeof(int));
        show_suggestion();
    }
    //DISPLAYER FUNCTION FOR REMARKS 
    void show_comply() {
        cout << "Compliments: " << *compliments << "." << endl;
    }
    //READER FUNCTION FOR REMARKS
    void read_compliments() {

        ifstream infile("compliment.dat", ios::binary);
        infile.read(reinterpret_cast<char*>(compliments), sizeof(int));
        show_comply();
    }





    
};
