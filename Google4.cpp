#include "stdafx.h"

/*
Given the relative positions (S, W, N, E, SW, NW, SE, NE) of some pairs of points on a 2D plane, determine whether it is possible. 
No two points have the same coordinates.
e.g., if the input is "p1 SE p2, p2 SE p3, p3 SE p1", output "impossible".
*/

#include <iostream>
#include <assert.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef struct
{
	string src;
	string dst;
	string angle;
}Relation;

typedef struct RelationNode_{
	string name;
	map<string, set<RelationNode_*> > nodes;
}RelationNode;

RelationNode *findNodeByName(RelationNode * root, const string& name, const string& angle)
{
	queue<RelationNode *> task;
	task.push(root);
	while (!task.empty())
	{
		if (task.front()->name == name)
			return task.front();

		for ( const auto& node : task.front()->nodes )
			if (angle.empty() || node.first == angle)
				for ( const auto& nodeInSet : node.second )
				task.push(nodeInSet);

		task.pop();
	}

	return nullptr;
}

string getOpposite(const string& angle)
{
		 if ("S" == angle) return "N";  else if ("N" == angle)  return "S";
	else if ("W" == angle) return "E";  else if ("E" == angle)  return "W";

	else if ("NE" == angle) return "SW";  else if ("SW" == angle)  return "NE";
	else if ("NW" == angle) return "SE";  else if ("SE" == angle)  return "NW";

	assert(false);
	return string();
}

bool TryAddNode(RelationNode **root, const Relation& relation)
{
	if (!*root)
	{
		*root = new RelationNode();
		(*root)->name = relation.src;
	}

	const auto srcNode = findNodeByName(*root, relation.src, string());
	if ( !srcNode )
		// Sorry, for this task we do not create flat hierarchy. Only root-based
		// It is easy to extend it by vector of roots.
		return false;

	const auto dstNode = findNodeByName(*root, relation.dst, string());
	if ( dstNode )
		// If we have this node already, we just make sure that is is correctly placed and test way back
		return 	findNodeByName(srcNode, relation.dst, relation.angle) 
				|| 
				findNodeByName(dstNode, relation.src, getOpposite(relation.angle));

	const auto dst = new RelationNode();
	dst->name = relation.dst;

	if ( srcNode->nodes.end() == srcNode->nodes.find(relation.angle))
	{
		auto iter = srcNode->nodes.insert(make_pair(relation.angle, set<RelationNode_*>()));
		iter.first->second.insert(dst);
	}
	else
	{
		srcNode->nodes[relation.angle].insert(dst);
	}

	return true;
}

bool isPossible(const vector<Relation>& pairs)
{
	if (pairs.empty())
		return true;

	RelationNode *root = nullptr;
	for (const auto& relation : pairs)
	{
		if (!TryAddNode(&root, relation))
			return false;
	}

	return true;
}

void Google4()
{
	Relation r1 { "p1", "p2", "SE" };
	Relation r2 { "p2", "p3", "SE" };
	Relation r3 { "p3", "p1", "SE" };
	Relation r4 { "p3", "p1", "NW" };

	assert( true == isPossible({ r1, r2 }) );
	assert( false == isPossible({ r1, r2, r3 }) );
	assert( true == isPossible({ r1, r2, r4 }) );
}

#if !defined(_MSC_VER)
int main()
{
	Google4();
	return 0;
}
#endif
