#include "connect3.h"

class LargeFrac//basic rational number container
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

void contFrac(LargeFrac &frac, int a)//helps with compute of x=[a0;a1,a2,a3,...], a0 must be added at end on own
{
	vector<short> temp = multVecAndInt(frac.den, a);
	frac.num = sumVecs(temp, frac.num);
	swap(frac.num, frac.den);
}

int ffysvn()//consider finite simple continued fraction approximations of sqrt(2)
{//how many of first 1000 fractional approx have more digits in the numerator than denominator
	int longNum = 0;
	LargeFrac inner{ itov(0),itov(1) };//init inner frac to 0
	for (int i = 1; i <= 1000; i++)//is simplified due to a1=a2=a3...
	{
		contFrac(inner, 2);
		LargeFrac sqrt2{sumVecs(inner.den,inner.num),inner.den};//+1 to complete formula for approx of sqrt(2)
		//sqrt2.fracDisp();
		if (sqrt2.num.size() > sqrt2.den.size())
			longNum++;
	}
	cout << longNum << endl;
	return 0;
}

/*
sqrt(2) = 1 + ______1______
			   2 + _____1_____
			        2 + ___1___
			 _		     2 + ...
		= [1;2]
*/