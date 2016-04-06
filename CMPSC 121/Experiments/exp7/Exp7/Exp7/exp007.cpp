//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: Lab 7
//File: P:\Private\CMPSC 121\Experiments\exp7\Exp7\Exp7\exp007
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
	cout << fixed << showpoint << setprecision(1);
	ifstream fin;
	string filename, vehicleID;
	int counter = 0;
	double miles = 0, gallons, total_miles = 0, MPG = 0, total_gallons= 0;
	double bestMPG = 0, worstMPG = 0, avgMPG = 0;
	string bestVehicleID, worstVehicleID;
	cout << "Enter file name: ";
	cin >> filename;
	fin.open(filename);
	cout << "\n\t\tAMSCO Fleet Report\n";
	cout << "----------------------------------------------------------------------\n";
	cout << "Vehicle ID\tMiles\tGallons\tMPG\n";

	if (fin.fail())
		cout << "Unable to Open File!";
	else
	{
		while (fin >> vehicleID >> miles >> gallons)
		{
			//calculate MPG
			MPG = miles / gallons;
			
			// calculate total miles
			total_miles += miles;

			//calculates average MPG
			avgMPG += MPG;

			// calculate Best and Worst MPG and 
			if (counter == 0)
			{
				bestMPG = MPG;
				worstMPG = MPG;
			}
			if (MPG > bestMPG)
			{
			bestMPG = MPG;
			bestVehicleID = vehicleID;
			}
			
			if (MPG < worstMPG)
			{
				worstMPG = MPG;
				worstVehicleID = vehicleID;
			}
			counter++;
		
		cout << vehicleID << "\t" << miles << "\t" << gallons << "\t" << MPG << endl;
		}
		avgMPG /= counter;
		cout << "----------------------------------------------------------------------\n";
		cout << "Count:       " << setw(10) << counter << endl;
		cout << "Total Miles: " << setw(10) << total_miles << endl;
		cout << "Average MPG: " << setw(10) << avgMPG << endl;
		cout << "Vehicle ID with Best MPG:    " << bestVehicleID << " at " << bestMPG << endl;
		cout << "Vehicle ID with worst MPG:   " << worstVehicleID << " at " << worstMPG << endl;
		
	}
	return 0;
}
/* 
EXECUTION SAMPLE:

Enter file name: fleet.txt

AMSCO Fleet Report
----------------------------------------------------------------------
Vehicle ID      Miles   Gallons MPG
279BX6KY2Z      582.2   20.5    28.4
802MX8BZ4Q      723.6   25.1    28.8
671AY6DZ3N      756.9   27.5    27.5
845DH6AJ3B      660.2   25.4    26.0
566GJ6KV2U      510.2   30.8    16.6
109QW6RP2Y      301.2   8.3     36.3
135TR4YC6H      387.6   12.2    31.8
----------------------------------------------------------------------
Count:                7
Total Miles:     3921.9
Average MPG:       27.9
Vehicle ID with Best MPG:    109QW6RP2Y at 36.3
Vehicle ID with worst MPG:   566GJ6KV2U at 16.6
Press any key to continue . . .

*/
