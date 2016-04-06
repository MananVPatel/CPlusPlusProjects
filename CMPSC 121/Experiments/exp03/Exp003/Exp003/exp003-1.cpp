//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Lab Experiment: 03
//File: P:\Private\CMPSC 121\Experiments\exp03\Exp003\Exp003
//purpose: To find the Volume and Surface Area of a circular ring.
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <iomanip>
using namespace std;
int main()


{
	const double PI = 3.14159;
	double V, S; // V = Volume, S = Surface Area
	double R, r; // R = Radius of Ring, r = radius of Cross Section 

	cout << fixed << setprecision(3);
	cout << "Enter radius of ring and radius of cross section: \n";
		cin >> R >> r;
		cout << endl;
	cout << "For a ring with a radius of " << R << " and cross section radius of " << r <<"."<< endl;
	cout << endl;
	V = 2 * (PI * PI)*R*r*r;
	S = 4 * (PI * PI)*R*r;
	cout << "The Volume is:            " << V << endl;
	cout << "The Surface Area is:      " << S << endl;

	return 0;

/* 
Execution Sample:
Enter radius of ring and radius of cross section:
25.75 3

For a ring with a radius of 25.750 and cross section radius of 3.000.

The Volume is:            4574.554
The Surface Area is:      3049.703
*/
}


