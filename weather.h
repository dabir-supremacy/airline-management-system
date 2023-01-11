/*COMPILED BY MUHAMMAD TALHA SYED, i210277, AI-J
WEATHER FUNCTIONALITY CLASS
MAIN PURPOPSE IS TO CHECK IF THE WEATHER IS SAFE FOR FLYING*/


#pragma once
#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include"admin.h"
using namespace std;
class weather {
protected:
	int tmp = -65 + (rand() % 50);//RANDOMS TEMPERATURE IN THE RANGE -65(LOWEST EVER RECORDED IN A CITY) AND 50 DEGREES CELCIUS
	int w = 0 + (rand() % 3);//RANDOMS THE WEATHER CONDITION
	admin obj;//OBJECT FROM ADMIN CLASS
	int x = 0;//SELECTOR VARIABLE
public:                             //FOURTH DESIGNED INTERFACE
	void menu() {
		cout << "            |  Select one of the following options:    |" << endl;
		cout << "            |                                          |" << endl;
		cout << "            | --------------------------------------   |" << endl;
		cout << "            |   To get today's temperatue press 1      |" << endl;
		cout << "            | --------------------------------------   |" << endl;
		cout << "            |     Press 2 to get the feel outside      |" << endl;
		cout << "            | --------------------------------------   |" << endl;
		cout << "            |  To check weather condition press 3      |" << endl;
		cout << "            | --------------------------------------   |" << endl;


		cin >> x;//SELECTOR INPUT
		if (x == 1) {
			show_temperature();//SHOWS TEMPERATURE

		}
		else if (x == 2)
		{
			tell_cond();//TELLS THE "FEEL" OF TEMPERATURE OUTSIDE
		}
		else if (x == 3) {
			check_weather();//CHECKS THE WEATHER CONDTION FOR THE FLIGHTS
		}
	

	}
	//MENU
	void open_menu() {
		menu();

	}
	//TEMPERATURE FUNCTION
	void show_temperature() {
		cout << "Today's temperature: " << tmp << " degrees Celsius.";

	}
	//FEEL FUNCTION
	void tell_cond() {
		if (tmp <= 0) {
			cout << "Weather is too cold today.";
		}
		if (tmp >= 10 && tmp <= 30)
		{
			cout << "Weather is mild today, a good day to fly.";
		}
		if (tmp > 30 && tmp < 50) {
			cout << "Weather is extremely hot today.";
		}

	}
	//WEATHER CHECKER FOR FLIGHTS
	void check_weather() {
		if (w == 0) {
			cout << "Fog is expected today, flight maybe cancelled" << endl;
		}
		else if (w == 1) {
			cout << "Thunderstorm is expected today, a longer route to the destination maybe opted by the pilot" << endl;
		}
		else if (w == 2) {
			cout << "The weather is clear today, flight will proceed as planned" << endl;
		}
		else if (w == 3) {
			cout << "The weather is hostile today, expected extreme winds are expected, all flights are cancelled for today" << endl;
		}
	
	}
};