// =====================================================================================================
// File: Part2.cpp
// =====================================================================================================
// Programmer: Eric Du
// Date: 12/04/2014
// Class: CPSC 121
// Time: 1:00 PM
// Instructor: Dr. Ray Ahmadnia
// Project: Project No.11
//
// Description
//      This program use stacks to print out a sentence in reverse, as well as find the forms of numbers
// using bases 2, 8, and 16
//
// =====================================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"STACKLIB.h"
using namespace std;



// ==== main ===========================================================================================
//
// =====================================================================================================

int main()
{
	time_t P;
	time(&P);
	cout << "Today's date and time " << ctime(&P) << endl;

	char c;
	STACK <char, 30> S;
	S.ClearStack();
	cout << "Enter a sentence: ";
	cin.get(c);

	while (c != '\n')
	{
		S.PushStack(c);
		cin.get(c);
	}

	cout << "Sentence in reverse order is: ";
	while (!S.EmptyStack())
	{
		cout << S.PopStack();
	}

	for (int i = 0; i < 3; i++)
	{
		int num, base;
		cout << endl << endl << "Enter an integer <100: ";
		STACK<int, 30> basedNum;
		basedNum.ClearStack();
		cin >> num;
		cout << "Enter a new base(2,8,16): ";
		cin >> base;
		while (num != 0)
		{
			basedNum.PushStack(num % base);
			num = num / base;
		}
		cout << num << " at base " << base << " is: ";
		while (!basedNum.EmptyStack())
		{
			int r = basedNum.PopStack();
			if (r <= 9) cout << r;
			else cout << char(r + 55);
		}
		cout << endl;
	}




	//terminate program
	system("pause");
	return 0;
}

/*-------------------------------------------------output-----------------------------------------------
Today's date and time Thu Dec 04 12:54:46 2014

Enter a sentence: Happy Thanksgiving
Sentence in reverse order is: gnivigsknahT yppaH

Enter an integer <100: 58
Enter a new base(2,8,16): 2
0 at base 2 is: 111010


Enter an integer <100: 58
Enter a new base(2,8,16): 8
0 at base 8 is: 72


Enter an integer <100: 58
Enter a new base(2,8,16): 16
0 at base 16 is: 3A
Press any key to continue . . .
------------------------------------------------------------------------------------------------------*/