//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Activity: 25
//File: done at home on my laptop
//Academic Integrity Affidavit: I certify that, this program code is my
//work.Others may have assisted me
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product
//of other individuals is a violation
//of the Academic Integrity Policy and accepted ethical precepts. Falsified
//execution results are also results of improper
//activities. Such violations may result in zero credit for the assignment,
//reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

using namespace std;
int fillVector(vector <int> &v, int size);
void remove(vector<int> &v);
void Sort(vector<int> &v, int size);
void display(vector<int> &v, int size);
int main()
{
	srand(time(NULL));
	int size = 0;
	int fill;
	vector<int> v;
	fill = fillVector(v, size);
	remove(v);
	Sort(v, size);
	display(v, size);
	return 0;

}

int fillvector(vector <int> &v, int size)   //What's wrong with this?   
{
	int i;
	for (i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 500 + 1;
	}
	i = size;
	return v[size];
}

void remove(vector <int> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] == v[i + 1])
		{
			for (int j = i + 1; j < v.size() - 2; j++)
			{
				v[j] = v[j + 1];
			}
			v.pop_back();
		}
	}
}

void Sort(vector<int> &v, int size)
{
	int minIndex, minValue;

	for (int s = 0; s < v.size(); s++)
	{
		minIndex = s;
		minValue = v[s];
		for (int i = s + 1; i < v.size(); i++)
		{
			if (v[i] < minValue)
			{
				minValue = v[i];
				minIndex = i;
			}
			v[minIndex] = v[i];
			v[s] = minValue;
		}
	}
}

void display(vector<int> &v, int size)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0 && i % 10 == 0)
			cout << endl;
		cout << v[i] << " ";
	}
}

