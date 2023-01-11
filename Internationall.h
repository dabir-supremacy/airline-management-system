#pragma once
#pragma once
#include <iostream>
#include<fstream>
#include<string.h>


using namespace std;

class int_booking// international class
{
protected://protected 
    int pnr_int;
    char fl_int[10], xint[7], yint[7];
    //long int doji;
    int departi, destini, choici;
public://public funcs
    int_booking() {}
    int_booking(int w, char r[10], char t[7], char y[7], int u, int o, int p) {

        pnr_int = w;
        fl_int[10] = 'r';
        xint[7] = 't';
        yint[7] = 'y';
        choici = u;
        departi = o;
        destini = p;
    }
    void int_pnr()
    {
        g++;//incrementing
        pnr_int = g;
    }

    int intj_info()// International journey details
    {
        // cout << "Enter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;;
         //cin >> doji;
        cout << "\1.Sweden(1) \2.Brazil(2) \3.Capetown(3) \4.Malaysia(4) \5.New Jersey(5) " << endl << endl;
        cout << "\nEnter Your Departure:" << endl;
        cin >> departi;
        cout << "\nEnter Your Destination:";
        cin >> destini;


        if ((departi == 1 && destini == 3) || (departi == 3 && destini == 1))//1st cond
        {
            cout << "\t \t \t Congrats Flights Found!!!" << endl << endl;
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.I-499(1)\t06:30\t\t10:30\t\tRs.200000\t\tRefundable\n";
            cout << "\2.I-499(2)\t12:30\t\t15:30\t\tRs.80000\t\tRefundable\n";
            cout << "\3.I-499(3)\t17:30\t\t20:45\t\tRs.103000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((departi == 1 && destini == 4) || (departi == 4 && destini == 1))//2nd cond
        {
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.I-499(1)\t06:30\t\t10:30\t\tRs.104000\t\tRefundable\n";
            cout << "\2.I-499(2)\t12:30\t\t15:30\t\tRs.54000\t\tRefundable\n";
            cout << "\3.I-499(3)\t17:30\t\t20:45\t\tRs.159000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((departi == 1 && destini == 5) || (departi == 5 || destini == 1))//3rd cond
        {
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.I-499(1)\t06:30\t\t10:30\t\tRs.109000\t\tRefundable\n";
            cout << "\2.I-499(2)\t12:30\t\t15:30\t\tRs.73000\t\tRefundable\n";
            cout << "\3.I-499(3)\t17:30\t\t20:45\t\tRs.174000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((departi == 2 && destini == 3) || (departi == 3 && destini == 2))//4th cond
        {
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.I-499(1)\t06:30\t\t10:30\t\tRs.14500\t\tRefundable\n";
            cout << "\2.I-499(2)\t12:30\t\t15:30\t\tRs.88000\t\tRefundable\n";
            cout << "\3.I-499(3)\t17:30\t\t20:45\t\tRs.101000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if ((departi == 2 && destini == 4) || (departi == 4 && destini == 2))//5th cond
        {
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.I-499(1)\t06:30\t\t10:30\t\tRs.60000\t\tRefundable\n";
            cout << "\2.I-499(2)\t12:30\t\t15:30\t\tRs.40000\t\tRefundable\n";
            cout << "\3.I-499(3)\t17:30\t\t20:45\t\tRs.180000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
        }

        else if (departi == 2 && destini == 5 || (departi == 5 && destini == 2))//6th cond
        {
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
            cout << "\n\nFlight No.:\tDeparture time:\tArrival time:\tCost:\t\tType:\n";
            cout << "\1.I-499(1)\t06:30\t\t10:30\t\tRs.90000\t\tRefundable\n";
            cout << "\2.I-499(2)\t12:30\t\t15:30\t\tRs.75000\t\tRefundable\n";
            cout << "\3.I-499(3)\t17:30\t\t20:45\t\tRs.120000\t\tRefundable\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";

        }
        else if (departi == destini)// as both can't be same
        {
            cout << " Sorry wrong input so.\nTry again\n\n\n" << endl;
            return intj_info();
        }
        else//other cond
        {
            cout << "Sorry Wrong input  so.\nTry again\n\n\n";
            return intj_info();
        }

    }

    int choose_flightint()// selecting flight international
    {
        cout << "\nEnter your choice" << endl;
        cin >> choici;
        switch (choici)//switch 
        {
        case 1://1st cond
            cout << "\nFlight selected:" << endl;
            cout << "I-499" << endl;
            strcpy_s(fl_int, "I-499");//copy to string
            cout << "Departure Time: 06:30" << endl;
            cout << "Arrival Time: 10:30" << endl;
            strcpy_s(xint, "06:30");//copy to string
            strcpy_s(yint, "10:30");//copy to string
            break;
        case 2://2nd csase
            cout << "\nFlight selected:" << endl;
            cout << "I-499" << endl;
            strcpy_s(fl_int, "I-499");//copy to string
            cout << "Departure Time: 12:30" << endl;
            cout << "Arrival Time: 15:30" << endl;
            strcpy_s(xint, "12:30");//copy to string
            strcpy_s(yint, "15:30");//copy to string
            break;
        case 3://3rd case
            cout << "\nFlight selected:" << endl;
            cout << "I-499" << endl;
            strcpy_s(fl_int, "I-499");//copy to string
            cout << "Departure Time : 17:30" << endl;
            cout << "Arrival Time: 20:45" << endl;
            strcpy_s(xint, "17:30");//copy to string
            strcpy_s(yint, "20:45");//copy to string
            break;
        default://4th cond
            cout << "Wrong input entered" << endl;
            return choose_flightint();
        }
    }
};