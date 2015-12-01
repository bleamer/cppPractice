// The problem to decide what should be the order of 
// multiplication of matrices in a chain for matrices to 
// to use minimum number to muliplications

#include <iostream>
#include <climits>
using namespace std;

// j = Number of matrices in the chain
int MatrixChainOrder(int p[], int i, int j)
{
	// if the both the dimensions of this matrix
	// are equal then order of multiplication will not m
	// matter
	if (i == j)
		return 0;
	int min = INT_MAX;
	int count;

	// place the parantheses at different places
	// between the given chain of matrices and 
	// and count the number of multiplicatios in 
	// each case

	for(int k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + // count from prev matrix
				MatrixChainOrder(p, k+1, j)+ // count from next matrix
				p[i-1]*p[k]*p[j]; // dimension[prev] * dim [current prod]* dim[next]				 
		if (count <  min)
			min = count;
	}
	return min; 
}

int main (int argc, char ** argv)
{
	int givenMatrices[] = {10, 40, 55, 79, 34, 23};
	int size = sizeof(givenMatrices) / sizeof(givenMatrices[0]);
	cout << MatrixChainOrder(givenMatrices, 1, size-1) << endl;
	return 0;
}