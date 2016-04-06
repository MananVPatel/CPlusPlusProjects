//Author: Manan Patel, mvp5542@psu.edu, Thursday 8:00 AM - 9:50 AM
//Class: CMPSC 121
//Experiment: 11
//File: P:\Private\CMPSC 121\Experiments\lab11\Lab11\Lab11\lab011
//Academic Integrity Affidavit: I certify that, this program code is my work.Others may have assisted me 
//with planning and concepts, but the code was written, solely by me.
//I understand that submitting code which is totally or partially the product of other individuals is a violation 
//of the Academic Integrity Policy and accepted ethical precepts. Falsified execution results are also results of improper 
//activities. Such violations may result in zero credit for the assignment, reduced credit for the assignment, or course failure.
//Sources of logic assistance: 121 study group: None

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//function prototypes
string fixName(string n);
string fixSSN(string ss);
string fixPhone(string ph);
string fixAddress(string addr);
string fixCity(string cty);
string fixState(string st);
string extractField(string &s);
void buildLine(string &s, string field);

int main()
{
	string line, name, SSN, phone, address, city, state, buildL;
	ifstream inputfile; 
	ofstream outputfile;
	inputfile.open("badnames.txt");
	outputfile.open("goodnames.txt");
	
	if (inputfile.fail())
	{
		cout << "Failure to open file\n";
	}
	else
	{

		while (getline(inputfile, line))
		{
			

			buildL = "";
			//function calls
			name = extractField(line); 
			name = fixName(name);
			buildLine(buildL, name);
			
			SSN = extractField(line);
			SSN = fixSSN(SSN);
			buildLine(buildL, SSN);

			phone = extractField(line);
			phone = fixPhone(phone);
			buildLine(buildL, phone);

			address = extractField(line);
			address = fixAddress(address);
			buildLine(buildL, address);

			city = extractField(line);
			city = fixCity(city);
			buildLine(buildL, city);

			state = extractField(line);
			state = fixState(state);
			buildLine(buildL, state);

			buildL += line;
			outputfile << buildL << endl;
			cout << buildL << endl;


		}
		//closing files
		inputfile.close();
		outputfile.close();
	}
	return 0;
}


//Extracts a field (eg. SSN) and then deletes it with the octothorpe following it. 
string extractField(string &s)
{
	int i;
	string str;
	i = s.find('#');
	str = s.substr(0, i);
	s.erase(0, i + 1);
	return str;
}

//fixes the name by changing the lowercase letter of the first and last name to uppercase and adds a comma in between last and first name.
string fixName(string n)
{
	int i;
	string last;
	i = n.find(' ');
	last = n.substr(0, i);
	n.erase(0, i + 1);
	n[0] = toupper(n[0]);
	last[0] = toupper(last[0]);
	n += ", " + last;
	return n;
}

//fixes the Social security # by adding a - in between #'s
string fixSSN(string ss)
{
	ss.insert(5, "-");
	ss.insert(3, "-");
	return ss;
}

//fixes the phone # by adding a dash in between the area code and the last 3 & last 4
string fixPhone(string ph)
{
	ph.insert(6, "-");
	ph.insert(3, "-");
	return ph;
}

//fixes address by sequencing and changing first letter to uppercase
string fixAddress(string addr)
{
	string address;
	int lookup = 0, loc1 = 0;
	do
	{
		lookup = addr.find(" ", loc1);
		if (lookup != -1)
			if (isalpha(addr[lookup + 1]))
				addr[lookup + 1] = toupper(addr[lookup + 1]);
		loc1 = lookup + 1;
	} while (lookup != -1);
		address = addr;
		return address;
}

// change the first letter to uppercase
string fixCity(string cty)
{
	cty[0] = toupper(cty[0]);
	return cty;
}

// changes both letter to uppercase
string fixState(string st)
{
	for (int i = 0; i < static_cast<int>(st.length()); i++)
	{
		st[i] = toupper(st[i]);
	}
	return st;
}
// concatenates the final output line
void buildLine(string&s, string field)
{
	s += field;
	s += ",";
}

/*
Execution Sample:

Smith, John,165-98-0076,814-833-7965,3rd & State St,Erie,PA,16506
Gardner, Martin,164-90-5543,440-354-2700,5244 Heisley Rd,Mentor,OH,44123
Vendetti, Sarah,164-87-9987,330-254-1122,29 Millhaven St.,Akron,OH,44532
Golumbiewski, Judy,194-40-9976,716-334-7654,6187 Fillmore Ave,Rochester,NY,07654
Merz, Terry,193-97-6554,800-243-5799,19876 Elm Avenue,Manchester,MO,63166
Jones, Kenisha,198-43-2265,919-361-0419,902 East Taylor Rd,Apex,NC,27709
Yee, Phil,176-40-9976,630-860-2682,1976 Wacker Drive,Chicago,IL,60191
Caron, Jean,167-45-3321,973-887-4700,1429 Delben Street,Whippany,NJ,07981
Alicea, Sandy,176-41-9006,305-442-8202,12 La Habana East,Miami,FL,33134
Williams, Rob,206-33-7765,334-271-5450,9854 Fremont Blvd,Montgomery,AL,36109
Hilfiger, Jancy,201-87-6987,814-881-7654,3012 State St,Pittsburgh,PA,15011
Press any key to continue . . .



*/