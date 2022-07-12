// =====================================================================================================
// File: part1.cpp
// =====================================================================================================
// Programmer: Eric Du
// Date: 11/12/2014
// Class: CPSC 121
// Time: 10:30 PM
// Instructor: Dr. Ray Ahmadnia
// Project: Project No.10
//
// Description
//      This program uses classes and functions to sort multiple x and y coordinates for different
// objects.
//
// =====================================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class POINT
{
private: float x, y;
public: //constructor to set x, y of each vertex to ZERO
	POINT();
	//member to read x and y coordinates of each vertex
	void ReadData(char vertex);
	//display the (x, y) of a given vertex
	void Display(char vertex);
	//friend to compute the distance between verticies p(x,y) and q(x,y)
	friend float Distance(POINT p, POINT q);
	//Compute and display the perimeter of ABCD
	friend void DisplayPer(float AB, float AC, float CD, float BD);
	//destructor to releaes all memory used by objects in the program
	~POINT();

};


// ==== main ===========================================================================================
//
// =====================================================================================================

int main()
{
	time_t P;
	time(&P);
	cout << "Today's date and time " << ctime(&P) << endl;

	POINT A, B, C, D;
	cout << "For the rectangle ABCD:\n";
	A.ReadData('A');
	B.ReadData('B');
	C.ReadData('C');
	D.ReadData('D');

	//draw the rectangle;
	cout << fixed << showpoint << setprecision(2);
	A.Display('A');
	cout << "-----------------------------";
	B.Display('B');
	cout << endl << "             |                            |";
	cout << endl << "             |                            |";
	cout << endl << "             |                            |\n";
	C.Display('C');
	cout << "-----------------------------";
	D.Display('D');
	cout << endl;
	//compute the length of each side
	float AB = Distance(A, B);
	cout << "\tAB=" << AB << endl;
	float AC = Distance(A, C);
	cout << "\tAC=" << AC << endl;
	float CD = Distance(C, D);
	cout << "\tCD=" << CD << endl;
	float BD = Distance(B, D);
	cout << "\tBD=" << BD << endl;

	//compute and display perimeter
	DisplayPer(AB, AC, CD, BD);
	cout << endl;

	//terminate program
	system("pause");
	return 0;
}

POINT::POINT()
{
	x = 0;
	y = 0;
}
void POINT::ReadData(char vertex)
{
	cout << "Enter the x and y coordinates of vertex " << vertex << ": ";
	cin >> x >> y;
}
void POINT::Display(char vertex)
{
	cout << vertex << "(" << x << "," << y << ")";
}
float Distance(POINT p, POINT q)
{
	return sqrt(pow((q.x - p.x), 2.0) + (pow((q.y - p.y), 2.0)));
}
void DisplayPer(float AB, float AC, float CD, float BD)
{
	cout << "Perimeter =" << AB + AC + CD + BD;
}
POINT::~POINT()
{}

/*-------------------------------------------------output-----------------------------------------------
Today's date and time Wed Nov 12 22:31:06 2014

For the rectangle ABCD:
Enter the x and y coordinates of vertex A: 10 7
Enter the x and y coordinates of vertex B: 20 7
Enter the x and y coordinates of vertex C: 10 2
Enter the x and y coordinates of vertex D: 20 2
A(10.00,7.00)-----------------------------B(20.00,7.00)
             |                            |
             |                            |
             |                            |
C(10.00,2.00)-----------------------------D(20.00,2.00)
AB=10.00
AC=5.00
CD=10.00
BD=5.00
Perimeter =30.00
Press any key to continue . . .
------------------------------------------------------------------------------------------------------*/