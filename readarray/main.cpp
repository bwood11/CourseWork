// A small main program to demonstrate the way the read_int_as_array
// function works. The program reads a long integer from the keyboard,
// and then displays the contents of the array.


#include <iostream>
#include <algorithm>  // libary to reverse arrays 
#include "readarray.h"
using namespace std;

int main()
{
	const int MAXSIZE = 50;
	int num1[MAXSIZE], num2[MAXSIZE];
	bool success, success2;
	int numdigits, numdigits2;
	

	cout << "Enter a positive integer:" << endl;

	// creating first big num array 
	read_int_as_array(num1,MAXSIZE,numdigits,success);

	if (success)
		cout << "Valid input" << endl;
	else
		cout << "Invalid input" << endl;

	cout << endl << numdigits << " digits entered" << endl << endl;
	
	// reverses the array ready for long subtraction 

	reverse(begin(num1), end(num1)); 
	
	// checks the size of the arrays which is 50 and probably should have been obv
	//int size = sizeof(num1) / sizeof(num1[0]);

	//cout << "size is: " << size <<endl; 


	for (int i = 0; i < MAXSIZE; i++)
		cout << num1[i];
	// input for second long number same as above 

	cout << "Enter a second positive integer:" << endl;
	// creating second big num array 
	read_int_as_array(num2, MAXSIZE, numdigits2, success2);

	if (success)
		cout << "Valid input" << endl;
	else
		cout << "Invalid input" << endl;

	cout << endl << numdigits2 << " digits entered" << endl << endl;
	
	// reverse second array
	reverse(begin(num2), end(num2));
	 
	// keeps the console open 
	char junk; cin.get(junk);

	// print contents of second array - check if it was working 
	for (int i = 0; i < MAXSIZE; i++)
		cout << num2[i];


	// checking size of array again
	//int size2 = sizeof(num2) / sizeof(num2[0]);

	//cout << "size is: " << size2 << endl;

	//bool isSmaller(int numdigits, int numdigits2);


	
	// calls the longsub function:
	// parameters are both array and their size? only 50 works 
	longSub(num1, num2, 50);

	//cout << endl << "The difference between these numbers is: " << ans;

	return 0;
}
