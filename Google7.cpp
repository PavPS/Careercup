#include "stdafx.h"

/*
You are given two streams 's_a' and 's_b' of digits. Each stream represents an integer 'a' and 'b' 
from its less significant digit to the most significant digit. 
For example, integer 2048 is represented in the stream as 8, 4, 0, 2. 

Write a function that subtract two integers 'a - b' and returns the result as a string. 
You are not allowed to buffer entire 'a' or 'b' into a single string, i.e. you may access only a single 
digit per stream at time (imagine that 'a' and 'b' are stored in huge files). You may assume that 'a>=b'. 

Example: 
s_a: 8 4 0 2 
s_b: 4 2 0 1 

result: '1024'
*/

#include <iostream>
#include <assert.h>
#include <sstream>

using namespace std;

void Google7()
{
	stringstream a_stream, b_stream, r_stream;

	a_stream.write("8402", 4);a_stream.seekg(0);
	b_stream.write("4201", 4);b_stream.seekg(0);

	int in_brain = 0;
	while(true)
	{
		char a;
		if (!a_stream.eof())
			a = a_stream.get();
		else
			a = '0';

		char b;
		if (!b_stream.eof())
			b = b_stream.get();
		else
			b = '0';

		if (a_stream.eof() || b_stream.eof()) 
			break;

		int a_num = a - '0';
		int b_num = b - '0';

		if (a_num < in_brain)
		{
			a_num += 10 - in_brain;
		}
		else
		{
			a_num -= in_brain;
			in_brain = 0;
		}

		if (a_num < b_num)
		{
			a_num += 10;
			in_brain = 1;
		}

		r_stream << a_num - b_num;
	}

	cout << r_stream.str() << endl;
	cout << "DONE" << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Google7();
	return 0;
}
#endif
