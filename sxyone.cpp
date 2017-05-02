#include "connect3.h"

class Poly//polygonal value container
{
public:
	int value;
	int sides;
};

int trian(int n)
{
	return n*(n + 1) / 2;
}
int squar(int n)
{
	return n*n;
}
int penta(int n)
{
	return n*(3 * n - 1) / 2;
}
int hexag(int n)
{
	return n*(2 * n - 1);
}
int hepta(int n)
{
	return n*(5 * n - 3) / 2;
}
int octag(int n)
{
	return n*(3 * n - 2);
}

int sxyone()//find the cycle of 6 4-digit numbers where the last 2 digits of each number are the first 2 of the next
{//and each polygonal number type is represented once and sum the numbers
	vector<Poly> polys;
	
	for (int n = 1; trian(n) < 10000; n++)//if trian(n)>10000 all the other polygonals are too
	{
		polys.push_back(Poly{ trian(n),3 });
		polys.push_back(Poly{ squar(n),4 });
		polys.push_back(Poly{ penta(n),5 });
		polys.push_back(Poly{ hexag(n),6 });
		polys.push_back(Poly{ hepta(n),7 });
		polys.push_back(Poly{ octag(n),8 });
	}
	for (int i = 0; i < polys.size(); i++)//now delete all values that aren't 4 digits
	{
		if (polys[i].value < 1000 || polys[i].value>9999)
		{
			polys.erase(polys.begin() + i);
			i--;
		}
	}
	
	vector<Poly> chain;//use for remembering which polygonal types have been used
	int link = 0, sum = 0;
	bool win = false;
	while (win==false)//
	{
		for (int i = 0; i < polys.size(); i++)
		{
			if (chain.size() == 0)
			{
				chain.push_back(polys[i]);
				link = polys[i].value % 100;
				goto NextPoly;
			}
			if ((chain.back().sides == polys[i].sides && chain.back().value == polys[i].value) || chain.size() == 6)
			{//every poly has failed to connect to end of chain...or the chain did't loop
				chain.pop_back();
				if (chain.size() == 0)
					link = 0;
				else
					link = chain.back().value % 100;
				goto NextPoly;
			}
			if (polys[i].value / 100 == link)//check for linkage
			{
				for (int p = 0; p < chain.size(); p++)//check if polygonal type is already used
				{
					if (polys[i].sides == chain[p].sides)
						goto NextPoly;
				}
				chain.push_back(polys[i]);
				link = polys[i].value % 100;
			}
			if (chain.size() == 6 && chain[0].value / 100 == link)//chain is correct length and loops around
			{
				win = true;
				break;
			}
		NextPoly:;
		}
	}
	for (int i = 0; i < chain.size(); i++)//display winner
	{
		cout << chain[i].sides << ' ' << chain[i].value << endl;
		sum += chain[i].value;
	}
	cout << sum << endl;
	
	return 0;
}