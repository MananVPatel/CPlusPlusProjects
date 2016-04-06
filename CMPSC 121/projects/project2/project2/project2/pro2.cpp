//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Project: 02
//File: P:\Private\CMPSC 121\projects\project2\project2\project2\pro2
//purpose: To determine if each credit card number read from a file is valid using luhn formula.
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//variables used throughout main
	ifstream inputFile;
	long long number, ccsave;
	int sum, valid_counter = 0, invalid_counter = 0, totalCount;
	string cardType;
	int count; // counts the amount of digits in a credit card number
	inputFile.open("cardnumbers.txt"); 
	if (inputFile)
	{
		while (inputFile >> number)
		{
			ccsave = number; //saves the credit card number after its read in
			int digit, first_digit;
			int sumOfAllDigits = 0;
			count = 0; // intializing the variable count
			int sumDigit = 0;//holds the value of each digit in a Credit card number 
			do
			{
				count++;
				digit = number % 10; // yields the last digit
				first_digit = digit; // holds the last digit
				if (count % 2 == 0) // if even
				{
					digit *= 2;
					// if digit is > 9, the if statement below seperates the two digits and adds them together
					if (digit > 9)
					{
						int dig1, dig2;
						dig1 = digit % 10;
						digit /= 10;
						dig2 = digit;
						sumDigit = dig1 + dig2;
					}
					else sumDigit = digit; // if digit is not greater than 9 after multiplying by 2, digit is the original digit
				}
				else
					sumDigit = digit; // if digit is not greater than 9, digit is the original digit

				sumOfAllDigits += sumDigit;
				number /= 10; // eliminates the last digit

			} while (number); 
			
			sum = sumOfAllDigits;// sum holds the sum of all digits of a credit card number

			//determines the card type of all the cards in the file by evaluating the cases listed below.
			switch (first_digit)
			{
				case 4:
					cardType = "Visa";
				break;

				case 5:
					cardType = "Mastercard";
				break;

				case 6:
					cardType = "Discover";
				break;

				default:
					cardType = "Unknown";
				break;
			}
			//display on screen

			// checks if the LUHN formula was executed properly
			if (sum % 10 == 0) 
			{
				cout << "This " << cardType << " card <" << ccsave << "> is VALID!\n";
				valid_counter++;
			}
			else
			{
				cout << "This " << cardType << " card <" << ccsave << "> is NOT VALID!\n";
				invalid_counter++;
			}
		}
		// calculates Total Cards; valid and invalid
		totalCount = valid_counter + invalid_counter;
		cout << endl;
		cout << "Valid Cards: " << valid_counter << "\t\tInvalid Cards: " << invalid_counter << "\tTotal: " << totalCount << endl;
	}
	else
		cout << "Unable to open file" << endl;

	return 0;
}

/*
1)
This Visa card <4120670000624855> is VALID!
This Visa card <4266901024841678> is VALID!
This Discover card <6011002543517833> is VALID!
This Discover card <6011208947684752> is VALID!
This Mastercard card <5545141002153628> is VALID!
This Visa card <4403190016296308> is NOT VALID!
This Discover card <6011208997992451> is VALID!
This Unknown card <8466160241276433> is NOT VALID!
This Visa card <4313072843714489> is VALID!
This Mastercard card <5121079602112358> is VALID!
This Visa card <4403190015929676> is VALID!
This Mastercard card <5581588012277612> is VALID!
This Mastercard card <5466160341276433> is NOT VALID!
This Visa card <4313072843777890> is VALID!

Valid Cards: 11         Invalid Cards: 3        Total: 14
Press any key to continue . . .


*/
