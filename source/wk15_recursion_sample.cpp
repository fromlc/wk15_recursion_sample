//------------------------------------------------------------------------------
// Recursive function examples
//      - factorial calculation: n! = n * (n-1) * (n-2) * ... * 1
//      - string character count
//		- binary search
// 
// Author: Gaddis 9E example programs Pr20-3, Pr20-4, Pr20-9
//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
int rFactorial(int);						// recursive version
int iFactorial(int);						// iterative version
int rNumChars(char, string&, int);			// recursive version
int iNumChars(char, string&, int);			// iterative version
int rBinarySearch(int[], int, int, int);	// recursive version

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	//--------------------------------------------------------------------------
	// Example 1: calculate factorial n!
	//--------------------------------------------------------------------------
	int number;

	// Get a number from the user.
	cout << "\nEnter an integer value to display its factorial: ";
	cin >> number;

	// display value of number factorial (number!)

	// recursive calculation
	cout << "\tRecursive: " << number << "! = " 
		<< rFactorial(number) << '\n';

	// iterative calculation
	cout << "\tIterative: " << number << "! = " 
		<< iFactorial(number) << "\n\n";

	//--------------------------------------------------------------------------
	// Example 2: count the occurrences of a character in a string
	//--------------------------------------------------------------------------
	string str = "abcddddef";
	char ch = 'd';

	// Display the number of times character ch appears in the string.

	// recursive calculation
	cout << "Recursive: " << ch << " appears "
		<< rNumChars('d', str, 0) 
		<< " times in string " << str << ".\n";

	// iterative calculation
	cout << "Iterative: " << ch << " appears "
		<< rNumChars('d', str, 0)
		<< " times in string " << str << ".\n\n";

	//--------------------------------------------------------------------------
	// Example 3: recursive binarySearch()
	//--------------------------------------------------------------------------

	// Define a _sorted_ array of employee ID numbers
	int idNumbers[] = {
		101, 142, 147, 189, 199,
		234, 289, 296, 310, 319,
	};
	 
	// display array elements
	cout << "Sorted array for recursive binary search:\n\t";
	int index = 0;
	for (int n : idNumbers) {
		cout << index++ << ':' << n << ' ';
	}
	cout << "\n\n";


	// get employee ID number to search for
	cout << "Enter the Employee ID to search for: ";
	int idNum;
	cin >> idNum;

	// search for the ID number in the array.
	int numElements = sizeof(idNumbers) / sizeof(int);

	// pass starting and ending array indexes for search
	int foundAtIndex = rBinarySearch(idNumbers, 0, numElements - 1, idNum);

	// display search results
	if (foundAtIndex == -1)
		cout << idNum << " was not found in the array.\n";

	else {
		cout << idNum << " was found at array index " 
			<< foundAtIndex << '\n';
	}

	return 0;
}

//------------------------------------------------------------------------------
// Recursively calculates the factorial value of parameter n.
//
// Definition of n factorial: n! = n * (n-1) * (n-2) * ... * 1
// 
//		For instance: 5! = 5 * 4 * 3 * 2 * 1
//		
//		This function uses divide and conquer to calculate 
//		successively smaller factorials:
// 
//			5!  = 5 * 4! 
//				= (5 * 4) * 3!
//				= (5 * 4 * 3) * 2!
//				= (5 * 4 * 3 * 2) * 1
//------------------------------------------------------------------------------
int rFactorial(int n) {

	// Base case terminates the recursion
	if (n == 0)
		return 1;

	// Recursive case
	return n * rFactorial(n - 1);
}

//------------------------------------------------------------------------------
// iterative version
//------------------------------------------------------------------------------
int iFactorial(int n) {
	int result = 1;

	// use base case as loop termination case
	while (n != 0) {
		result *= n;
		n--;
	}

	// this is a better iterative version
	//for (int i = 2; i <= n; i++) {
	//	result *= i;
	//}

	return result;
}

//------------------------------------------------------------------------------
// Recursively counts the number of times a character occurs in a string.
// The search begins at the subscript stored in parameter subscript.
// 
// Parameters:
//		- ch: search for this character
//		- str: string to search
//		- startIndex: search begins at this array index
// 
// Iteration is a much better solution to this problem! (Why?)
//------------------------------------------------------------------------------
int rNumChars(char ch, string& str, int startIndex) {

	if (startIndex >= str.length()) {
		// Base case: The end of the string has been passed. 
		return 0;
	}
	else if (str[startIndex] == ch) {
		// Recursive case: A matching character was found.
		// Return 1 plus the number of times character ch
		// appears in the rest of the string.
		return 1 + rNumChars(ch, str, startIndex + 1);
	}
	else {
		// Recursive case: A character that does not match the
		// search character was found. Return the number of times
		// character ch appears in the rest of the string.
		return rNumChars(ch, str, startIndex + 1);
	}
}

//------------------------------------------------------------------------------
// iterative version
//------------------------------------------------------------------------------
int iNumChars(char ch, string& str, int startIndex) {

	// iterative code can use an accumulator variable (recursive code can't)
	int count = 0;

	// calculate string length once, not every time through loop
	int len = (int) str.length();

	int i = startIndex;

	// use base case for loop termination
	while (i < len) {
		if (str[i] == ch) {
			count++;
		}

		i++;
	}

	// a better iterative version
	//for (int i = startIndex; i < len; i++) {
	//	if (str[i] == ch) {
	//		count++;
	//	}
	//}

	return count;
}

//------------------------------------------------------------------------------
// Recursive binary search on a range of elements of an integer array.
// 
// Parameters: 
//		- array: search array
//		- first: subscript of the range's starting element
//		- last: subscript of the ranges's last element
//		- value: search value
// 
// Returns:
//		- array subscript of the search value, if found
//		- -1 otherwise
//------------------------------------------------------------------------------
int rBinarySearch(int array[], int first, int last, int value) {

	// base case
	if (first > last)
		return -1;

	// Mid point of search array
	int middle = (first + last) / 2;

	if (array[middle] == value)
		return middle;

	if (array[middle] < value)
		return rBinarySearch(array, middle + 1, last, value);
	else
		return rBinarySearch(array, first, middle - 1, value);
}