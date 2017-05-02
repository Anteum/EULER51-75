#include "connect3.h"

long long factDigits(long long n)//creates next number in chain
{
	long long total = 0;
	vector<short> digs = itov(n);
	for (short x : digs)
		total += factorial(x);
	return total;
}

int svyfor()//create a chain of numbers from n by summing the factorials of n's digits to create successive numbers 
{//eventually every chain will repeat, find the # of n, n < 1 000 000, whose chain's length is 60 before repeating
	vector<vector<long long>> factChains;//list of chains of long longs
	int maxChains = 0;
	for (int n = 1; n < 1000000; n++)
	{
		long long temp = n;
		factChains.push_back(vector<long long>(1, n));
		while (true)//every chain eventually loops and takes the goto out
		{
			temp = factDigits(temp);
			for (int k = 0; k < factChains[n - 1].size(); k++)//check for repeat
				if (temp == factChains[n-1][k])
					goto NextN;
			factChains[n - 1].push_back(temp);//if not repeat, add to chain
		}
	NextN:;
		//cout << n << "  ";
	}
	cout << endl << "chained." << endl;
	for (vector<long long> chain : factChains)
		if (chain.size() == 60)
			maxChains++;
	cout << maxChains << endl;

	return 0;
}