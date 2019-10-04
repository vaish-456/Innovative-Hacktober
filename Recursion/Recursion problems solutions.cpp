//Problem 1 solution.
// C++ program to print all palindromic partitions of a given string
#include<bits/stdc++.h>
using namespace std;

// A utility function to check if str is palindroem
bool isPalindrome(string str, int low, int high)
{
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

// Recursive function to find all palindromic partitions of str[start..n-1]
// allPart --> A vector of vector of strings. Every vector inside it stores
//			 a partition
// currPart --> A vector of strings to store current partition
void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,
				int start, int n, string str)
{
	// If 'start' has reached len
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}

	// Pick all possible ending points for substrings
	for (int i=start; i<n; i++)
	{
		// If substring str[start..i] is palindrome
		if (isPalindrome(str, start, i))
		{
			// Add the substring to result
			currPart.push_back(str.substr(start, i-start+1));

			// Recur for remaining remaining substring
			allPalPartUtil(allPart, currPart, i+1, n, str);

			// Remove substring str[start..i] from current
			// partition
			currPart.pop_back();
		}
	}
}

// Function to print all possible palindromic partitions of
// str. It mainly creates vectors and calls allPalPartUtil()
void allPalPartitions(string str)
{
	int n = str.length();

	// To Store all palindromic partitions
	vector<vector<string> > allPart;

	// To store current palindromic partition
	vector<string> currPart;

	// Call recursive function to generate all partiions
	// and store in allPart
	allPalPartUtil(allPart, currPart, 0, n, str);

	// Print all partitions generated by above call
	for (int i=0; i< allPart.size(); i++ )
	{
		for (int j=0; j<allPart[i].size(); j++)
			cout << allPart[i][j] << " ";
		cout << "\n";
	}
}

// Driver program
int main()
{
	string str = "nitin";
	allPalPartitions(str);
	return 0;
}

//Problem 2. solution
// A recursive C++ program to check whether a given number is
// palindrome or not
#include <stdio.h>

// A function that reurns true only if num contains one digit
int oneDigit(int num)
{
	// comparison operation is faster than division operation.
	// So using following instead of "return num / 10 == 0;"
	return (num >= 0 && num < 10);
}

// A recursive function to find out whether num is palindrome
// or not. Initially, dupNum contains address of a copy of num.
bool isPalUtil(int num, int* dupNum)
{
	// Base case (needed for recursion termination): This statement
	// mainly compares the first digit with the last digit
	if (oneDigit(num))
		return (num == (*dupNum) % 10);

	// This is the key line in this method. Note that all recursive
	// calls have a separate copy of num, but they all share same copy
	// of *dupNum. We divide num while moving up the recursion tree
	if (!isPalUtil(num/10, dupNum))
		return false;

	// The following statements are executed when we move up the
	// recursion call tree
	*dupNum /= 10;

	// At this point, if num%10 contains i'th digit from beiginning,
	// then (*dupNum)%10 contains i'th digit from end
	return (num % 10 == (*dupNum) % 10);
}

// The main function that uses recursive function isPalUtil() to
// find out whether num is palindrome or not
int isPal(int num)
{
	// If num is negative, make it positive
	if (num < 0)
	num = -num;

	// Create a separate copy of num, so that modifications made
	// to address dupNum don't change the input number.
	int *dupNum = new int(num); // *dupNum = num

	return isPalUtil(num, dupNum);
}

// Driver program to test above functions
int main()
{
	int n = 12321;
	isPal(n)? printf("Yesn"): printf("Non");

	n = 12;
	isPal(n)? printf("Yesn"): printf("Non");

	n = 88;
	isPal(n)? printf("Yesn"): printf("Non");

	n = 8999;
	isPal(n)? printf("Yesn"): printf("Non");
	return 0;
}

//problem 3. solution
// C++ program to print even length binary sequences
// whose sum of first and second half bits is same
#include <bits/stdc++.h>
using namespace std;

// Function to print even length binary sequences
// whose sum of first and second half bits is same

// diff --> difference between sums of first n bits
// and last n bits
// out --> output array
// start --> starting index
// end --> ending index
void findAllSequences(int diff, char* out, int start, int end)
{
	// We can't cover difference of more than n with 2n bits
	if (abs(diff) > (end - start + 1) / 2)
		return;

	// if all bits are filled
	if (start > end)
	{
		// if sum of first n bits and last n bits are same
		if (diff == 0)
			cout << out << " ";
		return;
	}

	// fill first bit as 0 and last bit as 1
	out[start] = '0', out[end] = '1';
	findAllSequences(diff + 1, out, start + 1, end - 1);

	// fill first and last bits as 1
	out[start] = out[end] = '1';
	findAllSequences(diff, out, start + 1, end - 1);

	// fill first and last bits as 0
	out[start] = out[end] = '0';
	findAllSequences(diff, out, start + 1, end - 1);

	// fill first bit as 1 and last bit as 0
	out[start] = '1', out[end] = '0';
	findAllSequences(diff - 1, out, start + 1, end - 1);
}

// Driver program
int main()
{
	// input number
	int n = 2;

	// allocate string contaning 2*n characters
	char out[2 * n + 1];

	// null terminate output array
	out[2 * n] = '\0';

	findAllSequences(0, out, 0, 2*n - 1);

	return 0;
}
