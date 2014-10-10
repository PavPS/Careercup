#include "stdafx.h"

/*
Problem
Sublist of a sorted (ascending order)link list is reversed...correct it 
1--->2--->3--->4--->8--->7--->6--->5--->9--->10--->NULL
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct TreeNode_{
	int value;
	TreeNode_ *next;
}TreeNode;

void addNode(int value, TreeNode **head)
{
	TreeNode *n = new TreeNode();
	n->value = value;
	n->next = NULL;

	if (!*head)	
	{
		*head = n;
		return;
	}

	n->next = *head;
	*head = n;
}

void printTree(TreeNode const * tree, const string& comment )
{
	cout << comment << ": ";
	while(tree)
	{
		cout << tree->value << " ";
		tree = tree->next;
	}
	cout << endl;
}

void fix(TreeNode * tree)
{
	TreeNode *goodTail = tree;
	while(tree && tree->next)
	{
		// Scroll to problem place
		if (tree->value <= tree->next->value)
		{
			goodTail = tree;
			tree = tree->next;
			continue;
		}

		// Reverse in please
		TreeNode *newHead = NULL;
		TreeNode *badHead = tree;
		while(tree)
		{
			TreeNode *originalNext = tree->next;
			tree->next = newHead;
			newHead = tree;
			tree = originalNext;

			if (originalNext && originalNext->value > newHead->value)
				break;
		}
		goodTail->next = newHead;
		badHead->next = tree;

		break;
	}
}

void JamesChen23()
{
	TreeNode *tree = NULL;
	addNode(10, &tree);
	addNode(9, &tree);
	addNode(5, &tree);
	addNode(6, &tree);
	addNode(7, &tree);
	addNode(8, &tree);
	addNode(4, &tree);
	addNode(3, &tree);
	addNode(2, &tree);
	addNode(1, &tree);

	printTree(tree, "Original");
	fix(tree);
	printTree(tree, "Fixed   ");
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen23();
	return 0;
}
#endif