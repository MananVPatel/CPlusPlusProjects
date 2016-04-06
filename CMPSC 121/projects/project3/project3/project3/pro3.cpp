//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Project: 3
//File: P:\Private\CMPSC 121\projects\project3\project3\project3\pro3\
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: Ron Delporto


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

//Function Prototypes

int displayMenu();

// Fills vectors. Called once at beginning of program!
bool getData(vector <string> &symbols, vector <int> &shares, vector <double> &prices, vector <char> &ratings);

//sorts vectors in order by symbol (calls swapper)
void sort(vector<string>& symbols, vector<int>& shares, vector<double>& prices,
	vector<char>& ratings);

//Called from Menu

//Menu choice #1
void addStock(vector <string>& symbols, vector <int>& shares, vector <double>& prices,
	vector <char>& ratings);

//Menu choice #2
void deleteStock(vector <string>& symbols, vector <int>& shares, vector <double>& prices,
	vector <char>& ratings);

//Menu choice #3
void printReport(const vector <string>& symbols, const vector <int>& shares,
	const vector <double>& prices, const vector <char> & ratings);

//Called by other functions as needed

//binary search
int binSearch(string key, const vector<string> &symbols);

//Ask for symbol to look up
string getSymbol();

//gets remaining info to add a part number
void getMoreData(int &shares, double &prices, char &ratings);

//inserts part number data into vectors
void insert_data(vector <string>& symbols, vector <int>& shares, vector <double>& prices,
	vector <char>& ratings, string symbol_in, int shares_in, double price_in, char rating_in);

//Filters by rating and price range
void filter(const vector <string>& symbols, const vector <double>& prices, vector <char>& ratings);

//displays info on part number
void display(const vector<string>&symbols, const vector<int>& shares,
	const vector<double>& prices, const vector<char>& ratings, const vector <int> &itemsToDisplay);

//Called at end of main

//prints search stats
void print_stats(int searches);

//writes out file
void put_data(const vector <string>& symbols, const vector <int>& shares, const vector <double>& prices, const vector <char> & ratings);

//templated swap function called by sort
template<class CType>
void swapper(CType& a, CType& b)
{
	CType temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	cout << fixed << showpoint << setprecision(2);

	vector <string> symbols;
	vector <int> shares;
	vector <double> prices;
	vector <char> ratings;

	bool verify; 
	int choice;
	int searches = 0;

	//function call to verify if the data was read properly
	verify = getData(symbols, shares, prices, ratings);
	if (verify == true)
	{
		//sort the data that was read in from the file
		sort(symbols, shares, prices, ratings);
		do
		{
			choice = displayMenu();
			switch (choice)
			{
			case 1:
				addStock(symbols, shares, prices, ratings);
				break;
			case 2:
				deleteStock(symbols, shares, prices, ratings);
				break;
			case 3:
				filter(symbols, prices, ratings);
				break;
			case 4:
				printReport(symbols, shares, prices, ratings);
				searches++;
				break;
			}

		} while (choice < 5);

		print_stats(searches); // print the amount of searches performed for printing report
		put_data(symbols, shares, prices, ratings); // send modified data out to file

	}
	return 0;
}


//read in data from the stocks.txt file
bool getData(vector <string> &symbols, vector <int> &shares, vector <double> &prices, vector <char> &ratings)
{
	ifstream fin;
	string sym;
	int shar;
	double price;
	char rat;

	fin.open("stocks.txt"); // open file
	bool OK = false; // flag variable

	if (fin.fail())
		cout << "Unable to Open File\n";
	else
	{
		OK = true;
		while (fin >> sym >> shar >> price >> rat)
		{
			//send new info from the data file into respective vectors
			symbols.push_back(sym);
			shares.push_back(shar);
			prices.push_back(price);
			ratings.push_back(rat);
		}
	}
	fin.close(); //close file
	return OK;
}


// alphabetically sort the data in the file by symbols
void sort(vector<string>& symbols, vector<int>& shares, vector<double>& prices,
	vector<char>& ratings)
{
	//Shell sort
	int i, j, increment;
	//create temporary variables to hold info for swapping 
	string temp_symbol;
	int temp_shares;
	double temp_prices;
	char temp_ratings;
	increment = 3;
	while (increment > 0)
	{
		for (i = 0; i < symbols.size(); i++)
		{
			j = i;

			// assign values from the vectors to the temporary variables
			temp_symbol = symbols[i];
			temp_shares = shares[i];
			temp_prices = prices[i];
			temp_ratings = ratings[i];

			//call swapper function to swap each category to sort out data
			while ((j >= increment) && (symbols[j - increment] > temp_symbol))
			{
				swapper(symbols[j], symbols[j - increment]);
				swapper(shares[j], shares[j - increment]);
				swapper(prices[j], prices[j - increment]);
				swapper(ratings[j], ratings[j - increment]);

				j = j - increment;
			}

			// finally assign modified data back to original vectors
			symbols[j] = temp_symbol;
			shares[j] = temp_shares;
			prices[j] = temp_prices;
			ratings[j] = temp_ratings;
		}
		
		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
}

// function adds stock into the current data file 
void addStock(vector <string>& symbols, vector <int>& shares, vector <double>& prices,
	vector <char>& ratings)
{
	string stock;
	char rating_in;
	int shares_in;
	double price_in;
	string symbol_in;
	cout << "Enter symbol of stock to add\n";
	cin >> stock;

	// change stock entered to uppercase
	for (int i = 0; i < stock.length(); i++)
	{
		stock[i] = toupper(stock[i]);
	}

	//search if stock entered already exists, let the user know it exists
	if (binSearch(stock, symbols) != -1)
	{
		cout << "The stock is already listed!\n";
	}

	// otherwise call getMoreData function and insert_data function to properly execute this function
	else
	{
		getMoreData(shares_in, price_in, rating_in);
		insert_data(symbols, shares, prices, ratings, stock, shares_in, price_in, rating_in);
	}

}

void deleteStock(vector <string>& symbols, vector <int>& shares, vector <double>& prices,
	vector <char>& ratings)
{
	string symbol;
	int i, location;
	cout << "Enter symbol of stock to delete\n";
	cin >> symbol;
	
	//change symbol entered to uppercase
	for (int i = 0; i < symbol.length(); i++)
	{
		symbol[i] = toupper(symbol[i]);
	}

	//search if stock entered already exists, let the user know it exists
	location = binSearch(symbol, symbols);
	if (location == -1)
	{
		cout << "That stock is not on the list!\n";
	}
	//otherwise delete the stock symbol the user provided along with the accompanying information
	else
	{
		i = location;

		while (i < symbols.size() - 1)
		{
			symbols[i] = symbols[i + 1];
			shares[i] = shares[i + 1];
			prices[i] = prices[i + 1];
			ratings[i] = ratings[i + 1];
			i++;
		}

		//resize each vector to have properly formatting
		symbols.resize(symbols.size() - 1);
		shares.resize(shares.size() - 1);
		prices.resize(prices.size() - 1);
		ratings.resize(ratings.size() - 1);
	}

}

int displayMenu()
{
	int choice = 0;
	do
	{
		cout << "Select desired Action\n";
		cout << "1. Add a stock\n";
		cout << "2. Remove a stock\n";
		cout << "3. Filter by rating and price range\n";
		cout << "4. Print a report\n";
		cout << "5. End program\n";
		cin >> choice;
	}while (choice < 1 || choice > 5);

	cout << "Your choice was: " << choice << endl;
	return choice;
}

//function does a binary search to see if something already exists
int binSearch(string key, const vector<string> &symbols)
{
	int first = 0,
		last = symbols.size() - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (symbols[middle] == key)
		{
			found = true;
			position = middle;
		}
		else if (symbols[middle] > key)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

string getSymbol()
{
	string symb;
	cout << "Which symbol would you like to look up?\n";
	cin >> symb;
	return symb;
}

void getMoreData(int &shares, double &prices, char &ratings)
{
	cout << "Please enter the amount of shares!\n";
	cin >> shares;
	cout << "Please enter the price!\n";
	cin >> prices;
	do
	{
		cout << "Please Enter the rating for the part number!\n";
		cin >> ratings;
		if (ratings < 'A' || ratings > 'F' || ratings == 'E')
		{
			cout << "Invalid Entry! Please re-enter rating!\n";
			cin >> ratings;
		}
	} while (ratings < 'A' || ratings > 'F' || ratings == 'E');

	cout << endl;
}


//inserts data into the file when entered by user(needs to be called in another function for this to occur)
void insert_data(vector <string>& symbols, vector <int>& shares, vector <double>& prices,
	vector <char>& ratings, string symbol_in, int shares_in, double price_in, char rating_in)
{

	int i;

	i = symbols.size() - 1;

	// resize all vectors to properly format the file
	symbols.resize(symbols.size() + 1);
	shares.resize(shares.size() + 1);
	prices.resize(prices.size() + 1);
	ratings.resize(ratings.size() + 1);

	while (i >= 0 && symbol_in < symbols[i])
	{
		symbols[i + 1] = symbols[i];
		shares[i + 1] = shares[i];
		prices[i + 1] = prices[i];
		ratings[i + 1] = ratings[i];

		i--;
	}
	symbols[i + 1] = symbol_in;
	shares[i + 1] = shares_in;
	prices[i + 1] = price_in;
	ratings[i + 1] = rating_in;
}

void filter(const vector <string>& symbols, const vector <double>& prices, vector <char>& ratings)
{
	char rating;
	double low_price, high_price;
	cout << "Enter rating, low price, and high price.\n";
	cin >> rating >> low_price >> high_price;
	cout << "\tS T O C K S   M E E T I N G  C R I T E R I A                        " << endl;

	//check to see if the user entry matches contents of the file and if so execute the body 
	for (int i = 0; i < symbols.size(); i++)
	{
		if ((ratings[i] == rating) && (prices[i] >= low_price) && (prices[i] <= high_price))
		{
			cout << symbols[i] << setw(16 - symbols[i].size()) << prices[i] << setw(8) << ratings[i] << endl;
		}
	}
	cout << endl;
}

void printReport(const vector <string>& symbols, const vector <int>& shares,
	const vector <double>& prices, const vector <char> & ratings)
{
	vector <int> itemsToDisplay;
	string key;
	int index;
	cout << "Enter a symbol, mark end with ^^. \n";

	do
	{
		
		key = getSymbol();
		index = binSearch(key, symbols); // perform binary search for existence
		if (index != -1)
		{
			itemsToDisplay.push_back(index); // if symbol exists, push it back into the itemsToDisplay vector
		}
		else if (key != "^^")
			{
				cout << key << " is not in the list!\n";
			}
	} while (key != "^^");
	display(symbols, shares, prices, ratings, itemsToDisplay); // display info on screen

}

// displays content on screen
void display(const vector<string>&symbols, const vector<int>& shares,
	const vector<double>& prices, const vector<char>& ratings, const vector <int> &itemsToDisplay)
{
	int j;
	cout << "\tS T O C K  R E P O R T" << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Symbol\t Shares\t Price\t Rating\n";

	for (int i = 0; i < itemsToDisplay.size(); i++)
	{
		j = itemsToDisplay[i];
		cout << symbols[j] << setw(14 - symbols[j].size())
			<< shares[j] << setw(7) << prices[j] << setw(7) << ratings[j] << endl;
	}

}

// prints how many searches were performed for printing the report
void print_stats(int searches)
{
	cout << "There were " << searches << " searches performed today." << endl;
}

//writes data back out to the stocks.txt file
void put_data(const vector <string>& symbols, const vector <int>& shares, const vector <double>& prices, const vector <char> & ratings)
{
	ofstream fout;
		fout.open("stocks.txt");
		int i;
	for (i = 0; i < symbols.size()-1; i++)
	{
		fout << symbols[i] << "  " << shares[i] << "  " << prices[i] << "  " << ratings[i] << endl;
	}
	fout << symbols[i] << "  " << shares[i] << "  " << prices[i] << "  " << ratings[i];
	fout.close();
	cout << "The file is now updated." << endl;
}

/*
#1)
Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
1
Your choice was: 1
Enter symbol of stock to add
abcd
Please enter the amount of shares!
10
Please enter the price!
25.25
Please Enter the rating for the part number!
C

Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
5
Your choice was: 5
There were 0 searches performed today.
The file is now updated.
Press any key to continue . . .


#2)
Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
2
Your choice was: 2
Enter symbol of stock to delete
abcd
Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
5
Your choice was: 5
There were 0 searches performed today.
The file is now updated.
Press any key to continue . . .


#3)
Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
3
Your choice was: 3
Enter rating, low price, and high price.
C 23.00 24.00
S T O C K S   M E E T I N G  C R I T E R I A
AF-C       23.84       C
AFA        23.93       C
AFSD       23.72       C
AIY        23.86       C
ALLY       23.95       C
AMT-A      23.80       C
CAP        23.14       C
CELP       24.00       C
CRK        23.20       C
CTB        23.97       C
DBL        23.34       C
EBS        23.31       C
ELJ        23.65       C
ETH        23.83       C
FBS-A      23.80       C
FHN-A      23.71       C
FI         23.93       C
GMED       23.19       C
GRT-I      23.45       C
GS-I       23.30       C
GS-J       23.92       C
HT-C       23.82       C
HTS-A      23.89       C
IMS        23.74       C
JLS        23.75       C
JMT        23.18       C
JPI        23.02       C
JZC        23.84       C
KNX        23.15       C
MET-A      23.20       C
MGU        23.92       C
NEE-G      23.93       C
OFG-B      23.28       C
PGP        23.52       C
PMT        23.74       C
PPX        23.76       C
PSA-T      23.24       C
RAS-A      23.45       C
RBA        23.97       C
RBS-Q      23.85       C
RSO-A      23.74       C
SJR        23.89       C
TEU-C      23.60       C
TNP-B      23.93       C
VTRB       23.27       C

Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
5
Your choice was: 5
There were 0 searches performed today.
The file is now updated.
Press any key to continue . . .


#4)
Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
4
Your choice was: 4
Enter a symbol, mark end with ^^.
Which symbol would you like to look up?
ACCO
Which symbol would you like to look up?
GE
Which symbol would you like to look up?
IBM
Which symbol would you like to look up?
KMI
Which symbol would you like to look up?
LOW
Which symbol would you like to look up?
PFE
Which symbol would you like to look up?
^^
S T O C K  R E P O R T
Symbol   Shares  Price   Rating
ACCO     10441   5.97      D
GE       10318  25.51      D
IBM       2305 195.04      A
KMI       4437  32.63      C
LOW       5344  46.66      C
PFE       6739  30.50      A
Select desired Action
1. Add a stock
2. Remove a stock
3. Filter by rating and price range
4. Print a report
5. End program
5
Your choice was: 5
There were 1 searches performed today.
The file is now updated.
Press any key to continue . . .


*/