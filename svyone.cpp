#include "connect3.h"

int svyone()//if all fractions n/d, d <= 1 000 000, are reduced and proper
{//and ordered by size, find the numerator of the fraction just less than 3/7
	const double cap = double(3) / 7;// 3/7 = 0.428571428571...
	double inf = 0.428571, cur;//starting greatest lesser fraction out at obvious guess of 428571/1000000
	int num = 428572, den = 1000000, topN, topD;//start num & den out at logical max values
	while (den > 0)//dividing by 0 is going too far!
	{
		cur = double(num) / den;
		if (inf < cur && cur < cap)
		{
			inf = cur;
			topN = num;
			topD = den;
		}
		if (cur < cap)//if frac too small, lower den to increase frac's value
			den--;
		else if (cur >= cap)//if frac too big, lower num to decrease frac's value
			num--;
	}
	cout << topN << endl << topD << endl;
	return 0;
}