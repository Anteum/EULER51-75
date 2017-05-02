#include "connect3.h"
#include <deque>

int ffynin()//decrypt the message of XOR encrypted ASCII codes in cipher.txt and find sum of original ASCII values
{//97-122 are value options for each of 3 chars constituting repeated encryption key
	const int a = 97, z = 122;
	vector<int> chars, daChars;//daChars is decryption attempt of chars
	ifstream ciph("cipher.txt");
	string temp;
	while (getline(ciph, temp, ','))
		chars.push_back(stoi(temp));
	ciph.close();
	deque<int> test = {32,116,104,101,32}, cur;//test is ascii for " the "
	bool found;
	int sum;
	
	for (int keyA = a; keyA <= z; keyA++)
	{
		for (int keyB = a; keyB <= z; keyB++)
		{
			for (int keyC = a; keyC <= z; keyC++)
			{
				daChars = chars;
				found = false;
				sum = 0;
				for (int ch = 0; ch < daChars.size(); ch++)
				{
					if (ch % 3 == 0)//using %3 to make cycle of length 3 for key
						daChars[ch] ^= keyA;//XOR chars with key to decrypt
					else if (ch % 3 == 1)
						daChars[ch] ^= keyB;
					else if (ch % 3 == 2)
						daChars[ch] ^= keyC;
					cur.push_back(daChars[ch]);//cycle thru daChar and compare 5 chars at time with the english test word
					if (cur.size() > test.size())
						cur.pop_front();
					if (cur == test)
						found = true;
				}
				cout << char(keyA) << char(keyB) << char(keyC) << endl;
				if(!found)
					continue;
				cout << endl << char(keyA) << char(keyB) << char(keyC) << endl;
				for (int i = 0; i < daChars.size(); i++)
				{
					sum += daChars[i];
					char temp = daChars[i];//convert ascii to char and display
					cout << temp;
				}
				cout << endl << sum << endl;
				return 0;
			}
		}
	}

	return 0;
}
