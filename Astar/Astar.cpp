#include "Astar.h"

CAstar::CAstar(char* _map, int x, int y, int endPosX, int endPosY)
	: endNode(nullptr)
	, map(_map)
	, sizeX(x)
	, sizeY(y)
	, endPosX(endPosX)
	, endPosY(endPosY)
	, bInitallize(false)
{
	startNode = new CNode(0, 2, 'S', this);

	// openlist push
	openList.push(startNode);
	iterableOpenList.push_back(startNode);

	while (true)
	{
		// 열린목록중 F비용이 가장 낮은 노드를 pop 후 닫힌 목록에 넣는다.
		CNode* node = openList.top();

		SetOpenList(node);

		// 로직
		if (Check(node))
			break;
		else
			Explore(node);
	}
}

CAstar::~CAstar()
{
}

void CAstar::SetOpenList(CNode* _node)
{
	openList.pop();
	iterableOpenList.remove(_node);

	// F값 가장 작은노드 결과스택에 push
	Result.push(_node);
	closeList.push_back(_node);

}

bool CAstar::Check(CNode* _node)
{
	if (_node->x == this->endPosX && _node->y == this->endPosY)
	{
		std::cout << "성공!!" << std::endl;
		return true;
	}

	// 열린목록 비었으면 경로 X (첫 시도 pass)
	if (openList.empty())
	{
		if (bInitallize)
		{
			std::cout << "경로 없음!!" << std::endl;
			return true;
		}
		else
			bInitallize = true;
	}

	return false;
}

// 노드
void CAstar::Explore(CNode* _node)
{
	// 노드의 8방향을 열린목록에 넣는다 (이동불가노드 제외)
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// 자기 자신 continue (가로세로만)
			if (0 == i && 0 == j)
				continue;

			if(0 != i)
				if (-1 == j || 1 == j)
					continue;

			

			int x = _node->x + j;
			int y = _node->y + i;
			
			// 맵 바깥 continue
			if (x < 0 || y < 0 || x >(sizeX - 1) || y >(sizeY - 1))
				continue;

			// 이동 불가지형 continue
			if ('1' == map[y * sizeX + x])
				continue;

			// 열린/닫힌 목록에 이미 있으면 continue
			bool flag = false;
			for (CNode* node : closeList)
			{
				if (x == node->x && y == node->y)
				{
					flag = true;
					break;
				}
			}
			for (CNode* node : iterableOpenList)
			{
				if (x == node->x && y == node->y)
				{
					flag = true;
					break;
				}
			}

			if (flag)
				continue;


			CNode* newNode;
			if (x == endPosX && y == endPosY)
				newNode = new CNode(x, y, 'E', this);
			else
				newNode = new CNode(x, y, 'N', this);

			newNode->ParentNode = _node; // 새 노드의 부모로 현재 노드를 지정

			newNode->SetScore();

			iterableOpenList.push_back(newNode);
			openList.push(newNode);
		}
	}
}

