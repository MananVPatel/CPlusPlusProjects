//File: P:\Private\CMPSC 121\Experiments\exp9\exp9\exp9\exp09
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <cmath>
using namespace std;
//DECLARATIONS SECTION

const double CRITICAL_TEMP = 85; // global constant, good practice

void check_pulse(int, int);   // Determine stability of pulse
int main()
{
	double temp; // holds the temperature of the person
	int pulse1, pulse2; // local variables
	cout << "Enter a temperature and two pulse rates: ";
	cin >> temp >> pulse1 >> pulse2;  // global variables
	check_pulse(pulse1, pulse2);
	cout << "Temperature = " << temp << endl;
	if (temp < CRITICAL_TEMP)
		cout << "Patient is dead. Shut off life support.\n";
	return 0;
}
void check_pulse(int pulse1, int pulse2)
{
	int temp; //temporary variable, holds the difference between the two pulse
	// Determine stability of pulse
	temp = pulse1 - pulse2;
	// Use temporary variable to check pulse variability
	if (abs(temp) >= 10)
		cout << "Irregular pulse.\n";
	else
		cout << "Regular pulse.\n";
}
/*
1)
Enter a temperature and two pulse rates: 98.6 70 100
Irregular pulse.
Temperature = 98.6
Press any key to continue . . .

2)
Enter a temperature and two pulse rates: 98.6 100 20
Irregular pulse.
Temperature = 98.6
Press any key to continue . . .

3)
Enter a temperature and two pulse rates: 82.9
100 150
Irregular pulse.
Temperature = 82.9
Patient is dead. Shut off life support.
Press any key to continue . . .
*/
