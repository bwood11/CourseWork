
#include "readarray.h"

// function read_int_as_array
// 
// parameter input: array to hold the digits of the integer
// parameter size: the size of the array
// parameter numdigits: the number of digits of the integer read in
// parameter success: indicates that integer was read successfully,
// or otherwise.
//
//
// This function reads an integer of up to "size" digits
// and stores the digits in the array "input".
//


void read_int_as_array(int input[], int size, int& numdigits, bool& success)

{
	char temp;
	int i;
	success = true;
	if (size < 1) return;
	
	int count = 0;
	
	// initialise array entries to 0

	for (i = 0; i < size; i++)
		input[i] = 0;
	
	do
	// loop through input characters
	{
		// get character (put it in temp)
		cin.get(temp);
        // if we have not reached end of line or got too many digits
		// place digit into array, converted to int
		if ((temp != '\n') && (count < size))	// if temp is not nothing and counter is less than size(of array) make input [current index based on counter] equal to temp  - 0???? what's the last step
			input[count] = int(temp) - int('0');
		// if the character was not a digit, make success false
		if ((!isdigit(temp)) && (temp != '\n'))
			success = false;

		// increase counter
		count ++;
	}
	while (temp != '\n');

	// set numdigits to avoid counting the end of line character
	numdigits = count-1;

	// if there were too many digits, set success to false
	if (numdigits > size)
		success = false;
	return;	

}



// only works if the number entered first is bigger WHEN BOTH ARE BACKWARDS 
// output is really ugly will display 50 digits regardless of how many are entered and is still BACKWARDS - this may be due to how input is made
// needs a way to determine largest number (highest number index not 0?)
int longSub(int a[], int b[], const int size)
{
	stringstream ss;
	int const sizes = 50;
	int c = 0; //borrow number
	int borrow = 1; // the '1' that gets carried to the borrowed number
	int r[sizes];

	//initialise answer array to 0.
	for (int i = 0; i < size; i++)
	{
		r[i] = 0;
	}
	
	for (int i = size - 1; i >= 0; i--) 
	{
		//handles zeros
		if (a[i] < b[i] && a[i]) 
		{
			//takes the borrow from the next unit and appends to a.
			ss << borrow << a[i];
			ss >> c;
			ss.str(""); // clears stringstream for next potential borrow.

			int temp = c - b[i];
			r[i] = abs(temp);
		}
		else 
		{
			int temp = a[i] - b[i];
			r[i] = abs(temp);
		}
	}
	for (int i = 0; i <= size - 1; i++) 
	{
		cout << r[i];
	}
	
	cout << endl;
	return r[sizes];
}


