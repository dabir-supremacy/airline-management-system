#pragma once
#include<iostream>
using namespace std;
class Crew_members :public employee         //inheritance
{
private:
	string name;
	string idNumber;
	string department;
	string position;
	int yearsWorked;

public:
	Crew_members(string n, string idNum, string depart, string pos, int yrsWrkd)
	{
		name = n;
		idNumber = idNum;
		department = depart;
		position = pos;
		yearsWorked = yrsWrkd;
	}
	Crew_members()
	{
		name = "";
		idNumber = "";
		department = "";
		position = "";
		yearsWorked = 0;
	}

	void setName(string n)
	{
		name = n;
	}
	void setIdnumber(string idNum)
	{
		idNumber = idNum;
	}
	void setDepartment(string depart)
	{
		department = depart;
	}
	void setPos(string pos)
	{
		position = pos;
	}
	void setYEARS(int yrsWrkd)
	{
		yearsWorked = yrsWrkd;
		if (yearsWorked < 0)
		{
			yearsWorked = 0;
		}
	}
	void display_info()
	{
		cout << "\n Name:" << name << endl << "\n Id:" << idNumber << endl << "\n Department: " << department << endl << "\n Position: " << position << endl << "\n Years worked: " << yearsWorked << endl;
	}

	string const getName()
	{
		return name;
	}
	string const getID()
	{
		return idNumber;
	}
	string const getDPT()
	{
		return department;
	}
	string const getPOS()
	{
		return position;
	}
	int const getYEARS()
	{
		return yearsWorked;
	}
};