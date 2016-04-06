//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Lab Experiment: 003-2
//File: P:\Private\CMPSC 121\Experiments\exp03\exp003-2\exp003-2
//purpose: To find the principal, the interest rate, and the number of times the interest is compounded.
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
	double A, IR, T, P, I; // A = Amount in savings after interest applied
	// IR = interest rate, T = Times Compounded, P = Principal, I = Accumulated Interest 
	cout << fixed << setprecision(2);
	cout << "Enter the current balance in your savings account, the interest rate, and the # of times it is compounded: " << endl;
	cin >> P >> IR >> T;
	A = P*pow(1 + (IR / T), T);
	I = A - P;
	IR = IR * 100;
	cout << endl;

	cout << "Interest Rate:         " << setw(8)<< IR << "%"  << endl;
	cout << "Times Compounded:      " << setw(8) << T  << endl;
	cout << "Principal:           $ " << setw(8) << P  << endl;
	cout << "Interest:            $ " << setw(8) << I  << endl;
	cout << "Amount in Savings:   $ " << setw(8) << A  << endl;

	return 0;
}

/* Execution Sample:
Enter the current balance in your savings account, the interest rate, and the #
of times it is compounded:
1000.00    0.0425    12

Interest Rate:             4.25%
Times Compounded:         12.00
Principal:           $  1000.00
Interest:            $    43.34
Amount in Savings:   $  1043.34
*/