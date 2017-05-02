#include "connect3.h"

int svytwo()//find the # of elements in the set of n/d, d <= 1 000 000
{//where n/d is reduced and proper
//realized that each d would only have # of fractions equal to numbers less than and relatively prime to d
//which is given by phi(d)!!!
	long long setSize = 0;
	for (int den = 2; den <= 1000000; den++)
		setSize += eulerPhi(den);
	cout << endl << setSize << endl;

	return 0;
}