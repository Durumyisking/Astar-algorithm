#include "Node.h"
#include "Astar.h"

void CNode::SetScore()
{
	// g = 최상단 부모로부터의 누적 이동값 (가로 세로밖에없으니 무조건 부모 +10 이다)
	g = ParentNode->g + 10;


	// h = 도착지점까지의 절대거리 (장애물 제외)
	int ix = abs(aStar->endPosX - x);
	int iy = abs(aStar->endPosY - y);
	h = (ix + iy) * 10;


	// f = g + h
	f = g + h;

}
