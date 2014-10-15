#include "stdafx.h"

/*
You are given very huge file , with each line containing a single word. 
We have to give the count and word which is repeated most. 

http://habrahabr.ru/post/111874/
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct node
{
	unsigned count;
	string::value_type letter;
	vector<node*> children;
};

void Amazone1()
{
	vector<string> strings;
	strings.push_back("pavel");
	strings.push_back("is");
	strings.push_back("trying");
	strings.push_back("to");
	strings.push_back("get");
	strings.push_back("paid");
	strings.push_back("1234");
	strings.push_back("12345");
	strings.push_back("123456");

	node head = {0};
	node *maxNode = &head;
	string maxWord;
	for ( vector<string>::const_iterator stringIter = strings.begin(), end = strings.end(); stringIter != end; ++stringIter )
	{
		node* pointer = &head;
		int depth = 0;
		for (string::const_iterator charIter = stringIter->begin(), charEnd = stringIter->end(); charIter != charEnd; ++charIter )
		{
			node* pointerNext = NULL;
			for ( vector<node*>::iterator childIter = pointer->children.begin(), childEnd = pointer->children.end(); childIter != childEnd; ++childIter )
			{
				if ( (*childIter)->letter == *charIter )
				{
					pointerNext = *childIter;
					break;
				}
			}

			if (!pointerNext)
			{
				node *newNode = new node();
				newNode->count = 0;
				newNode->letter = *charIter;

				pointer->children.push_back(newNode);
				pointerNext = newNode;
			}

			depth++;
			pointer = pointerNext;
		}
		pointer->count = depth;
		if ( pointer->count > maxNode->count )
		{
			maxNode = pointer;
			maxWord = *stringIter;
		}
	}

	cout << "Max string is: " << maxWord << " " << maxNode->count << " characters long" << endl;
} 

#if !defined(_MSC_VER)
int main()
{
	Amazone1();
	return 0;
}
#endif
