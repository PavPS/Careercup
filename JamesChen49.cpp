#include "stdafx.h"

/*
##Pretty much interested question asked in AMAZON Written test##

Take a string, store it as digits; str="678876". Now Check if the given str return TWO EQUAL PARTS with equal sum (6+7+8=8+7+6);
if it is correct then replace the str(678876) in the new string, str1="12345876678"

Final output should be: "12345678876"
I tried this ..but the interviewer didnt satisfy..
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void JamesChen49()
{
	const string str = "678876";

	unsigned left = 0, right = str.size();
	int sum = 0;

	while(left != right)
	{
		if (sum <= 0)
		{
			sum += (int)str[left++];
		}
		else if (sum > 0)
		{
			sum -= (int)str[--right];
		}
	}

	if (!sum)
		cout << "12345" + str << endl;
	else
		cout << "SORRY" << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen49();
	return 0;
}
#endif
