//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 04
//File: P:\Private\CMPSC 121\Activities\Activity4\Activity04\Activity04\
//purpose: To find the assesment value and property tax for a piece of property
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
	double propertyvalue, assessmentvalue, propertytax;
	const double AVP = 0.60;		//AVP: Assesment Value Percentage.
	// I created this variables in case the AVP ever changes, it would be easier to make modifications latter. 
	
	cout << fixed << setprecision(2);
	cout << "What is the actual value of the Property?" << endl;
	cin >> propertyvalue;
	
	assessmentvalue = propertyvalue*AVP;
	
	const double PTE = (assessmentvalue / 100)*0.75;		// PTE = Property Tax Equation
	// I created this variables in case the PTE ever changes, it would be easier to make modifications latter. 
	
	propertytax = PTE;
	
	cout << "The assement value for the property is:   $" << assessmentvalue << endl;
	cout << "The property tax for the property is:     $" << propertytax << endl;
	
	return 0;
}

/* Execution Sample:
1)
What is the actual value of the Property?
10000
The assement value for the property is:   $6000
The property tax for the property is:     $45
Press any key to continue . . .

2)
What is the actual value of the Property?
150000.75
The assement value for the property is:   $90000.45
The property tax for the property is:     $675.00
Press any key to continue . . .

*/