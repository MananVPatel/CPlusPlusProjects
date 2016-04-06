//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 04
//File: P:\Private\CMPSC 121\Experiments\Exp04\exp4\exp4\exp004
//purpose: To calculate the parking fee depending on the type of vehicle parked and the total number of hours the vehicle was parked.
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: Ron Delporto

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	char vehicle_type;
	double amount_due;
	int time;
	string vTypeName;
	const int carlimit = 2;
	const int trucklimit = 2;
	const int buslimit = 1;
	const double carin = 1.25;
	const double carover = 1.50;
	const double truckin = 2.75;
	const double truckover = 3.75;
	const double busin = 9.50;
	const double busover = 6.75;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the Vehicle Type (C = Car, T = Truck, B = Bus): " << endl;
	cin >> vehicle_type;
	cout << "Total time in hours: " << endl;
	cin >> time;


	if (vehicle_type == 'C')
		
	{
		vTypeName = "Car";
		if (time <= carlimit)
			amount_due = carlimit*time;
		else 
			amount_due = carover*(time-2) + (carlimit*carin);
	}
	
	if (vehicle_type == 'T')
	
	{
		vTypeName = "Truck";
		if (time <= trucklimit)
			amount_due = trucklimit*time;
		else
			amount_due = truckover*(time-2) + (trucklimit*truckin);
	}
	
	if (vehicle_type == 'B')

	{
		vTypeName = "Bus";
		if (time <= buslimit)
			amount_due = buslimit*time;
		else
			amount_due = busover*(time-1) + (buslimit*busin);
	}
	
	cout << "\nCrunchum Parking lots, Inc." << endl;
	cout << "\"We usually find your vehicle!\"" << endl;
	cout << endl;
	cout << "Vehicle Type: " << vTypeName << endl;
	cout << "Time: " << time << "     Hours" << endl;
	cout << "Amount Due: $" << amount_due << endl;
		
	return 0;
	


}

/*

#1) Car --> 4 Hours

Enter the Vehicle Type (C = Car, T = Truck, B = Bus):
C
Total time in hours:
4

Crunchum Parking lots, Inc.
"We usually find your vehicle!"

Vehicle Type: Car
Time: 4     Hours
Amount Due: $5.50
Press any key to continue . . .



#2) Car --> 7 Hours

Enter the Vehicle Type (C = Car, T = Truck, B = Bus):
C
Total time in hours:
7

Crunchum Parking lots, Inc.
"We usually find your vehicle!"

Vehicle Type: Car
Time: 7     Hours
Amount Due: $10.00
Press any key to continue . . .


#3) Truck --> 10 Hours

Enter the Vehicle Type (C = Car, T = Truck, B = Bus):
T
Total time in hours:
10

Crunchum Parking lots, Inc.
"We usually find your vehicle!"

Vehicle Type: Truck
Time: 10     Hours
Amount Due: $35.50
Press any key to continue . . .


#4) Bus --> 8 Hours

Enter the Vehicle Type (C = Car, T = Truck, B = Bus):
B
Total time in hours:
8

Crunchum Parking lots, Inc.
"We usually find your vehicle!"

Vehicle Type: Bus
Time: 8     Hours
Amount Due: $56.75
Press any key to continue . . .

*/