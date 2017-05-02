#include "connect3.h"

class Card
{
public:
	char rank;// A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q or K
	char suit;// H, D, C or S
	int value;//depends on game
	
};

bool valueIsLess(Card a, Card b)//just for sort()'s use
{
	return (a.value < b.value);
}

class Hand//just a vector of cards
{
public:
	vector<Card> cards;
	long long PokerValue();
	void dispHand()
	{
		for (int i = 0; i < cards.size(); i++)
		{
			cout << cards[i].rank << ' ' << cards[i].suit << "  ";
		}
		cout << endl;
	}
};

long long Hand::PokerValue()//only works for 5 card hands of standard poker
{
	long long handTotal = 0;
	vector<short> pokes (13, 0);//keep track of hands worth in poker
	for (int c = 0; c < cards.size(); c++)
	{
		switch(cards[c].rank)//set card values to poker values
		{
		case 'A':	cards[c].value = 14;	break;
		case 'K':	cards[c].value = 13;	break;
		case 'Q':	cards[c].value = 12;	break;
		case 'J':	cards[c].value = 11;	break;
		case 'T':	cards[c].value = 10;	break;
		default:	cards[c].value = cards[c].rank - '0';	break;
		};
	}
	vector<short> rankCount(15,0);//keep track of how many of each card rank is in the hand
	for (int r = 2; r < rankCount.size(); r++)
		for (int c = 0; c < cards.size(); c++)
			if (cards[c].value == r)
				rankCount[r]++;
	sort(cards.begin(), cards.end(), valueIsLess);//in ascending order
	//dispHand();
	for (int c = 0; c < cards.size(); c++)//high card
		pokes[c]=cards[c].value;
	for (int r = 2; r < rankCount.size() && pokes[5] == 0; r++)//one pair
		if (rankCount[r] == 2)
			pokes[5] = r;
	for (int r = pokes[5] + 1; r < rankCount.size(); r++)//2nd pair
		if (rankCount[r] == 2)
			pokes[6] = r;
	for (int r = 2; r < rankCount.size(); r++)//3 of a kind
		if (rankCount[r] == 3)
			pokes[7] = r;
	for (int i = 0; i < 4 && cards[i].value + 1 == cards[i + 1].value; i++)//straight
		if (i == 3)
			pokes[8] = cards[4].value;
	for (int i = 0; i < 4 && cards[i].suit == cards[i + 1].suit; i++)//flush
		if (i == 3)
			pokes[9] = 1;
	if (pokes[5] != 0 && pokes[7] != 0)//full house
		pokes[10] = 1;
	for (int r = 2; r < rankCount.size(); r++)//4 of a kind
		if (rankCount[r] == 4)
			pokes[11] = r;
	if (pokes[8] != 0 && pokes[9] != 0)//straight flush
		pokes[12] = 1;
	for (int ind = 0; ind < pokes.size(); ind++)//convert pokes to unique score for each possible different hand's "worth" in poker
	{
		handTotal += (pokes[ind]*pow(15,ind));//like converting from base 15 to decimal
	}

	return handTotal;
}

int ffyfor()//how many hands does P1 win in poker.txt which contains 1000 pairs of hands
{//with cards represented in rank-suit char pairs and hands valued with poker rules
	int winsP1 = 0;
	char charArr[1000][20];
	ifstream poker ("poker.txt");
	for (int row = 0; row < 1000; row++)
	{
		for (int col = 0; col < 20; col++)
		{
			poker >> charArr[row][col];
		}
		vector<Card> handP1, handP2;
		for (int cd = 0; cd < 5; cd++)//put each card in the correct hand
		{
			handP1.push_back(Card{ charArr[row][2 * cd], charArr[row][2 * cd + 1] });
			handP2.push_back(Card{ charArr[row][2 * cd + 10], charArr[row][2 * cd + 11] });
		}
		Hand p1{ handP1 };
		Hand p2{ handP2 };
		if (p1.PokerValue() > p2.PokerValue())//all the real work done here
			winsP1++;
	}
	poker.close();
	cout << winsP1 << endl;
	return 0;
}