#pragma once
#include <iostream>
#include "Exception.h"

using namespace std;


struct TPriorityQueueElem
{
	int priority;
	float elem;

	bool operator > (const TPriorityQueueElem& e) const
	{
		return priority > e.priority;
	}
};

template<class TElemType>
class TQueue
{
protected:
	int size;
	int count;
	int hi;
	int li;
	TElemType* elems;
public:
	TQueue(int size = 10);
	TQueue(const TQueue& q);
	~TQueue();
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(TElemType q);
	TElemType Pop();
	friend ostream& operator<< (ostream& out, const TQueue& q);
	friend istream& operator>> (istream& in, TQueue& q);
};

template<>
class TQueue<TPriorityQueueElem>
{
protected:
	int size;
	int count;
	int hi;
	int li;
	TPriorityQueueElem* elems;
public:
	TQueue(int size = 10);
	TQueue(const TQueue& q);
	~TQueue();
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(TPriorityQueueElem q);
	TPriorityQueueElem Pop();
	friend ostream& operator<< (ostream& out, const TQueue& q);
	friend istream& operator>> (istream& in, TQueue& q);
};