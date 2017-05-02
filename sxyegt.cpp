#include "connect3.h"

int sxyegt()//fill each "circle" in the image below with the numbers 1 to 10
{//a solution is found when each "line" of circles adds to the same amount
//create unique string for each solution by inputting the line with the smallest outside node first
//starting with the outside node, and then clockwise inputting each following group starting with their outside node
//find the maximum 16-digit string (only nodes on outside appear in string only once, so 10 must be in an outer node for string to be 16 digits)
	vector<short> outer = { 6,7,8,9,10 };//if you want max string and string starts with lowest outer node,
	do {//fill your outer nodes with largest numbers
		vector<short> inner = { 5,4,3,2,1 };
		do
		{
			vector<short> fivegon(15, 0);
			vector<short> inner2 = inner;
			short temp = inner2[0];
			inner2.erase(inner2.begin());//put first element to back just to simplify following for loop
			inner2.push_back(temp);
			for (int in = 0; in < inner2.size(); in++)//put inner nodes where they go in the string
			{
				fivegon[3 * in + 2] = inner2[in];
				fivegon[(3 * in + 4) % 15] = inner2[in];
			}
			for (int out = 0; out < outer.size(); out++)//put outer nodes where they go in the string
				fivegon[3 * out] = outer[out];
			if (fivegon[0] != 6)//if a sol starting with 6 exists, the max string must start with 6
				goto NextString;//since the string starts with lowest outer node and there are 5 outer nodes and numbers go up to 10
			int line = fivegon[0] + fivegon[1] + fivegon[2];
			for (int i = 1; i < 5; i++)//check each line has same sum
			{
				int test = fivegon[3 * i] + fivegon[3 * i + 1] + fivegon[3 * i + 2];
				if (test != line)
					goto NextString;
			}
			vPrint(fivegon);
		NextString:;
		} while (prev_permutation(inner.begin(), inner.end()));
	} while (next_permutation(outer.begin(), outer.end()));

	return 0;
}

/*//found an image to ascii converter to show image of "magic" 5-gon ring                                                                


                      ,,,
                     r     'y
                    [        L                                 ,,,,
                    ]        .                               /`     \
                     "w,  ,r'5,                             ]        L
                                *,                          ]        F
                                   *,,r'  "v                 'v,  ,=`
                                    ]       '                  `
                                    $        L                [
                                    ,W      A,               /
                                 ,r"   """`    *,           ,
                              ,e"                 *,      ,,F
                    ,e"""=,,e`                       *,r     *
                   /       \                          F       ]
                   L       .                          L       ]
                  ,A,      F                           \,   ,r
               ,r`   "*rrj                              /
     ,,,    ,r`           L                            ,
   r     "m`               L                           F
  [        .               ]                          /
  \       ,                 \                        ,
   "w   ,r                 ,^''"*,              ,r"'"^w               w^""^w
                          C       \            /       ]             `      'r
                          .       ]`````````"""L        P"""""""""""]        [
                          }      ,`             ,      r             V      /
                            "^^"C                 "*^"                 ^rr^`
                                ]
                                 \
                                  L
                                  '
                                  ,4^^~,
                                 `      }
                                [        F
                                ',      ,
                                  "~..="
*/