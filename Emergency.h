#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Emergency_Alert
{
private:
	int type, level, c;
	string location, instruction;
public:
	Emergency_Alert()
	{
		type = 0;
		level = 0;
		location = "Islamabad";
		instruction = "NULL";
	}
	Emergency_Alert(int a, int b, string c)
	{
		type = a;
		level = b;
		location = "ISLAMABAD1";
	}
	void Set_emergenvy_Type(int a)
	{
		type = a;
	}
	int get_emergency_type()
	{
		return type;
	}
	void set_level(int b)
	{

		cout << "\n Based on the type select a level that defines your situation";

		if (b == 1)
		{
			cout << "\n You have choosen Plane emergency:\n To specify the value make the selection from the given menu!\n \"1\" for Empty Feul Tank \n \"2\" for Engine failure \n \"3\" for wing fire \n \"4\" for engine fire ";
			cin >> c;
			if (c == 1)
			{
				level = 1; //normal level
			}
			else if (c == 2)
			{
				level = 2;
			}
			else if (c == 3)
			{
				level = 3;
			}
			else if (c == 4)
			{
				level = 4;
			}
			else
			{
				cout << "\n Invalid choice!! assigning 0 to level ";
				level = 0;
			}
		}
		else if (b == 2)
		{
			cout << "\n You have choosen Weather emergency:\n To specify the value make the selection from the given menu!\n \"1\" for Rain \n \"2\" for Thunderstorm \n \"3\" for cyclone \n \"4\" for other ";
			cin >> c;
			if (c == 1)
			{
				level = 2; //normal level
			}
			else if (c == 2)
			{
				level = 3;
			}
			else if (c == 3)
			{
				level = 4;
			}
			else if (c == 4)
			{
				level = 1;
			}
			else
			{
				cout << "\n Invalid choice!! assigning 0 to level ";
				level = 0;
			}
		}
		else if (b == 3)
		{
			cout << "\n You have choosen Health emergency:\n To specify the value make the selection from the given menu!\n \"1\" for Low blood pressure/ sugar level \n \"2\" for Vomiting \n \"3\" faint \n \"4\" for Heart attack/stabbed  ";
			cin >> c;
			if (c == 1)
			{
				level = 1; //normal level
			}
			else if (c == 2)
			{
				level = 2;
			}
			else if (c == 3)
			{
				level = 3;
			}
			else if (c == 4)
			{
				level = 4;
			}
			else
			{
				cout << "\n Invalid choice!! assigning 0 to level ";
				level = 0;
			}
		}
		else if (b == 4)
		{
			cout << "\n You have choosen Hijack related emergency:\n To specify the value make the selection from the given menu!\n \"1\" one troubling individual \n \"2\" for weapon display/violent behaviour  \n \"3\" Hijack \n \"4\" massacre ";
			cin >> c;
			if (c == 1)
			{
				level = 1; //normal level
			}
			else if (c == 2)
			{
				level = 2;
			}
			else if (c == 3)
			{
				level = 3;
			}
			else if (c == 4)
			{
				level = 4;
			}
			else
			{
				cout << "\n Invalid choice!! assigning 0 to level ";
				level = 0;
			}
		}
	}
	int get_emergency_level()
	{
		return level;
	}
	void set_location(string a)
	{
		location = "Islamabad";
	}
	string get_location()
	{
		return location;
	}
	void course_of_action()
	{
		int a = get_emergency_type();
		int b = get_emergency_level();
		string c = get_location();
		if (type == 1 && level == 1)
		{
			instruction = "\nContact control centre!!\a!";

		}
		else if (type == 1 && level == 2)
		{
			instruction = "\nContact control centre and admin!!!!!\a!";

		}
		else if (type == 1 && level == 3)
		{
			instruction = "\nContact airport fire department!!!! \a!";

		}
		else if (type == 1 && level == 4)
		{
			instruction = "\nContact airport fire department \a!";

		}



		else if (type == 2 && level == 1)
		{
			instruction = "\nContact admin to inform \a!";

		}
		else if (type == 2 && level == 2)
		{
			instruction = "\nContact weather !!!!\a!";

		}
		else if (type == 2 && level == 3)
		{
			instruction = "\nContact airport nearby for emergency landing!!!! \a!";

		}
		else if (type == 2 && level == 4)
		{
			instruction = "\nContact admin!!!contact Weather \a!";

		}

		else if (type == 3 && level == 1)
		{
			instruction = "\nContact crew members/kitchen staff \a!";

		}
		else if (type == 3 && level == 2)
		{
			instruction = "\nContact crew members/ contact cleaners  \a!";

		}
		else if (type == 3 && level == 3)
		{
			instruction = "\nContact medics !!!!! \a!";

		}
		else if (type == 3 && level == 4)
		{
			instruction = "\nContact hospital!!! contact nearby airport!!! contact air ambulance!!!!!\a!";

		}





		else if (type == 4 && level == 1)
		{
			instruction = "\nContact Pilot!! \a!";

		}
		else if (type == 4 && level == 2)
		{
			instruction = "\nContact security!!!!\a!";

		}
		else if (type == 4 && level == 3)
		{
			instruction = "\nContact control centre!!! contact FIA !!! contact Police!!!!\a!";

		}
		else if (type == 4 && level == 4)
		{
			instruction = "\nContact nearby airport !!! land urgently !!!! land urgently!!!! \a!";

		}
	}
	friend ostream& operator<< (ostream& out, Emergency_Alert& obj);

	void Add_emergency(Emergency_Alert obj)
	{
		obj.get_emergency_level();
		obj.get_emergency_type();
		obj.get_location();
		ofstream out_f("emergency.dat", ios::binary | ios::app);            //write record in file
		out_f.write((char*)&obj, sizeof(obj));
		out_f.close();
	}
	void show()
	{
		cout << "Type: " << type << endl;
		cout << "Level: " << level << endl;
		cout << "Instruction " << instruction << endl;
		cout << endl;
	}
	void read_emergency(Emergency_Alert obj)
	{
		ifstream in_f("emergency.dat", ios::binary);            //read file

		while (!in_f.eof()) {
			in_f.read((char*)&obj, sizeof(obj));
			cout << "Type: " << obj.type << endl;
			cout << "Level: " << obj.level << endl;
			cout << "Instruction " << obj.instruction << endl;
			cout << endl;
		}
		obj.show();
	}
};
ostream& operator<< (ostream& out, Emergency_Alert& obj)
{

	out << "\n Follow : \a\a\a\a\a the\a\a\a instruction \a\a\a : " << obj.instruction << "\a\a\a\a\a\a";
	out << "\n Collected information is: \n";
	out << "\n Type = " << obj.type << "\n Location = " << obj.location << "\n level = " << obj.level << endl;
	return out;
}
