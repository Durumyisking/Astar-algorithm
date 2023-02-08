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
		// ��������� F����� ���� ���� ��带 pop �� ���� ��Ͽ� �ִ´�.
		CNode* node = openList.top();

		SetOpenList(node);

		// ����
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

	// F�� ���� ������� ������ÿ� push
	Result.push(_node);
	closeList.push_back(_node);

}

bool CAstar::Check(CNode* _node)
{
	if (_node->x == this->endPosX && _node->y == this->endPosY)
	{
		std::cout << "����!!" << std::endl;
		return true;
	}

	// ������� ������� ��� X (ù �õ� pass)
	if (openList.empty())
	{
		if (bInitallize)
		{
			std::cout << "��� ����!!" << std::endl;
			return true;
		}
		else
			bInitallize = true;
	}

	return false;
}

// ���
void CAstar::Explore(CNode* _node)
{
	// ����� 8������ ������Ͽ� �ִ´� (�̵��Ұ���� ����)
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// �ڱ� �ڽ� continue (���μ��θ�)
			if (0 == i && 0 == j)
				continue;

			if(0 != i)
				if (-1 == j || 1 == j)
					continue;

			

			int x = _node->x + j;
			int y = _node->y + i;
			
			// �� �ٱ� continue
			if (x < 0 || y < 0 || x >(sizeX - 1) || y >(sizeY - 1))
				continue;

			// �̵� �Ұ����� continue
			if ('1' == map[y * sizeX + x])
				continue;

			// ����/���� ��Ͽ� �̹� ������ continue
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

			newNode->ParentNode = _node; // �� ����� �θ�� ���� ��带 ����

			newNode->SetScore();

			iterableOpenList.push_back(newNode);
			openList.push(newNode);
		}
	}
}

