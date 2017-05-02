#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

vector<short> vFact(int);//factorials for n>20
long long factorial(int);//computes (n!)
bool isPrime(long long);//returns primality of int > 0
template<typename T>
	void vPrint(vector<T>);//prints vectors of shorts
int numLength(long long);//returns number of digits in int > 0	//can use itov(int).size() instead
vector<short> itov(long long);//returns a vector of the digits of input
long long vtoi(vector<short>);//counterpart to itov()
vector<short> decToBin(int);//converts decimal to binary 
bool isPalindrome(vector<short>);//returns bool of whether int > 0 is a palindrome
vector<short> multVecAndInt(vector<short>,int);//returns product of vector multiplicand and int multiplier
bool isPandigital(int);//returns bool of whether int is pandigital from 1 to length of int
void peel_off(vector<short>&);//delete first element from vector of shorts
int vSum(vector<short>);//sum of numbers in elements of vector
vector<int> primeFactors(int);//returns vector of all prime factors of n
template<typename T>
	vector<T> uniqEle(vector<T>);//returns vector of all unique elements in input vector
vector<short> digOrder(vector<short>);//returns vector with digits ordered large to small
vector<short> multVecs(vector<short>, vector<short>);//multiply vectors as numbers
vector<short> sumVecs(vector<short>, vector<short>);//sum vectors as numbers
bool vIsGreater(vector<short>, vector<short>);//is first vector >= to second
long long concatInts(int, int);//concatenate 2 ints
int eulerPhi(int);//euler totient function

int ffyone();
int ffytwo();
int ffythr();
int ffyfor();
int ffyfiv();
int ffysix();
int ffysvn();
int ffyegt();
int ffynin();
int sixty();
int sxyone();
int sxytwo();
int sxythr();
int sxyfor();
int sxyfiv();
int sxysix();
int sxysvn();
int sxyegt();
int sxynin();
int svnty();
int svyone();
int svytwo();
int svythr();
int svyfor();
int svyfiv();
