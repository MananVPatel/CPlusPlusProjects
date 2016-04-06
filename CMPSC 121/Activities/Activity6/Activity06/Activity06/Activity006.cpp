
//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 06
//File: P:\Private\CMPSC 121\Activities\Activity6\Activity06\Activity06\
//purpose: To Calculate overtime when given hourly wage and hours worked of a company employee.
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()

{
	double hourly_wage, hours_worked, overtime, total_pay;
	string name;

	cout << "Enter your name: \n";
	getline(cin, name);
	cout << "Enter your Hourly wage: \n";
	cin >> hourly_wage;
	cout << "Enter Hours Worked: \n";
	cin >> hours_worked;
	cout << fixed << showpoint << setprecision(2);
	overtime = (hours_worked - 40)*1.50*(hourly_wage);
	total_pay = overtime + (40 * hourly_wage);

	cout << "********************************************************************************\n";
	cout << "CMPSCI-121 Industries \n";
	cout << endl;
	cout << "Pay to the order of: " << name << endl;
	cout << "                                                          $" << setw(8) << total_pay << endl;
	cout << "********************************************************************************\n";

	return 0;

}

/* Execution Sample:
Enter your name:
Manan V. Patel
Enter your Hourly wage:
18.95
Enter Hours Worked:
46.75
********************************************************************************

CMPSCI-121 Industries

Pay to the order of: Manan V. Patel
$  949.87
********************************************************************************

Press any key to continue . . .
*/
