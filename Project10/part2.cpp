// =====================================================================================================
// File: part2.cpp
// =====================================================================================================
// Programmer: Eric Du
// Date: 11/12/2014
// Class: CPSC 121
// Time: 10:00 PM
// Instructor: Dr. Ray Ahmadnia
// Project: Project No.10
//
// Description
//      This program uses parts of a class in order to access private values and makes use of friends
// to make use of those objects.
//
// =====================================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

class TWO
{
private: int age[5];
public: //read data into array age
		void ReadData();
	//a friend to return the average of data in array age of object p
		friend int FindAverage(TWO p);
	//display the max and min ages
		void FindMaxMin(int& maxAge, int& minAge);
	//display ages>age average
		void aboveAve(int ageAve);
	//display the max and min ags
		void DisplayMaxMinAge(int maxAge, int minAge);
	//release all memory used by objects
		~TWO() {}
	
};


// ==== main ===========================================================================================
//
// =====================================================================================================

int main()
{
	time_t P;
	time(&P);
	cout << "Today's date and time " << ctime(&P) << endl;

	TWO Steve;
	Steve.ReadData();

	Steve.aboveAve(FindAverage(Steve));

	int maxAge, minAge;
	Steve.FindMaxMin(maxAge, minAge);

	Steve.DisplayMaxMinAge(maxAge, minAge);


	//terminate program
	system("pause");
	return 0;
}

void TWO::ReadData()
{
	cout << "Enter 5 ages: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> age[i];
	}
}

int FindAverage(TWO p)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		total += p.age[i];
	}
	return total / 5;
}

void TWO::FindMaxMin(int& maxAge, int& minAge)
{
	minAge = age[0];
	maxAge = age[0];

	for (int i = 1; i < 5; i++)
	{
		if (minAge > age[i])
			minAge = age[i];
		if (maxAge < age[i])
			maxAge = age[i];
	}
}

void TWO::aboveAve(int ageAve)
{
	cout << "Ages above average:";

	for (int i = 1; i < 5; i++)
	{
		if (age[i] > ageAve)
			cout << age[i];
		if (i != 4)
			cout << " ";
	}
	cout << endl;
}

void TWO::DisplayMaxMinAge(int maxAge, int minAge)
{
	cout << "Maximum age is " << maxAge << endl;
	cout << "Minimum age is " << minAge << endl;
}

/*-------------------------------------------------output-----------------------------------------------
Today's date and time Wed Nov 12 22:14:23 2014

Enter 5 ages: 22 27 19 17 25
Ages above average:27   25
Maximum age is 27
Minimum age is 17
Press any key to continue . . .
------------------------------------------------------------------------------------------------------*/