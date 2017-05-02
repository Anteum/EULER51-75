#include "connect3.h"

int ffyegt()//create a square spiral with the natural numbers counter-clockwise
{//consider only the numbers in the diagonals and find the side length when 
//the percent of diagonals that are prime first falls below 10%
	/*
	vector<bool> primes(100000000, true);
	primes[0] = false; primes[1] = false;
	for (int i = 2; i <= sqrt(primes.size()); i++)
	{
		if (!primes[i])
			continue;
		for (int j = 2 * i; j < primes.size(); j += i)
		{
			if(primes[j])
				primes[j] = false;
		}
		cout << i << ' ';
	}
	//*/
	int diags = 1, primeDiags = 0, diag = 1;
	for (int m = 1; m < 1000000; m++)//1000000 is arbitrary large number
	{//side length is m*2+1
		for (int i = 1; i <= 3; i++)
		{
			diag += m * 2;//each diagonal of same side length are m*2 apart
			//if (diag < primes.size() && primes[diag])
				//primeDiags++;
			if (isPrime(diag))
				primeDiags++;
			diags++;
		}
		diag += m * 2;//4th diagonal on each side length is square (not prime)
		diags++;
		double ratio = double(primeDiags) / diags;
		cout << m * 2 + 1 << "  " << primeDiags << " / " << diags << " = " << ratio << endl;
		if (ratio < .10)
		{
			cout << endl << m * 2 + 1 << endl;
			break;
		}
	}

	return 0;
}

/*
	37 36 35 34 33 32 31
	38 17 16 15 14 13 30
	39 18  5  4  3 12 29
	40 19  6  1  2 11 28
	41 20  7  8  9 10 27
	42 21 22 23 24 25 26
	43 44 45 46 47 48 49...
*/