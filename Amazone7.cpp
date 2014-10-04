#include "stdafx.h"

#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct g_reference;

struct g_node {
	char name;
	vector<g_reference> ways;
};

struct g_reference {
	int weight;
	g_node *ref;
};

g_node * createNode(char name)
{
	g_node *n = new g_node();
	n->name = name;

	return n;
}

g_reference createReference(int weight, g_node *n)
{
	g_reference r;
	r.weight = weight;
	r.ref = n;

	return r;
}

void findPath(g_node *from, map<g_node*, g_reference>* measured)
{
	typedef map<g_node*, g_reference> TMap;

	int currentWeight = 0;
	TMap::const_iterator found = measured->find(from);
	if ( measured->end() != found )
		currentWeight = found->second.weight;
	else
	{
			g_reference destNew;
			destNew.ref = from;
			destNew.weight = 0;
			measured->insert( make_pair( from, destNew ) );
	}

	map<int, g_node*> task;
	for (unsigned i = 0; i < from->ways.size(); i++)
	{
		g_reference dest = from->ways[i];

		int weight = currentWeight + dest.weight;
		
		TMap::const_iterator alreadyMeasured = measured->find(dest.ref);
		if ( alreadyMeasured == measured->end() || alreadyMeasured->second.weight > weight)
		{
			g_reference destNew;
			destNew.ref = from;
			destNew.weight = weight;
			measured->erase( dest.ref );
			measured->insert( make_pair( dest.ref, destNew ) );
			cout << dest.ref->name << ": " << from->name << ":" << weight << endl;

			task.insert( make_pair(weight, dest.ref));
		}
	}

	while (!task.empty())
	{
		auto n = task.begin()->second;
		//task.pop();

		findPath(n, measured);
		task.erase(task.begin()->first);
		//break;
	}
}

vector<g_reference> findPath(const vector<g_node*>& nodes, int from, int to)
{
	map<g_node*, g_reference> measured;
	g_node *fromNode = nodes[from];
	findPath(fromNode, &measured );

	vector<g_reference> tmp;
	typedef map<g_node*, g_reference> TMap;
	TMap::const_iterator found = measured.find(nodes[to]);
	while(found->first != fromNode)
	{
		tmp.push_back(found->second);
		found = measured.find(found->second.ref);
	}
	return tmp;
}

void Amazone7()
{
	g_node *a = createNode('a');
	g_node *b = createNode('b');
	g_node *c = createNode('c');
	g_node *d = createNode('d');
	g_node *e = createNode('e');

	a->ways.push_back(createReference(5, b));
	a->ways.push_back(createReference(2, c));

	b->ways.push_back(createReference(5, a));
	b->ways.push_back(createReference(2, c));
	b->ways.push_back(createReference(7, e));

	c->ways.push_back(createReference(2, b));
	c->ways.push_back(createReference(2, a));
	c->ways.push_back(createReference(6, d));

	d->ways.push_back(createReference(6, c));
	d->ways.push_back(createReference(1, e));

	e->ways.push_back(createReference(7, b));
	e->ways.push_back(createReference(1, d));

	/*
	a->ways.push_back(createReference(5, b));
	a->ways.push_back(createReference(2, c));

	b->ways.push_back(createReference(5, a));
	b->ways.push_back(createReference(2, c));
	b->ways.push_back(createReference(7, e));

	c->ways.push_back(createReference(2, b));
	c->ways.push_back(createReference(2, a));
	c->ways.push_back(createReference(8, d));

	d->ways.push_back(createReference(8, c));
	d->ways.push_back(createReference(10, e));

	e->ways.push_back(createReference(7, b));
	e->ways.push_back(createReference(10, d));
	*/

	vector<g_node*> nodes;
	nodes.push_back(a);
	nodes.push_back(b);
	nodes.push_back(c);
	nodes.push_back(d);
	nodes.push_back(e);

	auto path = findPath(nodes, 0, nodes.size()-1);

	for (unsigned i = 0; i < path.size(); i++)
		cout << path[i].ref->name << "(" << path[i].weight << ") -> ";
}