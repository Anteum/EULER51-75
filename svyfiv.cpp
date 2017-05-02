#include "connect3.h"

class rTri//container for lengths of the sides of a triangle and its perimeter
{
public:
	rTri(int aa, int bb, int cc)//constructor
		:a(aa), b(bb), c(cc), sum{a+b+c}
	{}
	void set(int aa, int bb, int cc)
	{
		a = aa;
		b = bb;
		c = cc;
		sum = aa + bb + cc;
	}
	void triSum(rTri single)//used to get multiples of triangle
	{
		a += single.a;
		b += single.b;
		c += single.c;
		sum += single.sum;
	}
	int getSum()
	{
		return sum;
	}
	void dispTri()
	{
		cout << a << "  " << b << "  " << c << endl;
	}

private:
	int a;
	int b;
	int c;
	int sum;
};


int svyfiv()//for integers L <= 1 500 000, find how many can be the perimeter of
{//only one integer sided right triangle (pythagorean triple)
	int singles = 0;
	vector<short> lengths(1500001, 0);//list of how many pythagorean triples each length can make
	vector<rTri> primaTriples;//primitive triples are a,b,c such that a^+b^2=c^2 and gcd(a,b,c)=1
	rTri curTriple(0, 0, 0);
	bool nTooBig = false;
	for (int n = 1; !nTooBig; n++)//Euclid's formula generates all primitive triples from m,n
	{
		nTooBig = true;//maybe
		for (int m = n + 1; m*m - n*n + 2 * m*n + m*m + n*n <= 1500000; m++)
		{
			for (int f = 2; f <= n; f++)
			{
				if (n%f == 0 && m%f == 0)//m and n must be coprime
					goto NextPair;
			}//coprimes pass thru this '}'
			if (n % 2 == 1 && m % 2 == 1)//m and n can't both be odd
				goto NextPair;
			curTriple.set(m*m - n*n, 2 * m*n, m*m + n*n);//Euclid's formula
			primaTriples.push_back(curTriple);
			nTooBig = false;
		NextPair:;
		}
	}
	for (int i = 0; i < primaTriples.size(); i++)
	{
		rTri mult = primaTriples[i];
		lengths[primaTriples[i].getSum()]++;//give point to perimeter of each primitive
		while (mult.getSum() <= 1500000)
		{
			mult.triSum(primaTriples[i]);//check all multiples of each primitive
			if(mult.getSum() <= 1500000)
				lengths[mult.getSum()]++;//give point to perimeter of each primitive multiple
		}
	}
	for (int i = 0; i < lengths.size(); i++)//look for perimeters with only one "point"
		if (lengths[i] == 1)
			singles++;
	cout << endl << singles << endl;
	

	return 0;
}