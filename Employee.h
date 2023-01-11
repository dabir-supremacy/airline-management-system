#pragma once
#include <string>
#include"User.h"
#include <iostream>
using namespace std;
class employee: public user          //abstract class
{
protected:
	string employee_type;
public:
	employee()
	{
		employee_type = "blank";
	}
	employee(string n)
	{
		employee_type = n;
	}

	void settype(string n)
	{
		employee_type = n;
	}
	string get_employee_type()
	{
		return employee_type;
	}

	virtual void display_info() = 0;
};