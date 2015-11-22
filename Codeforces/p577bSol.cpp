#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, p;
	cin >> n >> p;
	vector <int> a(n); // Place holder to store integers or their modulus
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		// Calculate the modulo of every entered number
		a[i] %= p;
	}

	vector <int> parent(p, -1);
	vector <int> newParent(p, -1);

	for (int t = 0; t < n; t++) // for all input values
	{
		int v = a[t]; 		// Get the remainder for this element
		copy(parent.begin(), parent.end(), newParent.begin());
		if (newParent[v] == -1) // if newparent has not been assigned new value
		{
			newParent[v] = t;
		}
		for (int i = 0; i < p; ++i)
		{
			if (parent[i] != -1 && 
				parent[(i+v)%p] == -1)
			{
				newParent[(i+v)%p] = t;
			}
		}
		copy(parent.begin(), parent.end(), newParent.begin());
	}

	if (parent[0] == -1)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
 	return 0;
}