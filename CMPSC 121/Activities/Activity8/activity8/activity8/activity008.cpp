//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 08
//File: P:\Private\CMPSC 121\Activities\Activity8\activity8\activity8\activity008
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
	int books;
	int points;
	const int no_b = 0, // these variables hold the amount of points given
		one_b = 5,
		two_b = 15,
		three_b = 30,
		four_b = 60,
		over_b = 60;   // Four or more books

	cout << "How many books were purchased this month? \n";
	cin >> books;

	if (books < 0)
	{
		cout << "You have entered a Negative number.\n";
		cout << "Please start again and enter a positive number.\n";
		return 0;
	}

	switch (books)
	{
	case 0:
		points = no_b;
		break;
	case 1:
		points = one_b;
		break;
	case 2:
		points = two_b;
		break;
	case 3:
		points = three_b;
		break;
	case 4:
		points = four_b;
		break;
	default:
		points = over_b;
		break;
	}
	cout << "====================================================\n";
	cout << "Congratulations! You bought " << books << " books this month,\n";
	cout << "and earned " << points << " points! \n";
	cout << "====================================================\n";

	return  0;
}

/*
Execution Sample:
1)
How many books were purchased this month?
1
====================================================
Congratulations! You bought 1 books this month,
and earned 5 points!
====================================================
Press any key to continue . . .

2)
How many books were purchased this month?
2
====================================================
Congratulations! You bought 2 books this month,
and earned 15 points!
====================================================
Press any key to continue . . .

3)
How many books were purchased this month?
3
====================================================
Congratulations! You bought 3 books this month,
and earned 30 points!
====================================================
Press any key to continue . . .

4)
How many books were purchased this month?
4
====================================================
Congratulations! You bought 4 books this month,
and earned 60 points!
====================================================
Press any key to continue . . .

5)
How many books were purchased this month?
12
====================================================
Congratulations! You bought 12 books this month,
and earned 60 points!
====================================================
Press any key to continue . . .

6)
How many books were purchased this month?
-52
You have entered a Negative number.
Please start again and enter a positive number.
Press any key to continue . . .

*/