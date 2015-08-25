#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// This function generates all possible subset of given elements
// in the set by including them / excluding them
// depending upon the bit value corresponding to their positing
template <typename T>
void generate_power_set(const vector<T> &S)
{
	for (int i = 0; i < (1 << S.size()); ++i) // For all size set in the given vector
	{
		int x = i;
		while(x)						
		{
			// For set smaller than int bitwidth, 
			// ints can be used else arrays should be used
			// Extract the least significant bit which is set
			// and get its position using lg2
			int target = log2(x & ~(x -1)); 
			cout << S[target];
			// Consume the least significant bit from the word
			// and if still true insert ,
			// else we'll insert newline
			if (x &= x - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	std:vector<char> Chars;
	Chars.push_back('a');
	Chars.push_back('b');
	Chars.push_back('c');
	Chars.push_back('d');
	Chars.push_back('e');
	Chars.push_back('f');
	generate_power_set(Chars);
	return 0;
}