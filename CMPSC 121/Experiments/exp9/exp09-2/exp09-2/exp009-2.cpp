//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 04
//File: P:\Private\CMPSC 121\Activities\Activity4\activity4\activity4
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	//setting precision 
	cout << fixed << showpoint << setprecision(2);
	char choice; // Y for yes or N for no
	//global variables
	int num, out, walk, single, Double, triple, homeRun, hit, counter, NoOfHits;
	double battingAverage;
	//getting random numbers each time
	srand(time(0));
	
	// pre test loop
	do
	{
		//intializing the variables
		out = 0;
		walk = 0;
		counter = 0;
		single = 0;
		Double = 0;
		triple = 0;
		NoOfHits = 0;
		homeRun = 0;
		hit = 0;
		battingAverage = 0.0;

		for (int i = 0; i < 1000; i++) //loop will go on 1000 times before stopping to get random numbers
		{
			
			num = rand() % 1000 + 1;

			if (num <= 583)
			{
				out++;
			}
			else if (num <= 681 && num > 583)
			{
				walk++;
			}
			else if (num <= 904 && num > 681)
			{
				single++;		
			}
			else if (num <= 957 && num > 904)
			{
				Double++;
			}
			else if (num <= 985 && num > 957)
			{
				triple++;
			}
			else if (num > 985)
			{
				homeRun++;
			}
			
		} 
		 // display on the screen
		cout << "Number of Outs: " << out << endl;
		cout << "Number of Walks: " << walk << endl;
		cout << "Number of Singles: " << single << endl;
		cout << "Number of Doubles: " << Double << endl;
		cout << "Number of Triples: " << triple << endl;
		cout << "Number of Home Run: " << homeRun << endl;
		
		// caluclating # of hits
		NoOfHits = (single + Double + triple + homeRun);
		
		//calulating the bating average
		battingAverage = (NoOfHits) / ((1000 - walk)*1.0);
		cout << "The Batting Average is: " << battingAverage << endl;

		// ask to continue 
		cout << "Would you like to continue? Y or N\n";
		cin >> choice;
	} while (choice == 'Y'|| choice == 'y'); // this loop ends when the user enter N for no

return 0;
	
}
/*
1)

Number of Outs: 580
Number of Walks: 94
Number of Singles: 222
Number of Doubles: 64
Number of Triples: 24
Number of Home Run: 16
The Batting Average is: 0.36
Would you like to continue? Y or N
Y
Number of Outs: 600
Number of Walks: 99
Number of Singles: 219
Number of Doubles: 49
Number of Triples: 19
Number of Home Run: 14
The Batting Average is: 0.33
Would you like to continue? Y or N
Y
Number of Outs: 603
Number of Walks: 100
Number of Singles: 201
Number of Doubles: 51
Number of Triples: 34
Number of Home Run: 11
The Batting Average is: 0.33
Would you like to continue? Y or N
y
Number of Outs: 568
Number of Walks: 100
Number of Singles: 238
Number of Doubles: 51
Number of Triples: 32
Number of Home Run: 11
The Batting Average is: 0.37
Would you like to continue? Y or N
N
Press any key to continue . . .

2)
Number of Outs: 587
Number of Walks: 95
Number of Singles: 234
Number of Doubles: 42
Number of Triples: 23
Number of Home Run: 19
The Batting Average is: 0.35
Would you like to continue? Y or N
y
Number of Outs: 585
Number of Walks: 97
Number of Singles: 226
Number of Doubles: 51
Number of Triples: 27
Number of Home Run: 14
The Batting Average is: 0.35
Would you like to continue? Y or N
Y
Number of Outs: 606
Number of Walks: 90
Number of Singles: 214
Number of Doubles: 46
Number of Triples: 30
Number of Home Run: 14
The Batting Average is: 0.33
Would you like to continue? Y or N
Y
Number of Outs: 572
Number of Walks: 119
Number of Singles: 209
Number of Doubles: 53
Number of Triples: 33
Number of Home Run: 14
The Batting Average is: 0.35
Would you like to continue? Y or N
y
Number of Outs: 596
Number of Walks: 91
Number of Singles: 213
Number of Doubles: 51
Number of Triples: 33
Number of Home Run: 16
The Batting Average is: 0.34
Would you like to continue? Y or N
N
Press any key to continue . . .

*/