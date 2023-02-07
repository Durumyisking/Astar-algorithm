#pragma once
#include "zz.h"

#include "Node.h"


struct cmp
{
	bool operator()(CNode* a, CNode* b)
	{
		//if (a->f == b->f) // ������ ����
		//	return a->f > b->f;

		// f�� ������ �켱
		return a->f > b->f;
	}
};

class CAstar
{
public:
	CAstar();
	~CAstar();

	void SetOpenList();
	void SetScore(CNode* _Node);
	

public:
	std::priority_queue<CNode*, std::vector<CNode>, cmp > openList;
	std::list<CNode*> closeList;


	std::stack<CNode*> Result;

	CNode* startNode;
	CNode* endNode;

};

