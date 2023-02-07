#include "Astar.h"

CAstar::CAstar()
	: endNode(nullptr)
{
	startNode = new CNode(3, 3, 'S');

	openList.push(startNode);
	Result.push(startNode);
}

CAstar::~CAstar()
{
}
