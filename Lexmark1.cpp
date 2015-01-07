#include "stdafx.h"

#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

/*
	Write an algorithm that checks if two nodes of an arbitrary tree have same parent.
*/

template < typename T >
struct lmTreeNode
{
	vector<lmTreeNode<T> *> children;
	lmTreeNode *parent;
	T value;
};

template < typename T >
struct lmTreeNodeLessPointer : public binary_function<lmTreeNode<T>, lmTreeNode<T>, bool> 
{
	bool operator()(lmTreeNode<T> const*lhs, lmTreeNode<T> const* rhs) const
	{
		return lhs < rhs;
	}
};

template < typename T >
struct lmTreeNodeLessValue : public binary_function<lmTreeNode<T>, lmTreeNode<T>, bool>
{
	bool operator()(lmTreeNode<T> const*lhs, lmTreeNode<T> const* rhs) const
	{
		if (!lhs || !rhs)
			return false;

		return lhs->value < rhs->value;
	}
};

template< typename T, typename TLess >
bool lmIsSameNode(lmTreeNode<T> const *node1, lmTreeNode<T> const *node2)
{
	TLess less;
	return (!less(node1, node2)) && (!less(node2, node1));
}

template< typename T>
lmTreeNode<T>* lmCreateNode(const T& value)
{
	auto node = new lmTreeNode<T>();
	node->parent = nullptr;
	node->value = value;

	return node;
}

template< typename T>
void lmAddChild(lmTreeNode<T> *parent, lmTreeNode<T> *child)
{
	assert(parent);
	assert(child);

	parent->children.push_back(child);
	child->parent = parent;
}

template< typename T>
size_t lmCountNodes(lmTreeNode<T> const *parent)
{
	assert(parent);

	size_t result = 0;

	stack< lmTreeNode<T>const * > task;
	task.push(parent);
	while (!task.empty())
	{
		auto node = task.top();
		task.pop();

		++result;
		for (auto iter = node->children.cbegin(), end = node->children.cend(); iter != end; ++iter)
			task.push(*iter);
	}

	return result;
}

//
// There is way to traverse inorder and postorder, but it would give us O(n) solution.
// Moreover, you will use stack for recursion of 2*M(h) size
// Since I have pointer to parent, I can do easier.
// I was asked to do it fro O(h) where h is tree height.
// In this case we can do following:
// 1. Bubble up from one of the nodes until root node and collect M(h) objects.
// 2. Bubble up from another node and compare node by node from list. Performance depends on method you use fro comparison.
//    In case of using <set> (BST), creating set is O(log(h))  + searching for node is h*Log(h).
//    In case if using <unordered_set> (hashtable), creation is h*O(1) and search is h*O(1)
//    In both cases, memory is used M(h)
// If you're going to change the way it is compared, just change template argument to the right type.
// I'm currently comparing pointers. You can use by-value comparison.
//

template< typename T, typename TLess = lmTreeNodeLessPointer<T> >
lmTreeNode<T> const* findCommonParent1(lmTreeNode<T> const *node1, lmTreeNode<T> const *node2)
{
	assert(node1);
	assert(node2);

	if (lmIsSameNode<T, TLess>(node1, node2))
		return node1;

	set<lmTreeNode<T>*, TLess> path;
	lmTreeNode<T>* tmp = node1->parent;
	while (tmp)
	{
		path.insert(tmp);
		tmp = tmp->parent;
	}

	tmp = node2->parent;
	while (tmp)
	{
		if (path.cend() != path.find(tmp))
			return tmp;

		tmp = tmp->parent;
	}

	assert(false);
	return nullptr;
}

typedef lmTreeNode<int> SimpleNode;

//
// Simplified version. Compare by pointers.
// Performance required: O(h), where h is tree height.
// Memory requirements: const
// Sanity checks are omitted.
//
// Solution below uses recursion and memory is h (which not constant) 
// and performance is O(2h + summ(arithmetic progression)(1 to h)) = O(2h + (1+h)*h) which is ~O(h^2)
//
SimpleNode const* findCommonParent2(SimpleNode const *node1, SimpleNode const *node2)
{
	if (!node1 || !node2)
		return nullptr;

	if (node1 == node2 && node1->parent)
		return node2;

	auto found1 = findCommonParent2(node1->parent, node2);
	if (found1 != nullptr)
		return found1;

	return findCommonParent2(node1, node2->parent);
}

//
// Another solution of task above
// Memory: M(h) - vectors (non-const)
// Performance: O(h)
//
SimpleNode const* findCommonParent3(SimpleNode const *node1, SimpleNode const *node2)
{
	vector<SimpleNode const*> path1, path2;

	SimpleNode const* tmp = node1;
	while (tmp)
	{
		path1.push_back(tmp);
		tmp = tmp->parent;
	}

	tmp = node2;
	while (tmp)
	{
		path2.push_back(tmp);
		tmp = tmp->parent;
	}

	auto same = 0u;
	while (same < min(path1.size(), path2.size()) && *(path1.crbegin() + same) == *(path2.crbegin() + same))
		++same;

	return *(path1.crbegin() + same - 1);
}

//
//	Another solution of task above
//
/* Pseudo code

size_1 <- count_until_root(node1)
size_2 <- count_until_root(node2)
if (size_1 > size_2) {
  node1 <- node1.parent
  size_1 <- size_1 - 1
}
if (size_2 > size_1) {
  node2 <- node2.parent
  size_2 <- size_2 - 1
}
while ( node2 != node1 ) {
  node2 <- node2.parent
  node1 <- node1.parent
}
ret node1
*/
SimpleNode const* findCommonParent4(SimpleNode const *node1, SimpleNode const *node2)
{
	unsigned size_1 = 0;
	for (SimpleNode const* tmp = node1; tmp; tmp = tmp->parent)
		++size_1;

	unsigned size_2 = 0;
	for (SimpleNode const* tmp = node2; tmp; tmp = tmp->parent)
		++size_2;

	while (size_1 < size_2)
	{
		node2 = node2->parent;
		--size_2;
	}

	while (size_1 > size_2)
	{
		node1 = node1->parent;
		--size_1;
	}


	while (node1 != node2)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}

	return node1;
}

// see example image here: http://en.wikipedia.org/wiki/Tree_(data_structure)
void Lexmark1()
{
	auto root_2 = lmCreateNode(2);
	auto node_7 = lmCreateNode(7);
	auto node_2 = lmCreateNode(2);
	auto node_6 = lmCreateNode(6);
	auto node_5_1 = lmCreateNode(5);
	auto node_11 = lmCreateNode(11);
	auto node_5_2 = lmCreateNode(5);
	auto node_9 = lmCreateNode(9);
	auto node_4 = lmCreateNode(4);

	lmAddChild(root_2, node_7);
	lmAddChild(root_2, node_5_2);
	lmAddChild(node_7, node_2);
	lmAddChild(node_7, node_6);
	lmAddChild(node_6, node_5_1);
	lmAddChild(node_6, node_11);
	lmAddChild(node_5_2, node_9);
	lmAddChild(node_9, node_4);

	assert(9 == lmCountNodes(root_2));

	typedef lmTreeNodeLessPointer<int> comparer;
	assert( (lmIsSameNode<int, comparer>(root_2, findCommonParent1(root_2, root_2))) );
	assert( (lmIsSameNode< int, comparer >(node_7, findCommonParent1(node_2, node_6))) );
	assert( (lmIsSameNode< int, comparer >(root_2, findCommonParent1(node_4, node_6))) );
	assert( (lmIsSameNode< int, comparer >(node_7, findCommonParent1(node_2, node_11))) );

	assert((lmIsSameNode< int, lmTreeNodeLessValue<int> >(node_7, findCommonParent1(node_2, node_11))));

	//////////////////////////////////////////////////////////

	//assert(root_2 == findCommonParent2(root_2, root_2));
	assert(node_7 == findCommonParent2(node_2, node_6));
	//assert(root_2 == findCommonParent2(node_4, node_6));
	assert(node_7 == findCommonParent2(node_2, node_11));

	//////////////////////////////////////////////////////////

	assert(root_2 == findCommonParent3(root_2, root_2));
	assert(node_7 == findCommonParent3(node_2, node_6));
	assert(root_2 == findCommonParent3(node_4, node_6));
	assert(node_7 == findCommonParent3(node_2, node_11));
	assert(node_9 == findCommonParent3(node_4, node_9));

	//////////////////////////////////////////////////////////

	assert(root_2 == findCommonParent4(root_2, root_2));
	assert(node_7 == findCommonParent4(node_2, node_6));
	assert(root_2 == findCommonParent4(node_4, node_6));
	assert(node_7 == findCommonParent4(node_2, node_11));
	assert(node_9 == findCommonParent4(node_4, node_9));
	assert(root_2 == findCommonParent4(node_4, node_7));
	assert(root_2 == findCommonParent4(node_5_2, node_11));
}