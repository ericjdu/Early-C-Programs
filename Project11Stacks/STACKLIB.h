#ifndef STACKLIB
#define STACKLIB

template<class T, int n>
class STACK
{
private: int a[n];
		 int counter;
public:
	void ClearStack()
	{
		counter = 0;
	}
	bool EmptyStack()
	{
		return (counter == 0) ? true : false;
	}
	bool FullStack()
	{
		return (counter == n - 1) ? true : false;
	}
	void PushStack(T x)
	{
		a[counter] = x;
		counter++;
	}
	T PopStack()
	{
		counter--;
		return a[counter];
	}
};

#endif Save:STACKLIB