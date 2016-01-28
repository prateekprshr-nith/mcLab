#include <iostream>
using namespace std;

int main()
{
	int c1[4],
	    c2[4],
	    sum = 0;

	// Get the codes
	cout << "Enter the first code: ";
	for(int i = 0; i < 4; i++)
	{
		cin >> c1[i];
		if(c1[i] == 0)
		{
			c1[i] = -1;
		}
	}

	cout << endl <<  "Enter the second code: ";
	for(int i = 0; i < 4; i++)
	{
		cin >> c2[i];
		if(c2[i] == 0)
		{
			c2[i] = -1;
		}
	}

	// Now multiply them
	for(int i = 0; i < 4; i++)
	{
		sum += c2[i] * c1[i];
	}

	if(sum == 0)
	{
		cout << endl << "The codes are orthogonal" << endl;
	}
	else
	{
		cout << endl << "The codes are not orthogonal" << endl;
	}

	return 0;
}
