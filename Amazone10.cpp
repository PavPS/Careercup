#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Amazone10()
{
	string s("451");
	cout << "Initial: " << s << endl;

	sort(s.begin(), s.end());
	cout << "Sorted: " << s << endl;

	do
	{
		cout << "Perm: " << s << endl;
	}	while(next_permutation(s.begin(), s.end()));
}