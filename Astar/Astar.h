#pragma once
#include "zz.h"

#include "Node.h"

static int  nodeCount = 0;

struct cmp
{
	bool operator()(CNode* a, CNode* b)
	{
		if (a->f == b->f) // 같을경우
		{
			// 늦게 생성된 노드로 설정한다.
			return a->number < b->number;
		}

		// f값 작은게 우선
		return a->f > b->f;
	}
};

class CAstar
{
public:
	CAstar(char* _map, int x, int y, int endPosX, int endPosY);
	~CAstar();

	void SetOpenList(CNode* _node);
	bool Check(CNode* _node);
	void Explore(CNode* _node);
	

public:
	std::priority_queue<CNode*, std::vector<CNode*>, cmp > openList;
	std::list<CNode*> closeList;
	std::list<CNode*> iterableOpenList;


	std::stack<CNode*> Result;

	CNode* startNode;
	CNode* endNode;

	char* map;
	int sizeX, sizeY;

	int endPosX, endPosY;

	bool bInitallize;
	bool bEnd;

};

