#pragma once
class CAstar;
class CNode
{
//func
public:
	CNode(int _x, int _y, int _name, CAstar* _aStar)
		: ParentNode(nullptr)
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
	bool operator==(const CNode& a) const
	{
		return this->f == a.f;
	}

	void SetScore();

// var
public:
	CNode* ParentNode;
	int x, y;
	int g, h, f;
	char nodeName;
	int number;

	CAstar* aStar;
};

