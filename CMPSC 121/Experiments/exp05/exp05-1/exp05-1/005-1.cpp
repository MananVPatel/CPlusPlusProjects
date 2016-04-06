//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 05-1
//File: P:\Private\CMPSC 121\Experiments\exp05\exp05-1\exp05-1
//purpose: To find the assesment value and property tax for a piece of property
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <iomanip>

using namespace std;
int main()

{
	int choice;
	double radius, area, length, width, base, height;
	const double PI = 3.14159;
	cout << fixed << showpoint << setprecision(3);
	cout << "1. Calculate the Area of a Circle\n";
	cout << "2. Calculate the Area of a Rectangle\n";
	cout << "3. Calculate the Area of a Triangle\n";
	cout << "4. Quit\n";
	cout << "\nEnter your choice (1-4): \n";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{cout << "What is the radius of the Circle?\n";
	cin >> radius;
	area = PI*(pow(radius, 2));
	cout << "The are of the Circle is: " << area << endl; }
		break;
	case 2:
	{cout << "What is the length and width of the Rectangle?\n";
	cin >> length >> width;
	area = length*width;
	cout << "The area of a Rectangle is: " << area << endl; }
		break;
	case 3:
	{cout << "What is the length of the triangle's base and its height?\n";
	cin >> base >> height;
	area = base* height*.5;
	cout << "The area of a Triangle is: " << area << endl; }
		break;
	case 4: 
		return 0;
	default:
	{cout << "You have entered an invalid number.\n";
	cout << "Please end program and re-enter your choice (1-4).\n"; }
	}

	return 0;
}

/*
1)
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit

Enter your choice (1-4):
1
What is the radius of the Circle?
12
The are of the Circle is: 452.389
Press any key to continue . . .

2)
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit

Enter your choice (1-4):
2
What is the length and width of the Rectangle?
12 25
The area of a Rectangle is: 300.000
Press any key to continue . . .

3)
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit

Enter your choice (1-4):
3
What is the length of the triangle's base and its height?
12 15
The area of a Triangle is: 90.000
Press any key to continue . . .

4)
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit

Enter your choice (1-4):
4
Press any key to continue . . .

5)
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit

Enter your choice (1-4):
-5
You have entered an invalid number.
Please end program and re-enter your choice (1-4).
Press any key to continue . . .

*/