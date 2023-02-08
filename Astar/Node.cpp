#include "Node.h"
#include "Astar.h"

void CNode::SetScore()
{
	// g = �ֻ�� �θ�κ����� ���� �̵��� (���� ���ιۿ������� ������ �θ� +10 �̴�)
	g = ParentNode->g + 10;


	// h = �������������� ����Ÿ� (��ֹ� ����)
	int ix = abs(aStar->endPosX - x);
	int iy = abs(aStar->endPosY - y);
	h = (ix + iy) * 10;


	// f = g + h
	f = g + h;

}
