#pragma once
#include<iostream>
#include<string>
using namespace std;
#include<fstream>
class Aeroplanes
{
private:
	int Number_of_planes, Available_planes, petrolLevel;
	bool c = 0;
	string model;
public:
	Aeroplanes()
	{

		Number_of_planes = 3;
		Available_planes = 0;
		petrolLevel = 0;
		model = "blank";
	}
	Aeroplanes(int a, int b, int c, string v)
	{

		Number_of_planes = a;
		Available_planes = 0;
		petrolLevel = c;
		model = v;
	}
	void set_everything()
	{
		int a, b, c;
		cout << "\n enter the number of planes , available planes and fuel level respectively \n";
		cin >> a >> b >> c;
		Number_of_planes = a;
		Available_planes = b;
		petrolLevel = c;
		cout << "\n enter the plane model";
		getline(cin, model);
	}
	int get_noOfPlanes()
	{
		return Number_of_planes;
	}
	int get_available_planes()
	{
		return Available_planes;
	}
	string getmodel()
	{
		return model;
	}

	void setPetrolLevel(int petrolLevelVal) //this function will set the level of petrol
	{
		if (petrolLevel >= 45) //if petrol is equal to or greater than 45, the value will be 45
		{
			petrolLevel = 45;
		}
		else
		{
			petrolLevel = petrolLevelVal;  //otherwise the value acn be anything below 45
		}
	}
	int getPetrolLevel() //getter function to get the value of petrol
	{
		return petrolLevel; //and it returns the value of petrol
	}

	void set_plane_feul(int p) //parametrized constructor that sets the value pf petrol
	{
		petrolLevel = p;
	}
	bool MovePlane(int distanceKM) //this function will determine whether the car will move or not
	{
		const int litre_per_100_kilometers = 8; //const milaege of a plane
		float petrolUsed = (litre_per_100_kilometers * distanceKM); //petrol usage formula
		float totalUsedPetrol = petrolUsed / 100; //in percetage
		if (totalUsedPetrol > petrolLevel) // if that perctange is higher than the value then the car will not move
		{
			petrolLevel = 0;
			cout << "\n Warning: Insufficient petrol to move the plane!";
			return 0;
		}
		//otherwise the petrol will decrease to move the car
		petrolLevel = petrolLevel - totalUsedPetrol;
		return 1;

	}

	void Refill() //this function will refill the tank
	{
		cout << "\n Wait while tank is being refilled!\n\a Refill Successful";
		petrolLevel = 45;
	}
	bool isEmpty() //this function checks whether petrol is available or not
	{
		if (petrolLevel == 0)
		{
			cout << "\n One plane feul empty" << endl;
			Available_planes--;
			c = 1;
			return c;
		}
		else
		{
			c = 0;
			return c;
		}
	}
	void showcontent()
	{
		cout << "\n No. of planes" << Number_of_planes << "\n Available planes: " << Available_planes << "\n feul: " << petrolLevel;
		cout << "\n models" << model;
	}
	bool write_plane_info(Aeroplanes obj)
	{

		obj.getmodel();
		obj.getPetrolLevel();
		obj.get_available_planes();
		obj.get_noOfPlanes();
		ofstream outfile("PlaneList.dat", ios::binary | ios::app);
		if (!outfile)
		{
			cout << "Cannot open file!" << endl;
			return 1;
		}
		outfile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
		outfile.close();
		if (!outfile.good()) {
			cout << "Error occurred at reading time!" << endl;
			return 1;
		}

	}
	bool read(Aeroplanes obj)
	{
		ifstream infile("PlaneList.dat", ios::binary);
		infile.read(reinterpret_cast<char*>(&obj), sizeof(obj));
		if (!infile)
		{
			cout << "Cannot open file!" << endl;
			return 1;
		}
		obj.showcontent();
		infile.close();

		if (!infile.good()) {
			cout << "Error occurred at reading time!" << endl;
			return 1;
		}
	}
};
