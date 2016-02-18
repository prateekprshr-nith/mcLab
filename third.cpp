/*
 * Programm to implement CDMA
 * Prateek Prasher
 */

#include <iostream>
using namespace std;

int main()
{
	int cA[4],
	    cB[4],
	    sA[4],
	    sB[4],
      	cS[4],
	    A,
	    B,
	    sum = 0;

	// Get the codes
	cout << "Enter the first code: ";
	for(int i = 0; i < 4; i++)
	{
		cin >> cA[i];
		if(cA[i] == 0)
		{
			cA[i] = -1;
		}
	}

	cout << endl <<  "Enter the second code: ";
	for(int i = 0; i < 4; i++)
	{
		cin >> cB[i];
		if(cB[i] == 0)
		{
			cB[i] = -1;
		}
	}

	// Get the data
	cout << endl << "Enter A and B: "; cin >> A >> B;
	if(A == 0)
		A = -1;
	if(B == 0)
		B = -1;
	
	// Now process at the sending end
	cout << endl << "Intermediate code mixing A and B is: ";
	for(int i = 0; i < 4; i++)
	{
		cS[i] = (A * cA[i]) + (B * cB[i]);
		cout << cS[i];
		cout << " ";
	}
	
	
	// Now process at the receiving end
	for(int i = 0; i < 4; i++)
	{
		sum += cS[i] * cA[i]; 	// For A
	}
	cout << endl << "A's received as: " << (sum > 0) ? 1 : 0; cout << endl;
	
	sum = 0;
	for(int i = 0; i < 4; i++)
	{
		sum += cS[i] * cB[i]; 	// For B
	}
	
	cout << endl << "B's received as: " << (sum > 0) ? 1 : 0; cout << endl;
	
	return 1;
}
	
























