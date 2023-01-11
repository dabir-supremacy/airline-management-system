#pragma once
#include <iostream>
using namespace std;
#include<fstream>
#include"Passenger.h"
#include"Payment.h"
#include<string.h>

class payment//payment class
{
protected://protected vars
    long
        int choice_a, b, c, d, cvv, us_id; // variables for bank,card,date and user id
    char pass[10];

public://public funcs
    payment() {
    }
    payment(long int a, long int w, long int n, long int m, long int l, long int t, char pas[10]) {
        choice_a = a;
        b = w,
            c = n;
        d = m;
        cvv = l;
        us_id = t;
        pass[10] = pas[10];

    }
    void payment_detals()//func for payment 
    {
        cout << "\n\n\nWhich method you would like to pay with?:\n";
        cout << "\n\1.Debit Card(1) \n\2.Credit Card(2) \n\3.Net Banking(3)";
        cout << "\n\nPlease enter your desired option: ";
        cin >> choice_a;
        switch (choice_a)//Alternative of IF statement
        {
        case 1://1st cond
            cout << "\nEnter your card no.:";
            cin >> c;
            cout << "Enter Your card's expiry date:";
            cin >> d;
            cout << "Enter your CVV no.:";
            cin >> cvv;
            cout << "\nCongrats Transaction Done!\n" << endl;
            break;
        case 2://2nd cond
            cout << "\nEnter your card no.:";
            cin >> c;
            cout << "Enter your card's expiry date:";
            cin >> d;
            cout << "Enter your password:";
            cin >> pass;
            cout << "\nCongrats Transaction done!\n" << endl;
            break;
        case 3://case 3
            cout << "Banks Available: \1.JS Bank(1) \2.HBL Bank(2) \3.Allied Bank(3) \4.Silk Bank(4) \5.Or Others(5)" << endl;
            cout << "\nPlease Select your bank:";
            cin >> b;
            cout << "\nYou have chosen:" << b;
            cout << "\nEnter your user id:";
            cin >> us_id;
            cout << "Enter your password:";
            cin >> pass;
            cout << "\nCongrats Transaction done!\n" << endl;
            break;
        default:// false input
            cout << "\nSorry Wrong input so.\nTry again\n\n";
            return payment_detals();
        }
    }
    void MEMBERSHIP() { // MEMBERSHIP FUNCTION
        int No_of_flights = 0;
        srand(time(0));
        No_of_flights = (rand() % (35 - 5 + 1) + 5);
        if (No_of_flights >= 0 && No_of_flights <= 5) {// no discount
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;
            cout << "\t Sorry You can't avail any of the membership (discount)" << endl << endl;
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
        }
        else if (No_of_flights >= 6 && No_of_flights <= 15) { // discount for gold

            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;
            cout << "\t Congrats You can avail Gold Membership (Avail 15% discount)" << endl << endl;
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
        }
        else if (No_of_flights >= 16 && No_of_flights <= 25) {// dicount for bronze
            cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;;
            cout << "\t  Congrats You can avail Bronze Membership (Avail 25% discount)" << endl << endl;
            cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";

        }
        else // discount for platinum
            cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
        cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;
        cout << "\t  Congrats You lie in Platinum Membership (Avail 35% discount)" << endl << endl;
        cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
        cout << "\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    }

};

// Now Binary files
void creatfil(passenger p)//file - domestic booking
{
    ofstream fin("domestic.txt", ios::binary | ios::app);
    fin.write((char*)&p, sizeof(p));//writing in file
    fin.close();//close file
}

void cancel_domesticticket(int a)//canceletaion ticket
{
    passenger p;
    int ff = 0;
    ifstream fout("domestic.txt", ios::binary | ios::app);//reading file
    ofstream fin("domestic1.txt", ios::binary | ios::app);//writing to a new file
    fout.read((char*)&p, sizeof(p));//reading file
    while (fout)
    {
        if (p.getpnr() != a)//check pnr
            fin.write((char*)&p, sizeof(p));//writing to file
        else
        {
            p.disp_dm();//show domestic details
            cout << "\nSadly Your Above ticket is canceled now:\n" << "Amount refunded: $100\n";
            ff++;//increment only when pnr is found
        }
        fout.read((char*)&p, sizeof(p));//reading another record from file
    }
    if (ff == 0) {//,pnr not found
        cout << "Ticket has not not found\n";
    }
    fout.close();//closing file
    fin.close();//closing file
    remove("domestic.txt");//deleting previous file
    rename("domestic1.txt", "domestic.txt");//renaming brand new file

}

void checkticket_dm(int b)//function to check pnr or ticket
{
    passenger p;
    int fff = 0;
    ifstream fout("domestic.txt", ios::binary);//opening file
    fout.read((char*)&p, sizeof(p));//reading file
    while (fout)
    {
        if (p.getpnr() == b)//checking pnr
        {
            p.disp_int();//display details
            cout << "\nYour ticket is:" << endl;
            fff++;//incrementing f if onr found
            break;
        }
        fout.read((char*)&p, sizeof(p));//reading another record from the same file

    }
    fout.close();//close file
    if (fff == 0)// pnr not found
        cout << "Sadly Your Ticket has not been found" << endl;

}
void createfilei(passenger p)//opening for international booking
{
    ofstream fin("international.txt", ios::binary | ios::app);
    fin.write((char*)&p, sizeof(p));//writing to file
    fin.close();//closing file
}
void cancel_intticket(int s)//func for canceletion ticket
{
    passenger p;
    int aa = 0;
    ifstream fout("international.txt", ios::binary | ios::app);//opening file
    ofstream fin("international1.txt", ios::binary | ios::app);//writing to a new file
    fout.read((char*)&p, sizeof(p));//read previous file
    while (fout)
    {
        if (p.getpnri() != s)//check pnr
            fin.write((char*)&p, sizeof(p));//writing to new file;
        else
        {
            p.disp_int();//showing details
            cout << "Your Above ticket is being deleted:\n" << "Amount refunded: Rs.20000\n";
            aa++;//incrementing if pnr found
        }
        fout.read((char*)&p, sizeof(p));//reading another record from previous file
    }
    if (aa == 0)//if f==0,pnr not found
        cout << "\nSadly your Ticket has not been found\n";
    fout.close();//close file
    fin.close();//close file
    remove("international.txt");//deleting old file
    rename("international1.txt", "international.txt");//renaming new file

}
void checkticket_int(int b)//function to check pnr / ticket
{
    passenger p;
    int fff = 0;
    ifstream fout("international.txt", ios::binary);//open file
    fout.read((char*)&p, sizeof(p));//read file
    while (fout)
    {
        if (p.getpnr() == b)//checking pnr
        {
            p.disp_int();//display details
            cout << "\nYour ticket is:" << endl;
            fff++;//incrementing f if onr found
            break;
        }
        fout.read((char*)&p, sizeof(p));//reading another record from the same file

    }
    fout.close();//close file
    if (fff == 0)//, pnr not found
        cout << "Sadly your Ticket has not been found" << endl;

}
