#include "connect3.h"

int sxythr()//# of natural numbers that are an nth power with n digits
{
	int sum = 0;
	vector<short> num;
	bool done = false;
	for (int n = 1; !done; n++)
	{
		done = true;//only maybe true
		for (int x = 1; x < 10; x++)//10^n is always n+1 digits
		{
			num = itov(x);
			for (int p = 1; p < n; p++)//do powers by repeat multiplication
			{
				num = multVecAndInt(num, x);
			}
			if (num.size() == n)//test for winners
			{
				sum++;
				done = false;//if at least one sol found, look another round
			}
		}
	}
	cout << sum << endl;

	return 0;
}//ez pz