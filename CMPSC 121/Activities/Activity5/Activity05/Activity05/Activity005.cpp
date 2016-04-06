//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 05
//File: P:\Private\CMPSC 121\Activities\Activity5\Activity05\Activity05\Activity005
//purpose: To find the cosine, tangent, and sine: using the radians which are given.
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream> 
#include <iomanip> 
#include <cmath> 

using namespace std;
int main()

{
	double sine, cosine, tangent;
	double radians;

	
	cout << "Enter an angle in radians:" << endl;
	cin >> radians;

	sine = sin(radians);
	cosine = cos(radians);
	tangent = tan(radians);
	
	cout << "******************************************************************" << endl;
	cout << "For the angle with " << radians << " radians" << endl;
	cout << "Sine =       " << fixed << setprecision(4) << sine << endl;
	cout << "Cosine =     " << fixed << setprecision(4) << cosine << endl;
	cout << "Tangent =    " << fixed << setprecision(4) << tangent << endl;
	cout << "******************************************************************" << endl;
	return 0;
}

/*
Enter an angle in radians:
0.785
******************************************************************
For the angle with 0.785 radians
Sine =       0.7068
Cosine =     0.7074
Tangent =    0.9992
******************************************************************
Press any key to continue . . .
*/


