#pragma once
#include<iostream>
using namespace std;
#include<iostream>
#include<fstream>
#include"Employee.h"
using namespace std;
class MedicalStaff :public employee
{
protected:
    int id;
public:
    MedicalStaff()
    {
        id = 0;
        employee_type = "Medics";
    }
    MedicalStaff(int a, string b)
    {
        id = a;
        employee_type = b;
    }
    void set_Staff_id(int a)
    {
        id = a;
    }
    int get_staff_id()
    {
        return id;
    }
    virtual void display_info()
    {
        cout << "The id of the AMADEUS ALTEA SUITE medical staff w: \t " << id << endl;
    }
    void Add_med(MedicalStaff obj)
    {
        obj.get_employee_type();
        obj.get_staff_id();
        ofstream out_f("emergency.dat", ios::binary | ios::app);            //write record in file
        out_f.write((char*)&obj, sizeof(obj));
        out_f.close();
    }
    void show()
    {
        cout << "Type: " << employee_type << endl;
        cout << "ID: " << id << endl;
    }
    void read_med(MedicalStaff obj)
    {
        ifstream in_f("emergency.dat", ios::binary);            //read file

        while (!in_f.eof()) {
            in_f.read((char*)&obj, sizeof(obj));
            cout << "Type: " << obj.employee_type << endl;
            cout << "Level: " << obj.id << endl;
        }
        obj.show();
    }

};
class Doctor : public MedicalStaff
{
private:
    int pmdcNumber, working_experience;
public:
    Doctor()
    {
        pmdcNumber = 12345;
        working_experience = 0;
        id = 0;
        employee_type = "Doctor";
    }
    Doctor(int a, int b)
    {
        pmdcNumber = a;
        working_experience = b;
        employee_type = "Doctor";

    }
    void set_pmdc(int a)
    {
        pmdcNumber = a;
    }
    int get_pmdc()
    {
        return pmdcNumber;
    }
    void set_workingExperience(int a)
    {
        working_experience = a;
        if (a > 5)
        {
            cout << "\n Experienced doctor :)";
        }
        else if (a < 5)
        {
            cout << "\n Quack Doctor :(";
        }
    }
    int get_working_experience()
    {
        return working_experience;
    }

    void display_info()
    {
        cout << "The PMDC number: " << pmdcNumber << endl;
        cout << "The working experience: " << working_experience << endl;
        cout << "Type : " << employee_type << endl;
        cout << "Staff id: " << id << endl;

    }
};

