//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 10
//File: P:\Private\CMPSC 121\Experiments\exp10\exp10\exp10\exp010
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: Ron DelPorto

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//global constants
const double INCHESINLINEARFOOT = 12.0;
const double INCHESINONESQUAREFOOT = 144.0;
const double PINECOST = 0.89;
const double FIRCOST = 1.09;
const double CEDARCOST = 2.26;
const double MAPLECOST = 2.26;
const double OAKCOST = 3.10;

// function prototypes
bool validateType(char t);
double calcBoardFeet(double th, double wid, double len);
double calcCost(char type, int numP, double bf);
string getTypeName(char type);
void getData(char & woodType, int & numPieces, double & thickness, double &
	width, double & length);


int main()
{
	//variables
	char woodType, choice; // wType = wood type
	int numPieces;
	double thickness, width, length, totalCost, calculateBoardFeet, calculateCost;
	string woodTypeName;

	//outer do-while loop (displays totalcost and accepts choice by user)
	do
	{
		totalCost = 0.0;
		
		//inner do-while loop (displays details about the cost of lumber type)
		do
		{
			getData(woodType, numPieces, thickness, width, length);
			if (woodType != 'T')
			{
				calculateBoardFeet = calcBoardFeet(thickness, width, length);
				calculateCost = calcCost(woodType, numPieces, calculateBoardFeet);
				woodTypeName = getTypeName(woodType) + ", cost: $";

				cout << fixed << showpoint << setprecision(2);
				cout << numPieces << setw(5) << thickness << " X " << width << " X " << length << setw(16) << woodTypeName << calculateCost << endl;
				totalCost += calculateCost;
			}
				
		} while (woodType != 'T'); 

		cout << "Total Cost: $" << totalCost << endl;
		cout << "Would you like to enter more purchases?\n";
		cin >> (choice);

	} while (toupper(choice) == 'Y');
	return 0;
}

// getData function (user inputs details about lumber into this function)
void getData(char & woodType, int & numPieces, double & thickness, double &
	width, double & length)
{
	bool OK = false;
	cout << "Enter Item: ";
	do
	{
		cin >> woodType;
		woodType = toupper(woodType);
		OK = validateType(woodType);
		if (!OK)
		{
			cout << woodType << " is not a valid type! Re-Enter: \n";
		}
	} while (OK != true);


	if (OK && woodType != 'T')
	{
		cout << "Enter number of pieces and thickness width and length\n";
		cin >> numPieces >> thickness >> width >> length;
	}
}

// validateType function (this function validates the lumber type entered by the user in getData. once a bool value is returned, this function is sent to getData to further calculate other details)  
bool validateType(char t)
{
	bool OK = false;
	if (t == 'P' || t == 'F' || t == 'C' || t == 'M' || t == 'O' || t == 'T')
	{
		OK = true;
	}
	return OK;
}
// this function calculates the board feet using the details entered by the user
double calcBoardFeet(double th, double wid, double len) // th = thickness, wid = width, len = length
{
	double boardFeet;
	boardFeet = (th * wid * (len * INCHESINLINEARFOOT)) / (INCHESINONESQUAREFOOT);
	return boardFeet;
}

// this function calculates the cost of the lumber.
double calcCost(char type, int numP, double bf) // bf = board feet, numP = number of pieces
{
	double cost;
	switch (type)
	{
	case 'P': cost = bf*numP*PINECOST; break;
	case 'F': cost = bf*numP*FIRCOST; break;
	case 'C': cost = bf*numP*CEDARCOST; break;
	case 'M': cost = bf*numP*MAPLECOST; break;
	case 'O': cost = bf*numP*OAKCOST; break;
	}
	return cost;
}

// this function assigns the words to the designated lumber type letters entered by the user. 
string getTypeName(char type)
{
	string name;
	switch (type)
	{
	case 'P': name = "Pine"; break;
	case 'F': name = "Fir"; break;
	case 'C': name = "Cedar"; break;
	case 'M': name = "Maple"; break;
	case 'O': name = "Oak"; break;
	}
	return name;
}
/*
1)

Enter Item: i
I is not a valid type! Re-Enter:
o
Enter number of pieces and thickness width and length
100 2.5 3 20
100 2.50 X 3.00 X 20.00    Oak, cost: $3875.00
Enter Item: p
Enter number of pieces and thickness width and length
150 3 3.5 22
150 3.00 X 3.50 X 22.00   Pine, cost: $2569.88
Enter Item: t
Total Cost: $6444.88
Would you like to enter more purchases?
n
Press any key to continue . . .

2)
Enter Item: e
E is not a valid type! Re-Enter:
d
D is not a valid type! Re-Enter:
M
Enter number of pieces and thickness width and length
75 2.8 3.4 25
75 2.80 X 3.40 X 25.00  Maple, cost: $3361.75
Enter Item: C
Enter number of pieces and thickness width and length
175 2.6 3.2 23
175 2.60 X 3.20 X 23.00  Cedar, cost: $6306.91
Enter Item: t
Total Cost: $9668.66
Would you like to enter more purchases?
n
Press any key to continue . . .



*/
