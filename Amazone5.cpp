#include "stdafx.h"

/*
Given a binary search tree (BST) with each node having some value. 
You have to compute for each node the summation of all nodes whose 
value is greater than the current node.I have used the DFS kind of algorithm.
*/

#include <assert.h>
#include <queue>
#include <stack>

using namespace std;

struct bt_node
{
	int value;
	bt_node *left;
	bt_node *right;
};

bt_node** bt_next(bt_node* node, int value)
{
	bt_node **victim;
	if (value <= node->value)
		return &node->left;
	else
		return &node->right;
}

void bt_add(bt_node* node, int value)
{
	bt_node **victim = bt_next(node, value);
	if (!*victim)
	{
		*victim = new bt_node();
		(*victim)->value = value;
	}
	else
	{
		bt_add(*victim, value);
	}
}

int bt_sum_rec(bt_node* node)
{
	if (!node)
		return 0;

	return node->value + bt_sum_rec(node->left) + bt_sum_rec(node->right);
}

bt_node* bt_search_rec(bt_node* node, int value)
{
	if (!node)
		return nullptr;

	if (node->value == value)
		return node;

	return bt_search_rec( *bt_next(node, value), value );
}

bt_node* bt_search_bfs(bt_node* node, int value)
{
	if (node->value == value)
		return node;

	queue<bt_node*> nodes;
	nodes.push(node);

	while (!nodes.empty())
	{
		bt_node* tmp = nodes.front();
		nodes.pop();
		if (!tmp) continue;
	
		if ( tmp->value == value )
			return tmp;

		nodes.push(tmp->left);
		nodes.push(tmp->right);
	}

	return nullptr;
}

bt_node* bt_search_dfs(bt_node* node, int value)
{
	if (node->value == value)
		return node;

	stack<bt_node*> nodes;
	nodes.push(node);

	while (!nodes.empty())
	{
		bt_node* tmp = nodes.top();
		nodes.pop();
		if (!tmp) continue;
	
		if ( tmp->value == value )
			return tmp;

		nodes.push(tmp->left);
		nodes.push(tmp->right);
	}

	return nullptr;
}

void Amazone5()	
{
	bt_node *root = new bt_node();
	root->value = 2;
	bt_add(root, 7);
	bt_add(root, 5);
	bt_add(root, 1);
	bt_add(root, 4);
	bt_add(root, 9);
	bt_add(root, 3);

	auto sum = bt_sum_rec(root);
	assert(sum == 31);
	auto found1 = bt_search_rec(root, 7);
	assert(found1 && found1->value == 7);
	auto found2 = bt_search_rec(root, 9);
	assert(found2 && found2->value == 9);

	assert(bt_search_rec(root, 9) == bt_search_bfs(root, 9));
	assert(bt_search_rec(root, 7) == bt_search_bfs(root, 7));

	assert(bt_search_rec(root, 9) == bt_search_dfs(root, 9));
	assert(bt_search_rec(root, 7) == bt_search_dfs(root, 7));
}