//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 08
//File: P:\Private\CMPSC 121\Experiments\exp8\exp8\exp8\008
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;
double calcVolume(double R1, double R2, double H); // Volume Function prototype
double surfaceArea(double R1, double R2, double H); // Surface Area Function Prototype
char choice;

int main()
{
	cout << fixed << setprecision(1);
	double bottomRadius, topRadius, height, volume, surface_Area;
	
	
	do
	{
		do
		{
			cout << "Enter Radius at bottom of glass, radius at top and height: \n";
			cin >> bottomRadius >> topRadius >> height;
			if (bottomRadius < 0 && topRadius < 0 && height < 0)
			{
				cout << "Error! You have Entered a Negative Value!\n";
				cout << "Please Re-Enter Radius at bottom of glass, radius at top and height: \n";
				cin >> bottomRadius >> topRadius >> height;
			}
		} while (bottomRadius < 0 && topRadius < 0 && height < 0);

		cout << "-------------------------------------------------------------------------\n";
		cout << "For a glass with bottom radius of " << bottomRadius << endl;
		cout << "Top radius of " << topRadius << " and height of " << height << endl;
		
		volume = calcVolume(bottomRadius, topRadius, height); // calling function to execute
		
		surface_Area = surfaceArea(bottomRadius, topRadius, height); // calling function to execute
		
		cout << "The Volume is " << volume << " and the surface area is " << surface_Area << endl;
		
		cout << "-------------------------------------------------------------------------\n";
		cout << "\nWould you like to Enter more values (Y for yes OR N for No?\n";
		cin >> choice;
		cout << endl;
		cout << "-------------------------------------------------------------------------\n";

	} while (choice == 'Y' || choice == 'y');

	
	return 0;
}
 
// Function Definition Below 
double calcVolume(double R1, double R2, double H)
{
	double const PI = 3.14159;
	double volume;
	volume = ((0.3333)*(PI)*(H))*((pow(R1, 2)) + (pow(R2, 2)) + (R1*R2));
	return volume;
}

double surfaceArea(double R1, double R2, double H)
{
	double const PI = 3.14159;
	double surface_area;
	surface_area = (PI*(R1 + R2))*sqrt((pow((R2 - R1), 2)) + (pow(H, 2)) + (PI)*(pow(R1, 2)));
	return surface_area;
}

/*
Enter Radius at bottom of glass, radius at top and height:
2.5 3.75 4.5
-------------------------------------------------------------------------
For a glass with bottom radius of 2.5
Top radius of 3.8 and height of 4.5
The Volume is 139.9 and the surface area is 126.4
-------------------------------------------------------------------------

Would you like to Enter more values (Y for yes OR N for No?
Y

-------------------------------------------------------------------------
Enter Radius at bottom of glass, radius at top and height:
-1 -5 -6
Error! You have Entered a Negative Value!
Please Re-Enter Radius at bottom of glass, radius at top and height:
6.25 7.35 8.95
-------------------------------------------------------------------------
For a glass with bottom radius of 6.3
Top radius of 7.3 and height of 8.9
The Volume is 1302.8 and the surface area is 610.3
-------------------------------------------------------------------------

Would you like to Enter more values (Y for yes OR N for No?
N

-------------------------------------------------------------------------
Press any key to continue . . .
*/