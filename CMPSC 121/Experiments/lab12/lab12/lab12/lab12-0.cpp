//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 12
//File: P:\Private\CMPSC 121\Experiments\lab12\lab12\lab12\lab12-0
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//structure definition
struct SalesRecord
{
	string invoice;
	char plant;
	double sales;
};

//function prototype with the structure SalesRecord as a parameter with other parameters
void accumulate(const SalesRecord &s, double & Esales, double &Jsales, double & Psales);


int main()
{
	double total, percent;
	SalesRecord s; //Varible s of the struct SalesRecord
	ifstream inputfile;
	double Erie = 0, Jamestown = 0, Pittsburgh = 0;
	
	inputfile.open("sales.txt");
	if (inputfile.fail())
	{
		cout << "Unable to open file\n";
	}
	else
	{
		while (inputfile >> s.invoice >> s.plant >>s.sales) // calling each category one by one
		{
			accumulate(s, Erie, Jamestown, Pittsburgh); //function call 
		}
		cout << fixed << showpoint << setprecision(2) << endl;
		total = Erie + Jamestown + Pittsburgh;
		
		//display on screen
		cout << "\tS A L E S  R E P O R T\n";
		percent = (Erie / total) * 100;
		cout << "Erie          $" << Erie << setw(8) << percent << "%" << endl;
		percent = (Jamestown / total) * 100;
		cout << "Jamestown     $" << Jamestown << setw(8) << percent << "%" << endl;
		percent = (Pittsburgh / total) * 100;
		cout << "Pittsburgh    $" << Pittsburgh << setw(8) << percent << "%" << endl;
		total = Erie + Jamestown + Pittsburgh;
		cout << "              -----------\n";
		cout << "Total Sales   $" << total << endl;
		
		inputfile.close();
		return 0;
	}
}

//function definition
void accumulate(const SalesRecord &s, double & Esales, double &Jsales, double & Psales)
{
	// accurately distributes information using the switch statement
	switch (s.plant)
	{
	case 'E': 
		Esales += s.sales; 
		break;
	case 'J': 
		Jsales += s.sales; 
		break;
	case 'P': 
		Psales += s.sales;
		break;
	}
}

/*

S A L E S  R E P O R T
Erie          $18983.30   27.38%
Jamestown     $16923.40   24.41%
Pittsburgh    $33435.19   48.22%
-----------
Total Sales   $69341.89
Press any key to continue . . .

*/
