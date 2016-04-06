//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 13
//File: P:\Private\CMPSC 121\Experiments\exp13\lab13\lab13\lab13-0
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<random>
using namespace std;

//constant variables
const int CAPACITY = 20; //Array size


//Function Prototypes
bool readFile(string c[], int &size);
void getVotes(int v[], int size);
void calculatePercents(int v[], double p[], int size);
void displayResults(string c[], int v[], double p[], int size);

int main()
{
	bool read_F = false;
	string candidates[CAPACITY]; // array of candidates
	int votes[CAPACITY]; //array of votes
	double percents[CAPACITY]; // array of percents
	int size = CAPACITY;


	//function calls
	read_F = readFile(candidates, size);

	if (read_F == true)
	{
		getVotes(votes, size);
		calculatePercents(votes, percents, size);
		displayResults(candidates, votes, percents, size);
	}
	return 0;
}

bool readFile(string c[], int &size)
{
	ifstream fin;
	int i = 0;
	bool OK = false;
	fin.open("candidates.txt");

	if (fin.fail())
	{
		cout << "Unable to open file\n";
	}
	else
	{
		OK = true;
		
		//read in contents of the file
		while (i < size && fin >> c[i])
		{
			i++; 
		}
	}
	size = i; //sets size to the last i value
	fin.close();
	return OK;
}

//gets random values for votes each time
void getVotes(int v[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		v[i] = rand() % 7501 + 1500;
	}
}

void calculatePercents(int v[], double p[], int size)
{
	double total = 0;
	//adding all the values of votes to total
	for (int i = 0; i < size; i++)
	{
		total += v[i];
	}
	//calculating percentages for the votes values
	for (int i = 0; i < size; i++)
	{
		p[i] = (v[i] / total) * 100;
	}
}
void displayResults(string c[], int v[], double p[], int size)
{
	int counter;
	int mostVotes;
	string winner = c[0];
	mostVotes = v[0];
	
	//compares the votes' values with the intial votes' value to find the winner and the most votes' value.
	for (counter = 1; counter < size; counter++)
	{
		if (v[counter] > mostVotes)
		{
			mostVotes = v[counter];
			winner = c[counter];
		}
	}
	//display on screen
	cout << "Candidates\tVotes\tPercent\n";

	for (int i = 0; i < size; i++)
	{
		cout << setw(15) << left << c[i] << setw(10) << v[i] << fixed << setprecision(1) << p[i] << "%" << endl;
	}
	cout << "The winner is " << winner << " with " << mostVotes << " votes!" << endl;
}

/*
1)
Candidates      Votes   Percent
Johnson        4511      4.7%
Crosby         4740      4.9%
Guffy          5731      5.9%
Mancini        2071      2.1%
Hong           8563      8.9%
Fremont        5414      5.6%
Iglesias       8414      8.7%
Bronski        8593      8.9%
Huffnagle      4105      4.2%
Maata          5457      5.6%
Malkin         8770      9.1%
Polamalu       4597      4.8%
O'Brien        6407      6.6%
Fahd           6043      6.3%
Santini        6993      7.2%
Rodriguez      6184      6.4%
The winner is Malkin with 8770 votes!
Press any key to continue . . .

2)
Candidates      Votes   Percent
Johnson        4644      6.6%
Crosby         4438      6.3%
Guffy          2264      3.2%
Mancini        5627      8.0%
Hong           5477      7.8%
Fremont        2570      3.6%
Iglesias       4953      7.0%
Bronski        1881      2.7%
Huffnagle      3217      4.6%
Maata          8029      11.4%
Malkin         2706      3.8%
Polamalu       6403      9.1%
O'Brien        4098      5.8%
Fahd           3815      5.4%
Santini        6869      9.7%
Rodriguez      3650      5.2%
The winner is Maata with 8029 votes!
Press any key to continue . . .


*/

