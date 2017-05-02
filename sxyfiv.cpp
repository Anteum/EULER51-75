#include "connect3.h"

//copied from #57 but added some 2's...
class LargeFrac2
{
public:
	vector<short> num;
	vector<short> den;
	void fracDisp()
	{
		for (int n : num)
			cout << n;
		cout << " / ";
		for (int d : den)
			cout << d;
		cout << endl;
	}
};

void contFrac2(LargeFrac2 &frac, int a)//helps with compute of x=[a0;a1,a2,a3,...], a0 must be added at end on own
{//adds your current fraction to the coefficient and finds the reciprocal
	vector<short> temp = multVecAndInt(frac.den, a);
	frac.num = sumVecs(temp, frac.num);
	swap(frac.num, frac.den);
}

int sxyfiv()//find sum of the digits in the numerator of the 100th approx of e by continued frac
{//coefficients of CF rep of e are given as: [2; 1, 2, 1, 1, 4, 1, 1, 6, 1,...1, 2*k, 1,...]
	LargeFrac2 inner{ itov(0),itov(1) };
	for (int k = 33; k >= 1; k--)//each k is 3 steps for a total of 99 steps plus final 1 later for 100
	{
		contFrac2(inner, 1);
		contFrac2(inner, 2*k);
		contFrac2(inner, 1);
	}
	LargeFrac2 e{ sumVecs(multVecAndInt(inner.den,2),inner.num),inner.den };//+2 completes approx of e
	e.fracDisp();
	cout << endl << vSum(e.num) << endl;
	return 0;
}
 /*-->e<--
      e  = 2 + ____________1____________
                1 + __________1__________
                     2 + ________1________
                          1 + ______1______
                               1 + ____1____
		                            4 + ...
		 
		 = [2;1,2,1,1,4,1,...]
 */