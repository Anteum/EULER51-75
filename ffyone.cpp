#include "connect3.h"

int ffyone()//smallest prime which, by replacing part of the number with the same digit, is part of an eight prime family
{//ex: 56xx3 is a seven prime family, with 56003 being the smallest
	//going to assume "part of the number" is > 1 digit
	for (int p = 56005; p < 1000000; p += 2)//looking specifically for this smallest prime //1000000 is arbitrary large number
	{
		if (!isPrime(p))//need for smallest prime to be prime
			continue;
		vector<short> pVec = itov(p), pFam;
		int zeroes = 0, ones = 0, twos = 0, start, famSize = 1;
		for (int i = 0; i < pVec.size(); i++)//each prime needs multiple of a digit in it to be the "part of the number"
		{//that changes, and since 8 of the digits create primes, the first one must have either multiple 0's, 1's or 2's
			int dig = pVec[i];
			switch (dig)//look for multiple 0's, 1's or 2's here
			{
				case 0:	zeroes++;	break;
				case 1:	ones++;		break;
				case 2:	twos++;		break;
				default:			break;//nothing
			}
		}
		if (zeroes < 2 && ones < 2 && twos < 2)
			continue; 
		if (zeroes >= 2)//find the digit the "part of the number" is made of originally
			start = 0;
		else if (ones >= 2)
			start = 1;
		else if (twos >= 2)
			start = 2;
		for (int d = start + 1; d <= 9; d++)//go through all following digits
		{
			pFam = pVec;
			for (int ind = 0; ind < pFam.size(); ind++)//change "part" to next digit
			{
				if (pFam[ind] == start)
					pFam[ind] = d;
			}
			if (isPrime(vtoi(pFam)))//check if new family member is prime and count it if so
				famSize++;
		}
		if (famSize == 8)//display solution
		{
			cout << p << " is the smallest prime part of an 8 prime family created by changing all instances of " << endl;
			cout << "a certain digit (in this case " << start << ") to every other digit." << endl;
			break;
		}
	}
	return 0;
}