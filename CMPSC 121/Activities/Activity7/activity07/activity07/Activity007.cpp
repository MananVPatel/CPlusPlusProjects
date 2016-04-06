//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 07
//File: P:\Private\CMPSC 121\Activities\Activity7\activity07\activity07\activity007
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()

{
	char Pchoice; // package choice holds the characters 'A', 'B', & 'C' assigned to the packages.
	double monthly_bill;
	int minutes;
	const double
		packageA = 39.99,// this holds the prize for package A per month for 450 minutes
		packageB = 59.99, // this holds the prize for package B per month for 900 minutes
		packageC = 69.99, // this holds the prize for package C per month for unlimited minutes
		packageAA = 0.45, // this holds the additional charge per minute for package A
		packageBA = 0.40;// this holds the additional charge per minute for package B
	const int
		packageAM = 450, // this holds the regular minutes for package A
		packageBM = 900; // this holds the regular minutes for package B

	cout << fixed << showpoint << setprecision(2);
	cout << "\t Choose from three different subscription packages:\n";
	cout << "Package A:	For $39.99 per month 450 minutes are provided\n";
	cout << "			Additional minutes are $0.45 per minute.\n";
	cout << "Package B:	For $59.99 per month 900 minutes are provided\n";
	cout << "			Additional minutes are $0.40 per minute.\n";
	cout << "Package C:	For $69.99 per month unlimited minutes provided.\n\n";

	cout << "Enter the Package Letter (A, B, or C), you have purchased: \n";
	cin >> Pchoice;

	if ((Pchoice > 'A' || Pchoice >'a') && (Pchoice < 'C' || Pchoice < 'c'))
	{
		cout << "Enter the minutes used : \n";
		cin >> minutes;
	}
	else
	{
		cout << "\n\nYou must choose from Package A, B, or C. \n";
		cout << "Invalid Entry. Please end program and start again. \n";
		return 0;
	}

	if (Pchoice == 'A' || Pchoice == 'a')
	{
		if (minutes <= packageAM)
			monthly_bill = packageA;
		else
			monthly_bill = (packageA)+((minutes - packageAM)*packageAA);
	}


	if (Pchoice == 'B' || Pchoice == 'b')
	{
		if (minutes <= packageBM)
			monthly_bill = packageB;
		else
			monthly_bill = (packageB)+((minutes - packageBM)*packageBA);
	}


	if (Pchoice == 'C' || Pchoice == 'c')
	{
		monthly_bill = packageC;
	}


	cout << "\nYour Monthly Bill is: $" << monthly_bill << endl;

	return 0;

	/* Execution Sample:
	#1)
	Choose from three different subscription packages:
	Package A:      For $39.99 per month 450 minutes are provided
	Additional minutes are $0.45 per minute.
	Package B:      For $59.99 per month 900 minutes are provided
	Additional minutes are $0.40 per minute.
	Package C:      For $69.99 per month unlimited minutes provided.

	Enter the Package Letter (A, B, or C), you have purchased:
	a
	Enter the minutes used :
	450

	Your Monthly Bill is: $39.99
	Press any key to continue . . .



	#2)
	Choose from three different subscription packages:
	Package A:      For $39.99 per month 450 minutes are provided
	Additional minutes are $0.45 per minute.
	Package B:      For $59.99 per month 900 minutes are provided
	Additional minutes are $0.40 per minute.
	Package C:      For $69.99 per month unlimited minutes provided.

	Enter the Package Letter (A, B, or C), you have purchased:
	b
	Enter the minutes used :
	1000

	Your Monthly Bill is: $99.99
	Press any key to continue . . .


	#3)
	Choose from three different subscription packages:
	Package A:      For $39.99 per month 450 minutes are provided
	Additional minutes are $0.45 per minute.
	Package B:      For $59.99 per month 900 minutes are provided
	Additional minutes are $0.40 per minute.
	Package C:      For $69.99 per month unlimited minutes provided.

	Enter the Package Letter (A, B, or C), you have purchased:
	C
	Enter the minutes used :
	546543

	Your Monthly Bill is: $69.99
	Press any key to continue . . .


	#4)
	Choose from three different subscription packages:
	Package A:      For $39.99 per month 450 minutes are provided
	Additional minutes are $0.45 per minute.
	Package B:      For $59.99 per month 900 minutes are provided
	Additional minutes are $0.40 per minute.
	Package C:      For $69.99 per month unlimited minutes provided.

	Enter the Package Letter (A, B, or C), you have purchased:
	d
	You must choose from Package A, B, or C.
	Invalid Entry. Please end program and start again.
	Press any key to continue . . .



	*/
}