//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 02
////P:\Private\CMPSC 121\Activities\Activity3\Activity03.cpp
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None
#include <iostream>
using namespace std;
int main()
{
	
	double total;
	double num1, num2, num3, num4, num5;
	cout << "Enter Five integers: " << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5;
	total = num1 + num2 + num3 + num4 + num5;
	cout << "total sum:  " << total << endl;
	return 0;
}

/* Execution Sample:
Enter Five integers:
10
20.05
20.35
35.25
75.12
total sum:  160.77
Press any key to continue . . .
*/