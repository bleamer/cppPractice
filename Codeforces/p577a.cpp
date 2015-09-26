
// Code force P577 A ; Multiplicatoin table Solution

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, x;
	cin >> n >> x;
	// cout << n << endl;
	// cout << x << endl;

	int count = 0;


	// Each number occurs once in a column, when the column 
	// is a factor of the number/

	// So for solution print each such column no.

	for (int i = 1; i <= n; ++i)
	{
		if(   (x/i <= n) && !(x%i)  )
		{
			count ++;
		}
	}

	cout << count << endl;


	return 0;
}