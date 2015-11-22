// Fermat little theorem
// If  a number N prime then for all A :       1 < A < N-1
// A ^ (N-1) =- 1 MOD (N)
// OR
// A^N MOD(N) = A MOD(N)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int probabK = 3;	// iterator count ensure large probability of correctness

// A^N % P
int power (int a, unsigned int n, int p)
{
	int result = 1; // result will be stored here

	a = a % p;
	while (n > 0)
	{
		// cout << . << n << p << endl;
		// n is odd, multiply  result with result
		if ( n & 1)
			result = (result * a) % p;
		// n is even
		n >>= 1; //  divide by 2
		a  = (a*a) % p;
	}

	return result;
}

// If n is prime then return true
// if n is composite then return false with high probability
// Higher values of K increase the probability of a number
// being confidently non prime
// Do the following k times
//    - pick a random number in range [2, n-2]
//    - if A^N MOD(N) != A MOD(N), then return False
// Else number is probably prime
bool isPrime(unsigned int n, int k)
{
	if (n <= 1 || n == 4)
		return false;
	if (n <= 3)
		return true;
	for (; k > 0; --k)
	{
		// pick a random number between (4,n-2)
		int a = 2 + rand()%(n-4);

		// Run fermat's littel theorem
		if(power(a,n-1, n) != 1)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// cout << power(5,6,7) << endl;
	int i;
	// Print all primes between 1 and 10000
	for (i = 0; i < 10000; ++i)
	{
		if (isPrime(i,probabK))
			cout << i << endl;
	}
	return 0;
}