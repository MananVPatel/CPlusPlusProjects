// This program calculates the sale price of an item
// that is regularly priced at $59.95, with a 20 percent
// discount subtracted.
#include <iostream>
using namespace std;

int main()
{
	// Varaibles to hold the regular price, the
	// amount of a discount, and the sale price.
	double regularPrice = 59.95, discount, salePrice;
	// Calculate the amount of a 20% discount.
	discount = regularPrice * 0.2;

	// calculate the sale price by subtracting the 
	// discount from the regular price.
	salePrice = regularPrice - discount;

	// Displat the results.
	cout << "Regular price: $" << regularPrice << endl;
	cout << "Discount amount: $" << discount << endl;
	cout << "sale price: $" << salePrice << endl;
	return 0;
}

/* Execution Sample: 
Regular price: $59.95
Discount amount: $11.99
sale price: $47.96
Press any key to continue . . .
*/