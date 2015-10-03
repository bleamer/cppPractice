#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long  a,b; 
	cin >> a >> b;
	cout.precision(10);	
	// The line with any value of p (used in place of x)
	// will be of the form
	// y = x + np
	// y = -x + np
	// other constraint is
	// 0 < a < p/2
	// => for (a, b) to be the polyline
	// it should be of the form 
	// b = a + nt or b = -a + nt
	// where t is int such that  0 < b < t/2


	// determine relation between a and b
	int q = a / b;
	double r = ((double) a / (double) b )- q; 

	// if at all the point lies on the line it will be on
	// y = x + q
	// OR
	// y = -x + q

	// test if give points satisfy any of the given conditions
	double y =(double) a + q;

	if (a < b)
		cout << "-1" << endl;
	else
	{
		printf("%f\n", (a+b)/(2.*( (a+b) / (2*b) )) );
	}	

	return 0;
}