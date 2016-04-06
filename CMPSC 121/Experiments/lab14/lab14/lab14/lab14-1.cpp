//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 14
//File: P:\Private\CMPSC 121\Experiments\lab14\lab14\lab14\lab14-1
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: Ron Delporto

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

//Funtion Prototypes
bool readFile(vector <string> &partNumbers, vector <char> &partClasses, vector <int> &partOHB, vector<double> &partCost);
int displayMenu();
double totalCost(const vector<int> &partOHB, const vector<double> &partCost);
void countByClass(const vector<char> & partClasses, vector <int> &classCounts);
double costForClass(char classIn, const vector<char> &partClasses, const vector <int> &partOHB, const vector <double> & partCost);
string highestCost(const vector <string> &partNumbers, const vector <int> &partOHB, const vector <double> &partCost);
string lowestCost(const vector <string> &partNumbers, const vector <int> &partOHB, const vector <double> &partCost);
void displayCount(const vector <int> &classCounts);

int main()
{
	//function calls for each category
	vector <string> partNumbers;
	vector <char> partClasses;
	vector <int> partOHB;
	vector<double> partCost;
	vector <int> classCounts;

	// local variables 
	bool check; 
	char classIn;  
	double total, cost;
	string highest, lowest;
	int displayChoice;
	
	//set formatting
	cout << fixed << showpoint << setprecision(2);

	//function call to check if the file was read in properly
	check = readFile(partNumbers, partClasses, partOHB, partCost);

	//if file was read, continue.
	if (check == true)
	{
		do
		{
			//function call to show menu
			displayChoice = displayMenu();

			//use switch statement in order to switch between user choice and to call 
			//certain functions depending on choice.
			switch (displayChoice)
			{
			case 1:  
				total = totalCost(partOHB, partCost);
				cout << "Total cost of inventory is $" << total << endl;
				break;
			case 2: 
				countByClass(partClasses, classCounts);
				displayCount(classCounts);
				break;
			case 3: 
				cout << "Which Class?\n";
				cin >> classIn;
				classIn = toupper(classIn);
				cost = costForClass(classIn, partClasses, partOHB, partCost);
				cout << "Cost of inventory for class " << classIn << " is $" << cost << ".\n";
				break;
			case 4:
				highest = highestCost(partNumbers, partOHB, partCost);
				cout << "The part with the highest cost of inventory is " << highest << endl;
				break;
			case 5:
				lowest = lowestCost(partNumbers, partOHB, partCost);
				cout << "The part with the lowest cost of inventory is " << lowest << endl;
				break;
			case 6:
				cout << "Thank you for using this program!\n";
					break;
			}
		} while (displayChoice != 6);
	}
	return 0;
}

bool readFile(vector <string> &partNumbers, vector <char> &partClasses, vector <int> &partOHB, vector<double> &partCost)
{
	ifstream fin;
	fin.open("parts.txt");
	string pNum;
	char pClass;
	int pOHB;
	double pCost;
	bool OK = false;

	//check if file exists
	if (fin.fail())
		cout << "Unable to open File\n";
	else
	{
		OK = true;

		//read in file
		while (fin >> pNum >> pClass >> pOHB >> pCost)
		{
			//inlcude push_back operater to add more values and strings into each vector
			partNumbers.push_back(pNum);
			partClasses.push_back(pClass);
			partOHB.push_back(pOHB);
			partCost.push_back(pCost);
		}
	}
	fin.close();
	return OK;
}

int displayMenu()
{
	//display Menu
	int choice = 0;
		cout << "\tR E P O R T  M E N U\n";
		cout << "1. Total cost of inventory. \n";
		cout << "2. A count of parts of each class. \n";
		cout << "3. Cost of inventory for a class. \n";
		cout << "4. Part with the highest cost of inventory. \n";
		cout << "5. Part with the lowest cost of inventory. \n";
		cout << "6. Exit. \n";
		cin >> choice;
	
		cout << "Your choice was: " << choice << endl;
	return choice;
}

double totalCost(const vector<int> &partOHB, const vector<double> &partCost)
{
	double total = 0;

	//cycle through each partCost category 
	int length = partCost.size();
	
	//use for loop to cycle through parallel vectors to calculate total
	for (int i = 0; i < length; i++)
	{
		total += (partOHB[i] * partCost[i]);
	}
	return total;
}

void countByClass(const vector<char> & partClasses, vector <int> &classCounts)
{
	//intialize count for each partClass with a 0
	int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0, countF = 0;
	int length = partClasses.size();
	char character;

	for (int i = 0; i < length; i++)
	{
		//use switch statement to sort through each character in partClasses category
		//and then add them up.
		character = partClasses[i];
		switch (character)
		{
		case'A': countA++;
			break;
		case'B': countB++;
			break;
		case'C': countC++;
			break;
		case'D': countD++;
			break;
		case'E': countE++;
			break;
		case'F': countF++;
			break;
		}
	}
	//assign each count part class to classCounts using the push_back assignment
	classCounts.push_back(countA);
	classCounts.push_back(countB);
	classCounts.push_back(countC);
	classCounts.push_back(countD);
	classCounts.push_back(countE);
	classCounts.push_back(countF);
}

double costForClass(char classIn, const vector <char> &partClasses, const vector <int> &partOHB, const vector <double> & partCost)
{
	double totalValue = 0;

	for (int i = 0; i < partOHB.size(); i++)
	{
		//compare classIn with the partclasses category to verify class, then multiply
		//the parallel vectors and then add to total
		if (classIn == partClasses[i])
			totalValue += (partOHB[i] * partCost[i]);
	}
	return totalValue;
}

string highestCost(const vector <string> &partNumbers, const vector <int> &partOHB, const vector <double> &partCost)
{
	string highest;
	double hold;
	
	//declare first multiplied parallel vector as the biggest
	double biggest = (partOHB[0] * partCost[0]);

	for (int i = 1; i < partNumbers.size(); i++)
	{
		//hold each multipied parallel vector initially to compare
		//with the biggest vector calculated before
		hold = (partOHB[i] * partCost[i]);
		if (hold > biggest)
		{
			biggest = hold;
			highest = partNumbers[i];
		}
	}
	return highest;
}

string lowestCost(const vector <string> &partNumbers, const vector <int> &partOHB, const vector <double> &partCost)
{
	string lowest;
	double hold;
	
	//declare first multiplied parallel vector as the smallest
	double smallest = (partOHB[0] * partCost[0]);
	
	for (int i = 1; i < partNumbers.size(); i++)
	{
		//hold each multipied parallel vector initially to compare
		//with the smallest vector calculated before
		hold = (partOHB[i] * partCost[i]);
		if (hold < smallest)
		{
			smallest = hold;
			lowest = partNumbers[i];
		}
	}
	return lowest;
}

void displayCount(const vector <int> &classCounts)
{
	char Class = 65; // Intialize letter to ASCII code 65(same as Letter A)

	cout << "Count of parts by class\n";

	//display each letter(class) with the appropriate class count
	for (int i = 0; i < classCounts.size(); i++)
	{
		cout << Class << "    " << classCounts[i] << endl;
		Class++;
	}
}


/*EXECUTION SAMPLE:

1)

R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
1
Your choice was: 1
Total cost of inventory is $343136.99
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
2
Your choice was: 2
Count of parts by class
A    85
B    70
C    76
D    61
E    7
F    6
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was: 3
Which Class?
a
Cost of inventory for class A is $191519.80.
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
4
Your choice was: 4
The part with the highest cost of inventory is P-27850
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
5
Your choice was: 5
The part with the lowest cost of inventory is P-30538
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
6
Your choice was: 6
Thank you for using this program!
Press any key to continue . . .

2)

R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was: 3
Which Class?
b
Cost of inventory for class B is $75690.41.
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was: 3
Which Class?
c
Cost of inventory for class C is $48908.76.
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was: 3
Which Class?
d
Cost of inventory for class D is $22735.34.
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was: 3
Which Class?
e
Cost of inventory for class E is $3691.77.
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
3
Your choice was: 3
Which Class?
f
Cost of inventory for class F is $590.91.
R E P O R T  M E N U
1. Total cost of inventory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with the highest cost of inventory.
5. Part with the lowest cost of inventory.
6. Exit.
6
Your choice was: 6
Thank you for using this program!
Press any key to continue . . .






*/