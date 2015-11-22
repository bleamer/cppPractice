
// Code force P577 B ; Modulo Sum Solution

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	cout << n << endl << m << endl;
	long unsigned int v;
	// vector<long unsigned int> seq;
	vector <long unsigned int> seq;
	unsigned int tail = 0; 				// Index of the element where the current reference subsequence starts
	unsigned int head = 0; 				// Index of the elemenet where the current reference subsequence ends 

	int runningSum = 0;			// Running sum of the subequence in question
	if (n > 0)					// if valid n 
		seq.reserve(n);			// then reserve the space.
	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		seq.push_back(v);
		runningSum += v;
		if ( !(runningSum % m) )
		{
			cout << "YES" << endl;
			exit(0);
		}			
	}

	bool finished = false;
	runningSum = 0;
	while(!finished)
	{
		if (tail < seq.size() )
		{
			head = tail;
			runningSum = seq[head];	// Reset the running sum, to start from current sequence start
		}
		else
			finished = true;

		while( head < seq.size() )
		{
			if (runningSum % m)
			{
				if (++head < seq.size())
					runningSum += seq[head];
				
				cout << "runningSum = " << runningSum << ",head = " << head << ",tail = " << tail << endl;
			}
			else
			{
				cout << "YES" << endl;
				exit(0);
			}						
		}
		++tail;

	}

	cout  << "NO" << endl;

	return 0;
}