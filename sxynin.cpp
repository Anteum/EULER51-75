#include "connect3.h"

int sxynin()//Euler's Totient function: phi(n) outputs # of numbers < n where gcd(x,n)=1
{//find n <= 1 000 000 where n/phi(n) is maximum
	//*
	double max{}, value;
	int maxsN;
	for (double n = 2; n <= 1000000; n++)
	{
		value = n / eulerPhi(n);//real work done by eulerPhi()
		if (value > max)
		{
			max = value;
			maxsN = n;
		}
		//cout << n << "  ";
	}
	cout << endl << max << endl << maxsN << endl;
	//*/
	return 0;
}