#pragma once
class CAstar;
class CNode
{
//func
public:
	CNode(int _x, int _y, int _name, CAstar* _aStar)
		: NextNode(nullptr)
		, ParentNode(nullptr)
		, bClosed(false)
		, aStar(_aStar)
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
	bool operator>(const CNode& a) const
	{
		return this->f > a.f;
	}


	void SetScore();

	void GetAstar();

// var
public:
	CNode* NextNode;
	CNode* ParentNode;
	int x, y;
	int g, h, f;
	char nodeName;

	bool bClosed;

	CAstar* aStar;
};

