#include "Astar.h"


using namespace std;

char map[7][5] = {
	{'S', '0', '0', '0', '1'},
	{'0', '1', '0', '0', '0' },
	{'0', '1', '1', '1', '0' },
	{'0', '0', '0', '0', '0' },
	{'0', '0', '1', 'E', '0' },
	{'0', '1', '1', '1', '0' },
	{'0', '0', '0', '0', '0' }	
};
// S : 0, 2
// E : 3, 5
	
int main()
{
	char* pMap = *map;

	CAstar* astar = new CAstar(pMap, 7, 5, 3, 4);	

	delete astar;

	return 0;
}