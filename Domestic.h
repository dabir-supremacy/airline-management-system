#pragma once
#include <iostream>
#include<fstream>
#include<string.h>



using namespace std;

int gl = 0; //globs
int g = 20;

class domestic_booking // domestic class
{
protected:
    int pnr_dm;
    char fl_dm[10], xd[7], yd[7]; //protected variables
    //long int doj;
    int choice_b, depart, destin;
public://public functions
    domestic_booking() {

    }
    domestic_booking(int p, char c[10], char d[7], char e[7], int f, int g, int h) {
        pnr_dm = p;
        fl_dm[10] = 'c';
        xd[7] = 'd';
        yd[7] = 'e';
        choice_b = f;
        depart = g;
        destin = h;

    }
    void domestic_pnr()
    {
        gl++; // incrementing global
        pnr_dm = gl;
    }
    int dj_info() // function for domestic journey
    {
        /*cout << "\nEnter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;
        cin >> doj;*/
        cout << "\1.Lahore(1) \t\2.Islamabad(2) \t\3.Sialkot(3) \t\4.Karachi(4)" << endl << endl;
        cout << "\tEnter Your Departure:" << endl;
        cin >> depart;
        cout << "\tEnter Your Destination:" << endl;
        cin >> destin;
        if ((depart == 1 && destin == 2) || (depart == 2 && destin == 1))// 1st cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.F-899(1)\t09:00\t\t12:00\t\tRs.100000\t\tRefundable\n";
            cout << "\2.F-899(2)\t15:00\t\t18:00\t\tRs.102000\t\tRefundable\n";
            cout << "\3.F-899(3)\t21:00\t\t23:00\t\tRs.45000\t\tRefundable\n\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((depart == 1 && destin == 3) || (depart == 3 && destin == 1))// 2nd cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.F-899(1)\t09:00\t\t12:00\t\tRs.187000\t\tRefundable\n";
            cout << "\2.F-899(2)\t15:00\t\t18:00\t\tRs.50900\t\tRefundable\n";
            cout << "\3.F-899(3)\t21:00\t\t23:00\t\tRs.124000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((depart == 1 && destin == 4) || (depart == 4 && destin == 1))//3rd cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.F-899(1)\t09:00\t\t12:00\t\tRs.180000\t\tRefundable\n";
            cout << "\2.F-899(2)\t15:00\t\t18:00\t\tRs.120000\t\tRefundable\n";
            cout << "\3.F-899(3)\t21:00\t\t23:00\t\tRs.59500\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((depart == 2 && destin == 3) || (depart == 3 && destin == 2))// 4th cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.F-899(1)\t09:00\t\t12:00\t\tRs.78000\t\tRefundable\n";
            cout << "\2.F-899(2)\t15:00\t\t18:00\t\tRs.98000\t\tRefundable\n";
            cout << "\3.F-899(3)\t21:00\t\t23:00\t\tRs.45000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((depart == 2 && destin == 4) || (depart == 4 && destin == 2))// 5th cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.F-899(1)\t09:00\t\t12:00\t\tRs.78000\t\tRefundable\n";
            cout << "\2.F-899(2)\t15:00\t\t18:00\t\tRs.40000\t\tRefundable\n";
            cout << "\3.F-899(3)\t21:00\t\t23:00\t\tRs.99000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }
        else if ((depart == 3 && destin == 4) || (depart == 4 && destin == 3))//6th cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.F-899(1)\t09:00\t\t12:00\t\tRs.18000\t\tRefundable\n";
            cout << "\2.F-899(2)\t15:00\t\t18:00\t\tRs.50000\t\tRefundable\n";
            cout << "\3.F-899(3)\t21:00\t\t23:00\t\tRs.100000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }
        else if (depart == destin)// Because both can't be same
        {
            cout << "\nDeparture and destination can't match so.\nTry again\n\n\n" << endl;
            return dj_info();
        }
        else
        {
            cout << "\nWrong input \nTry again\n\n\n" << endl;
            return dj_info();
        }

    }

    int  choose_flight() // choosing domestic flight
    {
        cout << "\n\nEnter your choice:" << endl;
        cin >> choice_b;
        switch (choice_b) // switch case
        {
        case 1://case1


            cout << "\nFlight selected: F-899" << endl;
            strcpy_s(fl_dm, "F-899");//copy to string
            cout << "Departure Time : 09:00" << endl;
            cout << "Arrival Time: 12:00" << endl;
            strcpy_s(xd, "9:00"); //copy to string
            strcpy_s(yd, "12:00");// copy to string
            break;
        case 2://case 2
            cout << "\nFlight selected:" << endl;
            cout << "F-899" << endl;
            strcpy_s(fl_dm, "F-899");//copy to string
            cout << "Departure Time : 15:00" << endl;
            cout << "Arrival Time: 18:00" << endl;
            strcpy_s(xd, "15:00");//copy to string
            strcpy_s(yd, "18:00");//copy to string
            break;
        case 3://case3
            cout << "\nFlight selected:" << endl;
            cout << "F-899" << endl;
            strcpy_s(fl_dm, "F-899");//copy to string
            cout << "Departure Time : 21:00" << endl;
            cout << "Arrival Time: 23:00" << endl;
            strcpy_s(xd, "21:00");//copy to string
            strcpy_s(yd, "23:00");//copy to string
            break;
        default://case4
            cout << " Sorry, Wrong input so.\nTry again" << endl;
            return choose_flight();
        }
    }
};
