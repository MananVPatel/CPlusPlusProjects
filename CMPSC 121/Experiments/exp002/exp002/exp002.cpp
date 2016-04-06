//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 02
//File: P:\cmpsc121\experiments\exp002.cpp
//purpose: Division modulo division.
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: Ronald Delporto

#include <iostream>
using namespace std;
int main()
{
	double tendered;
	double cost;
	int change;
	int fifties, twenties, tens, fives, ones, quarters, dimes, nickels, pennies;
	
	cout << "Enter amount of purchase and amount tendered: ";
	cin >> cost >> tendered;
	change = (tendered - cost) * 100 + .5;

	fifties = change / 5000;
	change = change % 5000;

	twenties = change / 2000;
	change = change % 2000;

	tens = change / 1000;
	change = change % 1000;

	fives = change / 500;
	change = change % 500;

	ones = change / 100;
	change = change % 100;

	quarters = change / 25;
	change = change % 25;

	dimes = change / 10;
	change = change % 10;

	nickels = change / 5;
	change = change % 5;

	pennies = change / 1;
	change = change % 1;

	cout << endl;
	cout << "For your purchase of $" << cost << " you tendered $" << tendered << endl;
	cout << "Your change is " << tendered - cost << endl;
	cout << endl;
	cout << "Fifties:     " << fifties << endl;
	cout << "Twenties:    " << twenties << endl;
	cout << "Tens:        " << tens << endl;
	cout << "Fives:       " << fives << endl;
	cout << "Dollars:     " << ones << endl;
	cout << "Quarters:    " << quarters << endl;
	cout << "Dimes:       " << dimes << endl;
	cout << "Nickels:     " << nickels << endl;
	cout << "Pennies:     " << pennies << endl;
return 0;
}

/* Execution Sample:
Enter amount of purchase and amount tendered: 2.09 100.00

For your purchase of $2.09 you tendered $100
Your change is 97.91

Fifties:     1
Twenties:    2
Tens:        0
Fives:       1
Dollars:     2
Quarters:    3
Dimes:       1
Nickels:     1
Pennies:     1
Press any key to continue . . .

*/
