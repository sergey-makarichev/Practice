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
	TNode<TKey, TData>* GetNext()const;
	TNode<TKey, TData>* GetPrev()const;
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
TList<TKey, TData> ::TList(TNode<TKey, TData>* first) // проход до конца списка от node
{
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = nullptr;
	if (first == nullptr)
		pFirst == nullptr;
	else
	{
		TNode<TKey, TData>* node = new TNode<TKey, TData>(*first);
		pFirst = node;
		TNode<TKey, TData>* prev = pFirst;
		TNode<TKey, TData>* it = first->pNext;
		while (it)
		{
			TNode<TKey, TData>* tmp = new TNode<TKey, TData>(*it);
			prev->pNext = it;
			prev = tmp;
			it = it->pNext;
		}
		prev->pNext = nullptr;
		pCurrent = pFirst;
		pNext = pCurrent->pNext;
	}
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
		tmp = tmp->pNext; // нужна ли проверка на ненайденный ключ
	if (tmp == nullptr)
		cout << "there is no such key";
	return tmp;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertBegin(TKey NewKey, TData* NewData)
{
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(NewKey, NewData, pFirst);
	if (pCurrent == pFirst)
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
	if (pFirst == nullptr)//insert begin
	{
		InsertBegin(NewKey, NewData);
		Reset();
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new TNode<TKey, TData>(NewKey, NewData);
	if (pCurrent == tmp)
		pNext = tmp->pNext;
	tmp->pNext->pNext = nullptr;// navigation
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
	if (pFirst == nullptr)
		throw "empty";
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp != nullptr && tmp->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key" << endl;
		return;
	}
	TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData, tmp->pNext);
	if (pCurrent == tmp)
		pNext = NewNode;
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	tmp->pNext = NewNode;// navigation
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData> ::InsertBefore(TKey SearchKey, TNode<TKey, TData>* node)
{
	if (pFirst == nullptr)
		throw "empty";
	if (pFirst->key == SearchKey)// insert begin
	{
		InsertBegin(node->key, node->pData);
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp != nullptr && tmp->pNext->key != SearchKey) // invert
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key" << endl;
		return;
	}
	TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData, tmp->pNext);
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	if (pCurrent == tmp)
		pNext = NewNode;
	tmp->pNext = NewNode;// navigation
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
	TNode<TKey, TData>* node = tmp->pNext;
	tmp->pNext = tmp->pNext->pNext;
	if (pCurrent == node)
		Reset();
	if (pCurrent == tmp)
		pNext = tmp->pNext;
	if (pCurrent == tmp->pNext)
		pPrevious = tmp;
	delete node;// navigation
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
		throw "list is empty";//
	pCurrent = pFirst;
	pPrevious = nullptr;
	pNext = pCurrent->pNext;
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

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetNext()const
{
	return pNext;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetPrev()const
{
	return  pPrevious;
}