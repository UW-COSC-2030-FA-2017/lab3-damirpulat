// lab3-dpulatov.cpp
// Damir Pulatov
// COSC 2030, Lab 3
// 09/29/17

#include<iostream>

using namespace std;

template <class type>
void sum();

template <class type> 
void factorial();

template <class type>
void f();

template <class type>
void puzzle();

bool overflowSum();

int main()
{
	// Testing shortSum() function
	// Overflow occurs when n = 256
	// You can detect the overflow if the sum is negative
	cout << "Testing sum with short data type:" << endl;
	sum<short>();
	cout << endl;

	// Testing longSum() function
	// Overflow occurs when n = 7900011
	cout << "Testing sum with long data type:" << endl;
	sum<long>();
	cout << endl;


	// Testing factorial() with floats
	// Overflow occurs when n = 35
	// You can detect the overflow if factorial = inf
	cout << "Testing factorial with float:" << endl;
	factorial<float>();
	cout << endl;


	// Testong factorial() with doubles
	// Overflow occurs when n = 171
	cout << "Testing factorial with double: " << endl;
	factorial<double>();
	cout << endl;


	// Testing f() 
	// This function is supposed always give 0 as output
	// f() gives 0 as it should when values for n are small. Once n becomes largers (>8) 
	// the results are not precisely 0. They're usually very close to 0, (-1.7*E-7)
	cout << "Testing f() 'strange floating point' bevavior with floats" << endl;
	f<float>();
	cout << endl;


	// Testing f() 
	// f() with doubles doesn't give 0 after n > 6. But in this case, approximations to 0 are closer
	// than the ones with floats (in the order of 1E-16. This is because doubles are twice more precise than floats.
	cout << "Testing f() 'strange floating point' bevavior with doubles" << endl;
	f<double>();
	cout << endl;


	// Testing puzzle() with floats
	// The error occurs at the end of the for loop
	// The for look goes beyond 4.2, which it's not supposed to
	// This is because floats do not represent fractions precisely 
	// It could be because at the last step, the result was 4.1, which got rounded to 4.2 and when you add 0.2
	// The result is 4.3, which again was rounded to 4.4
	cout << "Testing puzzle piece of code" << endl;
	puzzle<float>();
	cout << endl;


	// Testing puzzle() with doubles
	// storing i as double solves the problem, because doubles are twice more precise than floats
	cout << "Testing puzzle piece of code" << endl;
	puzzle<double>();
	cout << endl;


	return 0;
}


// Check for overflow when computing sum
bool overflowSum()
{

	return true;
}

template<class type>
void sum()
{
	cout << "Put in a number to find sum from 1 up until that number" << endl;
	cout << "Put in -1 to exit" << endl;
	int n;


	// Check input and compute the sum
	while (cin >> n && n != -1)
	{
		type sum = 0;
		for (type i = 1; i <= n; i++)
		{
			sum = sum + i;
		}
		cout << "Sum = " << sum << endl;
	}

	return;
}


// Compute factorial of a number using float
template <class type>
void factorial()
{
	cout << "Put in a number to find factorial of that number" << endl;
	cout << "Put in -1 to exit" << endl;
	int n;

	// Check input and compute the sum
	while (cin >> n && n != -1)
	{
		type product = 1;
		for (long i = 1; i <= n; i++)
		{
			product = product * i;
		}
		cout << "Factorial = " << product << endl;
	}

	return;
}


// Puzzle code
template <class type>
void puzzle()
{
	for (type i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	return;
}


// Strange behavior function
template<class type>
void f()
{
	cout << "Put in a number to find sum 1/n - 1.0" << endl;
	cout << "Put in -1 to exit" << endl;
	int n;

	// Check input (including zero case) and compute the sum
	while (cin >> n && n != -1 && n != 0)
	{
		type sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum = sum + (type)1/n;
		}
		sum = sum - 1.0;
		cout << "Sum = " << sum << endl;
	}



	return;
}

