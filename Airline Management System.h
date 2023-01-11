#pragma once
#include<iostream>
using namespace std;
#include"Emergency.h"
#include"Medics.h"
#include"Aeroplane.h"
#include"Payment.h"
#include"Crew_Members.h"
#include"customer_services.h"

class Airline_Management_system
{
private:
	int choice = 1, type = 0, level = 0, x = 0;
	string l;
	long cnic;
	char pass[8],ch;
public:
	void choose()
	{
		cout << "\n<><><><><><><><><><><><><><><> WELCOME TO AMADEUS ALTEA SUITE <><><><><><><><><><><><><><><>";
		while(choice!=0)
		{ 
	    cout << "\n Make your selection:\n Press 1 for accessing user management\n Press 2 to access Plane management \n Press 3 to access Emergency alert\n Press 4 to go to the Feedback section" << endl;
		cin >> choice;
		if (choice == 1)
		{
			system("CLS");
			// using the object to 
		// call the member functions of the class Medical class and class Doctor
			cout << "<><><><><><><><><><><><>  WELCOME TO USER MANAGEMENT  <><><><><><><><><><><><>\n\t Press 1 for accessing Employee \n\t Press 2 for accessing Passenger" << endl;
			cin >> x;
			if (x == 1)
			{
				cout << "<><><><><><><><><><><><>  WELCOME TO EMPLOYEE MANAGEMENT  <><><><><><><><><><><><>\n\t Press 1 for Basic Operations \n\t Press 2 for accessing Medics\n\t Press 3 for accessing Crew members" << endl;
				cin >> x;
				if (x == 1)
				{
					cout << "enter 1 for verification" << endl;
					cout << "enter 2 for searching a user" << endl;
					cout << "enter 3 for creating your account" << endl;
					cout << "Enter 4 to print data" << endl;
					cin >> x;
					cout << "\n Enter the cnic ";
					cin >> cnic;
					cout << "\n Enter Password character by charcter";
					for (int i = 0; i < 8; i++)
					{
						cin >> pass[i];
					}
					employee* obj = new MedicalStaff(1234, "doctor");
					obj->setCNIC(cnic);
					obj->setpassword(pass);
					if (x == 1)
					{
						obj->CNIC_valid(cnic);
						obj->Password_check(pass);
					}
					else if (x == 2)
					{
						obj->search_user(pass);
					}
					else if (x == 3)
					{
						obj->storing_person(*obj);
					}
					else if (x == 4)
					{
						obj->Print_data();
					}

				}
				if (x == 2)
				{
					cout << "<><><><><><><><><><><><>  WELCOME TO MEDICAL DEPARTMENT  <><><><><><><><><><><><>\n Press 1 for displaying current employee \n Press 2 for accessing Doctors \n Press 3 for writing medical staff data \n Press 4 for reading Medical staff data" << endl;
					cin >> x;
					if (x == 1)
					{
						employee* ptr = new MedicalStaff(1, "Nurse");
						ptr->display_info();
					}
					else if (x == 2)
					{
						Doctor* pt = new Doctor(123, 12);
						MedicalStaff* p;
						p = pt;
						p->display_info();
					}
					else if (x == 3)
					{
						MedicalStaff obj;
						obj.Add_med(obj);
					}
					else if (x == 4)
					{
						MedicalStaff obj;
						obj.read_med(obj);
						obj.read_med(obj);
					}
				}
				else if (x == 3)
				{
					cout << "<><><><><><><><><><><><>WELCOME TO CREW DEPARTMENT<><><><><><><><><><><><>" << endl;
					employee* obj;
					obj = new Crew_members("Amna", "1234", "Pilot", " Senior pilot", 12);
					obj->display_info();
				}
			}

			//Passenger
			else if (x == 2)
			{
				cout << "<><><><><><><><><><><><>  WELCOME TO PASSENGER MANAGEMENT  <><><><><><><><><><><><>" << endl;
				domestic_booking dm;//domestic object 
				int_booking intl;// International object
				passenger psg;//passenger object
				payment pym;// payment object
				int ch1, ch2, m;//integers
				char inp;//character vars
				do// loop
				{
					system("CLS");
					cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
					cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";
					cout << "\n\n \t\tWelcome To The Reservation Section" << endl << endl;
					cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
					cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n\n\n";
					cout << "\t  Fly the with Friendly Skies Our Amadeus Altea Suite!\n\n" << endl;


					cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";
					cout << "\n\t\t\t 1.Booking of flight \n\t\t\t 2.Cancelation of Flight \n\t\t\t 3.Checking of Ticket \n\t\t\t 4.Exit(4)" << endl;
					cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";

					cout << "\n\t\t Please enter your desired option:" << endl;
					cin >> ch1;
					switch (ch1)// switch statements
					{
					case 1://Cases
						system("CLS");
						cout << "\n\n\1.Domestic Flights(1) \n\2.International Flights(2)" << endl;
						cout << "\nPlease enter desired option :" << endl;
						cin >> ch2;
						switch (ch2)//inner case
						{
						case 1://domestic case
							//function calls
							psg.domestic_pnr();
							psg.p_detail(1);
							psg.gend_verf();
							psg.more_info_required();
							pym.payment_detals();
							pym.MEMBERSHIP();
							psg.disp_dm();
							psg.CompMenu();
							creatfil(psg);//file creation
							break;
						case 2: //international case
							//function calling
							psg.p_detail(2);
							psg.int_pnr();
							psg.gend_verf();
							psg.more_info_required();
							pym.payment_detals();
							pym.MEMBERSHIP();
							psg.disp_int();
							psg.CompMenu();
							createfilei(psg);
							//file creation
							break;
						default://wrong input
							cout << "Sorry Wrong input so \nTry again\n\n\n" << endl;
							return choose();
						}
						break;
					case 2:
						//for canceling ticket
						system("CLS");
						cout << "\1.Domestic Flight(1) \2\n.International Flight(2)" << endl;
						cout << "\nPlease enter your choice" << endl;
						cin >> ch2;
						if (ch2 == 1)
						{
							cout << "Please enter your PNR no.:" << endl;
							cin >> m;
							cancel_domesticticket(m);//function calling domestic cancellation
						}
						else if (ch2 == 2)
						{
							cout << "Please enter your PNR no.:" << endl;
							cin >> m;
							cancel_intticket(m);//function calling international cancellation
						}
						else
						{
							cout << "Sorry Wrong input so \nTry again\n\n\n";
							return choose();
						}
						break;
					case 3://displaying booked ticket details
						system("CLS");
						cout << "\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
						cout << "\nPlease chose your option" << endl;
						cin >> ch2;
						if (ch2 == 1)
						{
							cout << "Please enter your PNR no.:" << endl;
							cin >> m;
							checkticket_dm(m);
						}//function calling  fordomestic ticket details
						else if (ch1 == 2)
						{
							cout << "Please enter your PNR no.:" << endl;
							cin >> m;
							checkticket_int(m);//function calling for domestic ticket details
						}
						else
						{
							cout << "Sorry Wrong input so.\nTry again\n\n\n";
							return choose();
						}
						break;
					case 4:
						system("CLS");
					default://for wrong input
						cout << "Sorry Wrong input so\nTry again.\n\n\n\n" << endl;
						return choose();
					}
					cout << "\n\n\nDo you wish to continue:(y/Y)" << endl;
					cin >> inp;
				} while (inp == 'Y' || inp == 'y');//condition 
			}

		}
	

		else if (choice == 2)
		{
			system("CLS");
			cout << "\n <><><><><><><><><><><><> WELCOME TO PLANE MANAGEMENT <><><><><><><><><><><><>" << endl;
			//planes
			Aeroplanes obj(12, 11, 13, "A308");
			int x = 1;
			Aeroplanes obj1(12, 13, 0, "A308");
			obj1.write_plane_info(obj);
			while (x != 0)
			{
				cout << "\n Press 1 to check petrol level \n Press 2 to move the plane \n Press 3 to check if the feul is empty \n Press 4 to refill \n Press 0 to exit\n";
				cin >> x;
				if (x == 1)
				{
					cout << "\n Checking feul level: " << obj.getPetrolLevel(); //it will give the current level of petrol
				}
				else if (x == 2)
				{
					cout << "\n Trying to move Plane by some distance: ";
					int distance;
					cout << "\n Enter the distance";
					cin >> distance;
					obj.MovePlane(distance);  //trying to move the car
				}
				else if (x == 3)
				{

					cout << "\n Checking if the feul tank is empty\n 0 means yes \n 1 means no\n " << obj.isEmpty(); //checking if the tank is empty;
				}
				else if (x == 4)
				{
					cout << "\n Filling tank upto ____";
					int n;
					cin >> n;
					obj.setPetrolLevel(n); //filling up the tank
				}
				obj.showcontent();
				if (x == 0)
				{
					cout << "\n\tSorry to see you go! ";
				}
			}

		}
		else if (choice == 3)
		{
			system("CLS");
			//emergency
			cout << "<><><><><><><><><><><><> WELCOME TO EMERGENCY ALERT <><><><><><><><><><><><>" << endl;
			Emergency_Alert obje;
			cout << "\n Set Emergency type \n Press 1 for Plane emergency \n Press 2 for Weather emergency \n Press 3 for Health emergency \n Press 4 for Hijacking related emergency\n <><><><><><><><><><>MAKE YOUR SELECTION<><><><><><><><><><>";
			cout << endl;
			cin >> type;
			obje.Set_emergenvy_Type(type);
			cout << "\n Select emergency level 1-4 along with the matching scenerio";
			cout << endl;
			cin >> level;
			obje.set_level(level);
			cout << "\n Set location ";
			cout << endl;
			getline(cin, l);
			obje.set_location(l);
			cout << "\n Displaying course of action";
			obje.course_of_action();
			cout << obje;  //operator overloading
			cout << "\n<><><><><><><><>FINAL STEP <><><><><><><><>\n Press 1 to record emergency \n Press 2 to read emergency \n Press 3 to quit emergency";
			cin >> x;
			if (x == 1)
			{
				cout << "\n Adding emergency\n ->->->\n Exiting Emergency";
				obje.Add_emergency(obje);
			}
			else if (x == 2)
			{
				cout << "\n Reading emergency\n ->->->\n Exiting Emergency";
				obje.Add_emergency(obje);
			}
			else
			{
				cout << "\n \tHAPPY TO SEE YOU G0!\n <><><><><><><><><><><><><><><><><><><><><>";
				exit(0);
			}
		}
		else if (choice == 4) 
		{//THIS FUNCTION STARTS THE WHOLE THREAD FOR THE FEEDBACK SECTION
		customer_services object;
		object.display_screen();
		}
		else if (choice == 0)
		{

			cout << "\n\t\tARE YOU SURE YOU WANT TO QUIT?!\n press y to continue ";
			cin >> ch;
			if (ch == 'y' || ch == 'Y');
			cout << "\n Wait for the completion of logout ";

			break;
		 }
        }
}

	};



