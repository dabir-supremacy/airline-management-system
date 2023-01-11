#pragma once
#include<iostream>
#include<fstream>
#include <string.h>
//#include <cstring>
using namespace std;
class ecl {
private:

	//private:

public:
	string CNIC;
	string name, address, letter_reference, father_name, date, status;
	void add_ECL_record(ecl ecl_object)
	{
		ofstream out_f("ecl.dat", ios::binary | ios::app);            //write record in file
		out_f.write((char*)&ecl_object, sizeof(ecl));
		out_f.close();
	};

	ecl()
	{

	}

	ecl(string name_value, string address_value, string letter_reference_value, string father_name_value, string CNIC_value, string status_value, string date_value)
	{
		CNIC = CNIC_value;
		name = name_value;
		address = address_value;
		letter_reference = letter_reference_value;
		father_name = father_name_value;
		status = status_value;
		date = date_value;

	};

	void modify_ECL_status(string CNIC_value, string status_value)
	{
		// code to update and modify
		// the content of the binary file
		int pos, flag = 0;

		fstream fs;
		fs.open("ecl.dat", ios::in | ios::binary | ios::out);

		while (!fs.eof()) {
			// storing the position of
			// current file pointeri.e. at
			// the end of previously read record
			pos = fs.tellg();

			fs.read((char*)this, sizeof(ecl));
			if (fs) {

				// comparing the roll no with that
				// of the entered roll number
				if (CNIC == CNIC_value) {
					flag = 1;

					// setting the new (modified )
					// data of the object or new record
					//strcpy(status, status_value);
					status = status_value;

					// placing the put(writing) pointer
					// at the starting of the record
					fs.seekp(pos);

					// writing the object to the file
					fs.write((char*)this, sizeof(ecl));

				}
			}
		}
		fs.close();

		if (flag == 1)
			cout << "\nRecord successfully modified \n";
		else
			cout << "\nRecord not found \n";


	};

	bool ECL_check(string CNIC_value)
	{
		ecl tmp;
		ifstream in_f("ecl.dat", ios::binary);            //read file

		while (!in_f.eof()) {
			in_f.read((char*)&tmp, sizeof(ecl));

			if (tmp.CNIC == CNIC_value) {
				in_f.close();

				cout << "\n Person found! " << endl;
				return true;
			}
			std::cin.get();
		}

		in_f.close();
		return false;

	};
};