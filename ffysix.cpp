#include "connect3.h"

int ffysix()//max digit sum of a^b where a,b<100
{
	vector<short> power;
	int max = 0;
	for (int b = 99; b > 0; b--)
	{
		for (int a = 99; a > 0; a--)
		{
			power = itov(a);
			for (int i = 2; i <= b; i++)//multiply a by a b-1 times
			{
				power = multVecAndInt(power, a);
			}
			if (vSum(power) > max)//if new current max, display
			{
				max = vSum(power);
				cout << a << ' ' << b << "  " << max << endl;
			}
		}
	}

	return 0;
}