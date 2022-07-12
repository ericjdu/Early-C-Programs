// =====================================================================================================
// File: part1.cpp
// =====================================================================================================
// Programmer: Eric Du
// Date: 12/04/2014
// Class: CPSC 121
// Time: 11:00 PM
// Instructor: Dr. Ray Ahmadnia
// Project: Project No.11
//
// Description
//      This program 
//
// =====================================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctime>
#include<algorithm>
using namespace std;

template <class T, int n>
class TWO 
{
private: T a[n];
public: void ReadData(); //read data into array a
		void DisplayData();     //display array a
		void SortArray();          //sort array a
		~TWO(){}
};


// ==== main ===========================================================================================
//
// =====================================================================================================

int main()
{
	time_t P;
	time(&P);
	cout << "Today's date and time " << ctime(&P) << endl;

	TWO *P;
	P = new TWO(int a[] , 10);
	TWO *Q;
	Q = new TWO(string a[] , 12);

	P.ReadData();
	Q.ReadData();

	P.DisplayData();
	Q.DisplayData();

	P.SortArray();
	Q.SortArray();

	P.DisplayData();
	Q.DisplayData();

	
	//terminate program
	system("pause");
	return 0;
}

template<class T, int n>
void TWO<T,n>::ReadData()
{
	if (n == 10)
	{
		srand(time(0));
		int num = rand() % 10 + rand() % 10;

		for (int i = 0; i < n; i++)
		{
			a[i] = num;
			num = rand() % 10 + rand() % 10;

		}
	}

	if (n == 12)
	{
		a[0] = "Dec";
		a[1] = "Nov";
		a[2] = "Oct";
		a[3] = "Sep";
		a[4] = "Aug";
		a[5] = "Jul";
		a[6] = "Jun";
		a[7] = "May";
		a[8] = "Apr";
		a[9] = "Mar";
		a[10] = "Feb";
		a[12] = "Jan";
	}
}

template<class T, int n>
void TWO<T,n>::DisplayData()
{
	cout << "Here is the array: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	cout << endl;
}

template<class T, int n>
void TWO<T,n>::SortArray()
{
	sort(a, a + n);
}

/*-------------------------------------------------output-----------------------------------------------

------------------------------------------------------------------------------------------------------*/