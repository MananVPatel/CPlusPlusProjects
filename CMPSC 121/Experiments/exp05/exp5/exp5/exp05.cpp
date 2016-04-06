//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment 05
//File: P:\Private\CMPSC 121\Experiments\exp05\exp5\exp5
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()

{
	const int LT20 = 20;
	const double LT20Charge = 0.10;
	const int LT40 = 40;
	const double LT40Charge = 0.08;
	const int LT60 = 60;
	const double LT60Charge = 0.06;
	const double GTE60Charge = 0.04;
	const double BALANCELIMIT = 400.00;
	const double LOWBALANCECHARGE = 15.00;
	int numberOfChecks;
	bool isUnder = false;
	double balance, serviceFee = 0, checkCharge;
	cout << fixed << setprecision(2);
	cout << "Please enter beginning balance and number of checks written: " << endl;
	cin >> balance >> numberOfChecks;
	if (balance < BALANCELIMIT)
	{
		serviceFee + LOWBALANCECHARGE;
		isUnder = true;
	}

	if (numberOfChecks < LT20)
		serviceFee += (LT20Charge*numberOfChecks);
	else if (numberOfChecks < LT40)
		serviceFee += (LT40Charge*numberOfChecks);
	else if (numberOfChecks < LT60)
		serviceFee += (LT60Charge*numberOfChecks);
	else
		serviceFee += (GTE60Charge*numberOfChecks);

	cout << "MEGABUX Bancorp" << endl;
	cout << "Your balance was " << balance << endl;
	
	if (isUnder)
	{
		cout << "You did not maintain the minimum balance! " << endl;
		cout << "You incurred a fee of $ " << LOWBALANCECHARGE << endl;
	}
	
	cout << "Total service charge = $ " << serviceFee << endl;

	return 0;

}

/* 
Execution Sample:
#1)
Please enter beginning balance and number of checks written:
100 5
MEGABUX Bancorp
Your balance was 100.00
You did not maintain the minimum balance!
You incurred a fee of $ 15.00
Total service charge = $ 0.50
Press any key to continue . . .

#2)
Please enter beginning balance and number of checks written:
500 35
MEGABUX Bancorp
Your balance was 500.00
Total service charge = $ 2.80
Press any key to continue . . .

*/
