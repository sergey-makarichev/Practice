#pragma once
#include "TList.h"
#include "TNode.h"
#include "TMonom.h"
#include <iostream>

using namespace std;

template<>
class TList<int, float> //delete
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
	void Sort();

	bool IsEmpty()const;
	bool IsEnded()const;
	void Reset();
	void Next();

	TNode<int, float>* GetFirst()const;
	TNode<int, float>* GetCurrent()const;
	TNode<int, float>* GetNext()const;
	TNode<int, float>* GetPrev()const;

	friend class Polinom;
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
	pCurrent = nullptr;
	if (first == nullptr)
		pFirst == nullptr;
	else
	{
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
		Reset();
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
	pCurrent = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
}

void TList<int, float> ::Sort()
{
	if (pFirst == nullptr)
		return;
	if (pFirst->pNext == nullptr)
		return;
	TNode<int, float>* a, *b, *rev, *prev_a;
	for (bool ListDone = true; ListDone;)
	{
		ListDone = false;
		a = pFirst;
		b = pFirst->pNext;
		prev_a = a;
		while (b != nullptr)
		{
			if (a->key < b->key)
			{
				if (prev_a = a)
					pFirst = b;
				else
					prev_a->pNext = b;
				a->pNext = b->pNext;
				b->pNext = a;
				rev = a;
				a = b;
				b = rev;
				ListDone = true;
			}
			prev_a = a;
			a = a->pNext;
			b = b->pNext;
		}

	}
	Reset();
}

TNode<int, float>* TList<int, float> ::Search(int key)
{
	if (pFirst == nullptr)
		throw"list is empty";
	TNode<int, float>* tmp = pFirst;
	while ((tmp != nullptr) && (tmp->key != key))
		tmp = tmp->pNext;
	if (tmp == nullptr)
		cout << "there is no such key";
	return tmp;
}

void TList<int, float> ::InsertBegin(int NewKey, float NewData)
{
	TNode<int,float>* tmp = new TNode<int,float>(NewKey, NewData, pFirst);
	if (pCurrent == pFirst)
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
		InsertBegin(NewKey, NewData);
		Reset();
		return;
	}
	TNode<int,float>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new TNode<int,float>(NewKey, NewData);
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
	TNode<int,float>* tmp = pFirst;
	while (tmp != nullptr && tmp->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key" << endl;
		return;
	}
	TNode<int,float>* NewNode = new TNode<int,float>(node->key, node->pData, tmp->pNext);
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
		InsertBegin(node->key, node->pData);
		return;
	}
	TNode<int,float>* tmp = pFirst;
	while (tmp != nullptr && tmp->pNext->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key" << endl;
		return;
	}
	TNode<int, float>* NewNode = new TNode<int, float>(node->key, node->pData, tmp->pNext);
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	if (pCurrent == tmp)
		pNext = NewNode;
	tmp->pNext = NewNode;
}

void TList<int, float> ::Remove(int SearchKey)
{
	if (pFirst == nullptr)
		throw "list is empty";
	TNode<int,float>* tmp = pFirst;
	if (pFirst->key == SearchKey)
	{
		pFirst = pFirst->pNext;
		if (pCurrent == pFirst)
			pPrevious = nullptr;
		delete tmp;// navigation
		Reset();
	}
	while (tmp != nullptr && tmp->pNext->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key for remove" << endl;
		return;
	}
	TNode<int,float>* node = tmp->pNext;
	tmp->pNext = tmp->pNext->pNext;
	if (pCurrent == node)
		Reset();
	if (pCurrent == tmp)
		pNext = tmp->pNext;
	if (pCurrent == tmp->pNext)
		pPrevious = tmp;
	delete node;
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

TNode<int,float>* TList<int,float> ::GetNext()const
{
	return pNext;
}

TNode<int,float>* TList<int,float> ::GetPrev()const
{
	return pPrevious;
}