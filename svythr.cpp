#include "connect3.h"

int svythr()//find # of n/d, 1/3 < n/d < 1/2, d <= 12 000 and n/d is reduced and proper
{
	long long rangePop = 0;
	for (int den = 5; den <= 12000; den++)//2/5 has smallest den of fracs in the range
	{
		cout << den << "  ";
		for (int num = den / 3 + 1; num <= den / 2; num++)//keep num between 1/3 and 1/2 of den
		{
			for (int fac = 2; fac <= num; fac++)//ensure n/d is reduced
				if (num%fac == 0 && den%fac == 0)
					goto NextNum;
			rangePop++;
		NextNum:;
		}
	}
	cout << endl << rangePop << endl;

	return 0;
}