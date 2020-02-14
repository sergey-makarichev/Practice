#pragma once
#include "TList.h"
#include "TNode.h"
#include "TMonom.h"

using namespace std;

template<>
class TList<int, float>
{
private:
	TNode<int, float>* pFirst;
	TNode<int, float>* pCurrent;
	TNode<int, float>* pPrevious;
	TNode<int, float>* pNext;
public:
	TList();
	TList(const TList&);
	TList(TNode<int, float>*);
	~TList();
	TNode<int, float>* Search(int);
	void InsertBegin(int, float);
	void InsertBegin(TNode<int, float>*);
	void InsertEnd(int, float);
	void InsertEnd(TNode<int, float>*);
	void InsertAfter(int, TNode<int, float>*);
	void InsertBefore(int, TNode<int, float>*);
	void Remove(int);

	bool IsEmpty()const;
	bool IsEnded()const;
	void Reset();
	void Next();

	TNode<int, float>* GetFirst()const;
	TNode<int, float>* GetCurrent()const;
};

TList<int, float> ::TList()
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
}

TList<int, float> ::TList(TNode<int, float>* first)
{
	pPrevious = nullptr;
	pNext = nullptr;
	TNode<int, float>* node = new TNode<int, float>(*first);
	pFirst = node;
	TNode<int, float>* prev = pFirst;
	TNode<int, float>* it = first->pNext;
	while (it)
	{
		TNode<int, float>* tmp = new TNode<int, float>(*it);
		prev->pNext = it;
		prev = tmp;
		it = it->pNext;
	}
	prev->pNext = nullptr;
	pCurrent = pFirst;
	pNext = pCurrent->pNext;
}

TList<int, float> ::TList(const TList& list)
{
	if (list.pFirst == nullptr)
	{
		pFirst = nullptr;
		pCurrent = nullptr;
		pPrevious = nullptr;
		pNext = nullptr;
	}
	else
	{
		pFirst = new TNode<int, float>(*list.pFirst);
		pPrevious = nullptr;
		pCurrent = pFirst;
		pNext = pFirst->pNext;
		TNode<int, float>* tmp1(pFirst), * tmp2(list.pFirst);
		while (tmp2->pNext != nullptr)
		{
			tmp1->pNext = new TNode<int, float>(*(tmp2->pNext));
			tmp2 = tmp2->pNext;
			tmp1 = tmp1->pNext;
		}
		tmp1->pNext = nullptr;
	}

}

TList<int, float> ::~TList()
{
	while (pFirst != nullptr)
	{
		pNext = pFirst->pNext;
		delete pFirst;
		pFirst = pNext;
	}
}

TNode<int, float>* TList<int, float> ::Search(int key)
{
	if (pFirst == nullptr)
		throw"list is empty";
	TNode<int, float>* tmp = pFirst;
	while ((tmp != nullptr) && (tmp->key != key))
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"Key not found";
	return tmp;
}

void TList<int, float> ::InsertBegin(int NewKey, float NewData)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<int, float>(NewKey, NewData);
		pCurrent = pFirst;
		pPrevious = nullptr;
		pNext = nullptr;
		return;
	}
	TNode<int, float>* tmp = new TNode<int, float>(NewKey, NewData);
	tmp->pNext = pFirst;
	if (pCurrent = pFirst)
		pPrevious = tmp;
	pFirst = tmp;
	return;
}


void TList<int, float> ::InsertBegin(TNode<int, float>* node)
{
	InsertBegin(node->key, node->pData);
}

void TList<int, float> ::InsertEnd(int NewKey, float NewData)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<int, float>(NewKey, NewData);
		pCurrent = pFirst;
		pPrevious = nullptr;
		pNext = nullptr;
		return;
	}
	TNode<int, float>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new TNode<int, float>(NewKey, NewData);
	if (pCurrent == tmp)
		pNext = tmp->pNext;
	tmp->pNext->pNext = nullptr;
	return;
}

void TList<int, float> ::InsertEnd(TNode<int, float>* node)
{
	InsertEnd(node->key, node->pData);
}

void TList<int, float> ::InsertAfter(int SearchKey, TNode<int, float>* node)
{
	TNode<int, float>* tmp = pFirst;
	while (tmp != nullptr && tmp->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"Key not found";
	TNode<int, float>* NewNode = new TNode<int, float>(node->key, node->pData);
	NewNode->pNext = tmp->pNext;
	if (pCurrent == tmp)
		pNext = NewNode;
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	tmp->pNext = NewNode;
	return;
}

void TList<int, float> ::InsertBefore(int SearchKey, TNode<int, float>* node)
{
	if (pFirst == nullptr)
		throw "empty";
	if (pFirst->key == SearchKey)
	{
		TNode<int, float>* NewNode = new TNode<int, float>(node->key, node->pData);
		NewNode->pNext = pFirst;
		if (pCurrent = pFirst)
			pPrevious = NewNode;
		pFirst = NewNode;
		return;
	}
	TNode<int, float>* tmp = pFirst;
	while (tmp->pNext->key != SearchKey && tmp != nullptr)
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"Key not found";
	TNode<int, float>* NewNode = new TNode<int, float>(node->key, node->pData);
	NewNode->pNext = tmp->pNext;
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	if (pCurrent == tmp)
		pNext = NewNode;
	tmp->pNext = NewNode;
	return;
}

void TList<int, float> ::Remove(int SearchKey)
{
	if (pFirst == nullptr)
		throw "list is empty";
	TNode<int, float>* tmp = pFirst;
	if (pFirst->key == SearchKey)
	{
		if (pCurrent == pFirst)
		{
			pCurrent = pNext;
			if (pNext)
				pNext = pNext->pNext;
			else
				pNext = nullptr;
			pFirst = pFirst->pNext;
			delete tmp;
			return;
		}
		if (pCurrent == pFirst->pNext)
		{
			pPrevious = nullptr;
			pFirst = pFirst->pNext;
			delete tmp;
			return;
		}
		pFirst = pFirst->pNext;
		delete tmp;
		return;
	}
	tmp = Search(SearchKey);
	Reset();
	while (pCurrent != tmp)
		Next();
	pPrevious->pNext = pNext;
	pCurrent = pNext;
	pNext = pCurrent->pNext;
	delete tmp;
	return;
}

bool TList<int, float> ::IsEmpty()const
{
	return(pFirst == nullptr);
}

bool TList<int, float> ::IsEnded()const
{
	return(pCurrent == nullptr);
}

void TList<int, float> ::Reset()
{
	if (pFirst == nullptr)
		throw "list is empty";
	pCurrent = pFirst;
	pPrevious = nullptr;
	pNext = pCurrent->pNext;
	return;
}

void TList<int, float> ::Next()
{
	if (IsEnded())
		throw"end of list";
	pPrevious = pCurrent;
	pCurrent = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
	return;
}

TNode<int, float>* TList<int, float> ::GetFirst()const
{
	return pFirst;
}

TNode<int, float>* TList<int, float> ::GetCurrent()const
{
	return pCurrent;
}