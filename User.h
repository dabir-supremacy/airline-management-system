#include<iostream>
#include<fstream>
#include<cstring>
#include<time.h>
#include"Payment.h"
using namespace std;
class user
{
private:
	long int CNIC = 0;
	char password[8];

public:
	user()
	{

		for (int i = 0; i < 8; i++)
		{
			password[i] = '0';
		}
		CNIC = 0;
	}

	user(int x, char a[8], long int s)
	{
		for (int i = 0; i < 8; i++)
		{
			password[i] = a[i];
		}
		CNIC = s;
	}

	user(long int CNIC, char password[8]) {
		this->CNIC = CNIC;
		for (int i = 0; i < 7; i++)
		{
			this->password[i] = password[i];
		}
	}

	void setCNIC(long int CNIC)
	{
		this->CNIC = CNIC;
	}

	void setpassword(char password[8]) {
		this->password[7] = password[7];
	}

	long int getCNIC() {
		return this->CNIC;
	}

	char getpassword() {
		return this->password[7];
	}

	void storing_person(user U)
	{
		ofstream file;
		file.open("User_data.dat", ios::app | ios::out | ios::in | ios::binary);
		file.write(reinterpret_cast<char*>(&U), sizeof(U));
		file.close();
	}

	bool search_user(char password[8])
	{
		user check;
		ifstream check1;
		check1.open("User_data.dat", ios::binary);
		check1.read(reinterpret_cast<char*>(&check), sizeof(check));

		bool valid = false;

		char arr[20] = { check.getpassword() };

		string pass = "";
		for (int i = 0; i < 20; i++) {
			pass = pass + arr[i];
		};

		while (!check1.eof()) {

			if (pass == password)
			{
				cout << "You are already registered" << endl;
				valid = true;
				cout << endl;
				check.Print_data();
				cout << endl;
				break;
				return 1;
			}
			else
			{
				valid = false;
				check1.read(reinterpret_cast<char*>(&check), sizeof(check1));
				return 0;
			}
			cout << endl;
		}
	}
	void Print_data() {
		cout << "Password is: " << this->password << endl;
		cout << "CNIC is: " << this->CNIC << endl;
	}
	bool Password_check(char password[8]) {  //to check if the password is stored in the file
		if (strlen(password) != 8)
		{
			return false;
		}
		else
		{
			int digits = 0;
			int charac = 0;
			int small = 0;
			int capital = 0;
			for (int i = 0; i < 8; i++)
			{
				if (isdigit(password[i]))
				{
					digits++;
				}

				if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9')))
				{
					charac++;
				}

				if ((password[i] >= 'a' && password[i] <= 'z'))
				{
					small++;
				}

				if (password[i] >= 'A' && password[i] <= 'Z')
				{
					capital++;
				}
			}

			if (digits >= 1 && charac >= 1 && small >= 1 && capital >= 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	bool CNIC_valid(long int cnic) {                      //check if the CNIC entered is valid
		if (cnic >= 1000000000000 && cnic <= 9999999999999)
		{
			user check;
			ifstream check1;
			check1.open("User_data.dat", ios::binary);
			check1.read(reinterpret_cast<char*>(&check), sizeof(check));
			while (!check1.eof())
			{
				if (check.CNIC == cnic)
				{
					cout << "CNIC has already been used" << endl;
					cout << "If already registered, Kindly login" << endl;
					cout << endl;
					return false;
					break;
				}
				else
				{
					check1.read(reinterpret_cast<char*>(&check), sizeof(check));
				}
				cout << endl;
			}
			return true;
		}
		else
		{
			cout << "CNIC should be of 13 digits" << endl;
			return false;
		}
	}
};
