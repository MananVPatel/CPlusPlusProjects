#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	int num1, num2;
	
	cout << "Enter a number: \n";
	cin >> num1;

	cout << "Enter a different number: \n";
	cin >> num2;
	if (num1 < num2)
		cout << num1 << " is smaller than " << num2 << endl;
	else
		cout << num1 << " is larger than " << num2 << endl;
	return 0;
}