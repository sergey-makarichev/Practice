#pragma once
#include "TNode.h"

using namespace std;

template<>
class TNode<int, float>
{
public:
	unsigned int key;
	float pData;
	TNode<int, float>* pNext;
	TNode() : key(0), pData(0), pNext(nullptr)
	{
	}
	TNode(int NewKey, float Data) : key(NewKey), pData(Data), pNext(nullptr)
	{
	}
	TNode(const TNode& tmp) : key(tmp.key), pData(tmp.pData), pNext(nullptr)
	{
	}
	~TNode();
	TNode<int, float>* operator+(const TNode<int, float>&);
	TNode<int, float>* operator-(const TNode<int, float>&);
	TNode<int, float>* operator*(const TNode<int, float>&);
	bool operator <(const TNode<int, float>&)const;
	bool operator !=(const TNode<int, float>&)const;
	bool operator ==(const TNode<int, float>&)const;
};

TNode<int, float> :: ~TNode()
{
	pNext = nullptr;
}

bool TNode<int, float> ::operator <(const TNode& OtherMonom)const
{
	return(this->key < OtherMonom.key);
}

bool TNode<int, float> ::operator ==(const TNode& OtherMonom)const
{
	return(this->key == OtherMonom.key);
}

bool TNode<int, float> ::operator !=(const TNode& OtherMonom)const
{
	return(this->key != OtherMonom.key);
}

TNode<int, float>* TNode<int, float> :: operator+(const TNode& OtherMonom)
{
	TNode<int, float> m(*this);
	if (m == OtherMonom)
	{
		m.pData += OtherMonom.pData;
		return &m; //мусор после выхода из метода
	}
	else
		throw"different degree";
}

TNode<int, float>* TNode<int, float> :: operator-(const TNode& OtherMonom)
{
	TNode<int, float> m(*this);
	if (m == OtherMonom)
	{
		m.pData -= OtherMonom.pData;
		return &m; //мусор после выхода из метода
	}
	else
		throw"different degree";
}