// =====================================================================================================
// File: Simple Calculations for a Graph.cpp
// =====================================================================================================
// Programmer: Eric Du
// Date: 12/04/2014
// Class: CPSC 121
// Time: 1:30 PM
// Instructor: Dr. Ray Ahmadnia
// Project: Project No.11
//
// Description
//      This program uses overloaded functions to add together various objects, points on a graph,
//		and find the distance between those points.
//
// =====================================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class POINTS
{
private: int x, y;
public: void ReadPoint();
		void ShowPoint();
		friend POINTS operator + (POINTS P, POINTS G);
		friend POINTS operator - (POINTS P, POINTS G);
		friend POINTS operator *(int z, POINTS P);
		friend float Distance(POINTS P, POINTS G);
};


// ==== main ===========================================================================================
//
// =====================================================================================================

int main()
{
	time_t P;
	time(&P);
	cout << "Today's date and time " << ctime(&P) << endl;

	POINTS A;
	POINTS B;
	POINTS C;
	int num;

	cout << "Enter the coordinates of point A (Enter two numbers with a space in between): ";
	A.ReadPoint();
	cout << "Enter the coordinates of point B (Enter two numbers with a space in between): ";
	B.ReadPoint();

	cout << "	A";
	A.ShowPoint();
	cout << " + B";
	B.ShowPoint();
	cout << " = C";
	C = A + B;
	C.ShowPoint();
	cout << endl;

	cout << "	A";
	A.ShowPoint();
	cout << " - B";
	B.ShowPoint();
	cout << " = C";
	C = A - B;
	C.ShowPoint();
	cout << endl;

	cout << "\n\nThe distance from A";
	A.ShowPoint();
	cout << " to B";
	B.ShowPoint();
	cout << fixed << showpoint << setprecision(2);
	cout << " is: " << Distance(A, B);
	cout << endl;


	//terminate program
	system("pause");
	return 0;
}

void POINTS::ReadPoint()
{
	cin >> x;
	cin >> y;
}

POINTS operator +(POINTS P, POINTS G)
{
	POINTS R;
	R.x = P.x + G.x;
	R.y = P.y + G.y;
	return R;
}

POINTS operator -(POINTS P, POINTS G)
{
	POINTS R;
	R.x = P.x - G.x;
	R.y = P.y - G.y;
	return R;
}

POINTS operator *(int z, POINTS P)
{
	POINTS R;
	R.x = P.x * z;
	R.y = P.y * z;
	return R;
}

void POINTS::ShowPoint()
{
	cout << "(" << x << "," << y << ")";
}

float Distance(POINTS P, POINTS G)
{
	float ans = sqrt(pow(G.x - P.x, 2) + pow(G.y - P.y, 2));
	return ans;
}

/*-------------------------------------------------output-----------------------------------------------
Today's date and time Thu Dec 04 13:45:48 2014

Enter the coordinates of point A (Enter two numbers with a space in between): 2 3
Enter the coordinates of point B (Enter two numbers with a space in between): 5 7
A(2,3) + B(5,7) = C(7,10)
A(2,3) - B(5,7) = C(-3,-4)

The distance from A(2,3) to B(5,7) is: 5.00
Press any key to continue . . .
------------------------------------------------------------------------------------------------------*/