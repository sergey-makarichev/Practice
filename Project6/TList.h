#pragma once
#include<iostream>
#include "TNode.h"

using namespace std;

template<typename TKey, typename TData>
class TList
{
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pCurrent;
	TNode<TKey, TData>* pPrevious;
	TNode<TKey, TData>* pNext;
public:
	TList();
	TList(const TList&);
	TList(TNode<TKey, TData>*);
	~TList();
	TNode<TKey, TData>* Search(TKey);
	void InsertBegin(TKey, TData*);
	void InsertBegin(TNode<TKey, TData>*);
	void InsertEnd(TKey, TData*);
	void InsertEnd(TNode<TKey, TData>*);
	void InsertAfter(TKey, TNode<TKey, TData>*);
	void InsertBefore(TKey, TNode<TKey, TData>*);
	void Remove(TKey);

	bool IsEmpty()const;
	bool IsEnded()const;
	void Reset();
	void Next();

	TNode<TKey, TData>* GetFirst()const;
	TNode<TKey, TData>* GetCurrent()const;
};

template<typename TKey, typename TData>
TList<TKey, TData> ::TList()
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
}

template<typename TKey, typename TData>
TList<TKey, TData> ::TList(TNode<TKey, TData>* node)
{
	pFirst = node;
	pCurrent = node;
	pPrevious = nullptr;
	pNext = nullptr;
}

template<typename TKey, typename TData>
TList<TKey, TData> ::TList(const TList& list)
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
		pFirst = new TNode<TKey, TData>(*list.pFirst);//Инициализация значения, находящегося по адресу указателя
		pPrevious = nullptr;
		pCurrent = pFirst;
		pNext = pFirst->pNext;
		TNode<TKey, TData>* tmp1(pFirst), * tmp2(list.pFirst);
		while (tmp2->pNext != nullptr)
		{
			tmp1->pNext = new TNode<TKey, TData>(*(tmp2->pNext));
			tmp2 = tmp2->pNext;
			tmp1 = tmp1->pNext;
		}
		tmp1->pNext = nullptr;
	}

}

template<typename TKey, typename TData>
TList<TKey, TData> ::~TList()
{
	while (pFirst != nullptr)
	{
		pNext = pFirst->pNext;
		delete pFirst;
		pFirst = pNext;
	}
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::Search(TKey key)
{
	if (pFirst == nullptr)
		throw"Error";
	TNode<TKey, TData>* tmp = pFirst;
	while ((tmp != nullptr) && (tmp->key != key))
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"no key";
	return tmp;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertBegin(TKey NewKey, TData* NewData)
{
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>();
	tmp->key = NewKey;
	tmp->pData = new TData(*NewData);
	tmp->pNext = pFirst;
	if (pCurrent = pFirst)
		pPrevious = tmp;
	pFirst = tmp;
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertBegin(TNode<TKey, TData>* node)
{
	InsertBegin(node->key, node->pData);
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertEnd(TKey NewKey, TData* NewData)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TKey, TData>;
		pFirst->key = NewKey;
		pFirst->pData = new TData(*NewData);
		pCurrent = pFirst;
		pPrevious = nullptr;
		pNext = nullptr;
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new TNode<TKey, TData>(NewKey, *NewData);
	tmp->pNext->pNext = nullptr;
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertEnd(TNode<TKey, TData>* node)
{
	InsertEnd(node->key, node->pData);
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertAfter(TKey SearchKey, TNode<TKey, TData>* node)
{
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp != nullptr && tmp->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"Key not found";
	TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData);
	NewNode->pNext = tmp->pNext;
	tmp->pNext = NewNode;
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertBefore(TKey SearchKey, TNode<TKey, TData>* node)
{
	if (pFirst == nullptr)
		throw "empty";
	if (pFirst->key == SearchKey)
	{
		TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData);
		NewNode->pNext = pFirst;
		if (pCurrent = pFirst)
			pPrevious = NewNode;
		pFirst = NewNode;
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp->pNext->key != SearchKey && tmp != nullptr)
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"Key not found";
	TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData);
	NewNode->pNext = tmp->pNext;
	tmp->pNext = NewNode;
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::Remove(TKey SearchKey)
{
	if (pFirst == nullptr)
		throw "list is empty";
	TNode<TKey, TData>* tmp = pFirst;
	if (pFirst->key == SearchKey)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		return;
	}
	while (tmp->pNext->key != SearchKey && tmp != nullptr)
		tmp = tmp->pNext;
	if (tmp == nullptr)
		throw"Key not found";
	TNode<TKey, TData>* node = tmp->pNext;
	tmp->pNext = tmp->pNext->pNext;
	delete node;
	return;
}

template<typename TKey, typename TData>
bool TList<TKey, TData> ::IsEmpty()const
{
	return(pFirst == nullptr);
}

template<typename TKey, typename TData>
bool TList<TKey, TData> ::IsEnded()const
{
	return(pCurrent == nullptr);
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::Reset()
{
	if (pFirst == nullptr)
		throw "list is empty";
	pCurrent = pFirst;
	pPrevious = nullptr;
	pNext = pCurrent->pNext;
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::Next()
{
	if (IsEnded())
		throw"end of list";
	pPrevious = pCurrent;
	pCurrent = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
	return;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetFirst()const
{
	return pFirst;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetCurrent()const
{
	return pCurrent;
}