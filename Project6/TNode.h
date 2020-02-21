#pragma once

using namespace std;

template<typename TKey, typename TData>
class TNode
{
public:
	TKey key;
	TData* pData;
	TNode<TKey, TData>* pNext;
	TNode();
	TNode(TKey, TData*, TNode<TKey, TData>* pNext = 0); // TNode<TKey, TData>* pNext = 0
	TNode(const TNode&);
	~TNode();
};
template<typename TKey, class TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	pData = nullptr;
	pNext = nullptr;
}

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(TKey key, TData* pData, TNode<TKey, TData>* pNext)
{
	this->key = key;
	//this->pData = pData;
	this->pData = new TData(*(pData));
	this->pNext = pNext;
}

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& node)
{
	this->key = node.key;
	//this->pData = node.pData;
	this->pData = new TData(*(node.pData));
	pNext = nullptr;
}

template<typename TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	delete pData;
}