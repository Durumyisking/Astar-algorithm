#pragma once
class CNode
{
//func
public:
	CNode(int _x, int _y, int _name)
		: NextNode(nullptr)
	{
		x = _x;
		y = _y;
		nodeName = _name;
		g = 0;
		h = 0;
		f = 0;
	}

	bool operator<(const CNode& a) const 
	{
		return this->f < a.f;
	}

// var
public:
	CNode* NextNode;
	int x, y;
	int g, h, f;
	char nodeName;

};

