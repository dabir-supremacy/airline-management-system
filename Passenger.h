#include <iostream>
#include"Domestic.h"
#include"Internationall.h"
#include"ECL.h"
#include"Covidd.h"
#include"Boardingg.h"
#include<fstream>
#include<string.h>
#include<string>
using namespace std;
class passenger : public domestic_booking, public int_booking //  Inheritance
{
private://private 
    char fs_nam[20], ls_nam[20]; //email[50];
    int age, gender;
    long int ct_no;
    int x, y;
    string f, b;
public://public funcs
    covid_testing cov;
    boarding board;
    ecl sec;
    void CompMenu() {

        cout << "\n\1.Press for Covid testing info (1)" << endl;
        cout << "\2.Press for Security info (2)" << endl;
        cout << "\3.Press for Boarding info (3)" << endl;
        cout << "Enter your choice:" << endl;
        cin >> x;
        switch (x) {
        case 1:
            cout << "For checking Covid result" << endl;;
            cov.set_result();
            break;
        case 2:
            cout << "\n\n\t What do you want to do? \n\1.Adding ECL(1)\2.Checking ECL(2)\3.modifying ECL(3) " << endl << endl;
            cout << "Enter your choice:" << endl;
            cin >> y;
            switch (y) {
            case 1:
                cout << "Adding ECL" << endl;
                sec.add_ECL_record(sec);
                break;
            case 2:
                cout << "Checking ECL" << endl << endl;
                cout << "Enter ECL member's CNIC:" << endl;
                std::getline(cin, b);
                sec.ECL_check(b);
                break;

            case 3:
                cout << "Modifying ECL" << endl << endl;
                cout << "Enter ECL member's CNIC:" << endl;
                std::getline(cin, b);
                cout << "Enter ECL member's Status:" << endl;
                std::getline(cin, f);
                sec.modify_ECL_status(b, f);
                break;
            default:
                cout << "Wrong input" << endl;
                break;
            }
            break;
        case 3:
            cout << "For Checking your Baggage limit" << endl << endl;
            board.baggage_limit();
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
    passenger() {

    }
    passenger(char s[20], char d[20], int ag, int gen, long int contact) {
        fs_nam[20] = s[20];
        ls_nam[20] = d[20];
        int age = ag;
        gender = gen;
        ct_no = contact;
    }
    void p_detail(int x)//function
    {
        if (x == 1)// for domestic and international selection
        {
            dj_info();//func calling
            choose_flight();//funct calling
        }
        else
        {
            intj_info();//function calling
            choose_flightint();//function calling
        }
        cout << "\n\n\nPlease Enter Passenger Specific Information";
        cout << "\n\nYour First Name:";
        cin >> fs_nam;
        cout << "Your Last Name:";
        cin >> ls_nam;
    }
    int gend_verf()//checking gender 
    {
        cout << "\nGender:\nIf Male so press(1)\nIf Female so press(2):";
        cin >> gender;
        if (gender > 2)//cond
        {
            cout << "\n\nSorry Wrong input so.\nTry again\n\n" << endl;
            return gend_verf();//funct calling
        }
    }
    void more_info_required()//taking more details of  passeng
    {
        cout << " Your Age:";
        cin >> age;
        /**cout << "Email Id:";
        cin >> email;*/
        cout << "Your Contact no.( please enter 6 digits ):";
        cin >> ct_no;
        cout << "\n\nDetails Mentioned :\n";
        cout << "Your Name:" << fs_nam << " " << ls_nam << endl;
        cout << "Your Gender:" << gender << endl;      //displaying info
        cout << "Your Age:" << age << endl;
        /*cout << "Email id:" << email << endl;*/
        cout << "Your Cellphone No.:" << ct_no << endl;
    }


    int getpnr()// geting func for domestic flight
    {
        return pnr_dm;
    }

    int getpnri()// getting func for international flight
    {
        return pnr_int;
    }

    void disp_dm()//function for showing details for passenger's domestic 
    {
        cout << "\n\nYour PNR No.:" << pnr_dm << endl;
        cout << "Your Flight No.:" << fl_dm << endl;
        cout << "Your Good Name:" << fs_nam << " " << ls_nam << endl;
        //cout << "DOJ:" << doj << endl;
        cout << "Your Departure Time:" << xd << endl;
        cout << "Your Arrival Time:" << yd << endl;
    }

    void disp_int()//function for showing details for international 
    {
        cout << "\n\nYour PNR No.:" << pnr_int << endl;
        cout << "Your Flight No.:" << fl_int << endl;
        cout << "Your GoodName:" << fs_nam << " " << ls_nam << endl;

        // cout << "DOJ:" << doji << endl;
        cout << "Your Departure Time:" << xint << endl;
        cout << "Your Arrival Time:" << yint << endl;
    }
};


