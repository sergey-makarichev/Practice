#pragma once
#include <iostream>
#include "Exception.h"

using namespace std;


struct TPriorityQueueElem
{
	int priority;
	float elem;
	TPriorityQueueElem();
	TPriorityQueueElem(int priority, float elem);

	bool operator > (const TPriorityQueueElem& e) const
	{
		return priority > e.priority;
	}
	bool operator < (const TPriorityQueueElem& e) const
	{
		return priority < e.priority;
	}
	bool operator == (const TPriorityQueueElem& e) const
	{
		return priority == e.priority;
	}
	friend std::ostream& operator<<(std::ostream& out, const TPriorityQueueElem q);
};

TPriorityQueueElem::TPriorityQueueElem()
{
	priority = 1;
	elem = 1;
}

TPriorityQueueElem::TPriorityQueueElem(int priority, float elem)
{
	if (priority < 0)
		throw M_Exeption("wrong priority");
	this->priority = priority;
	this->elem = elem;
}

std::ostream& operator<<(std::ostream& out, const TPriorityQueueElem q)
{
	out << q.elem << std::endl;
	out << std::endl;
	return out;
}

template<class TElemType>
class TQueue
{
private:
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
};

template<class TElemType>
TQueue<TElemType>::TQueue(int size)
{
	this->size = size;
	this->elems = new TElemType[size];
	this->count = 0;
	this->hi = 0;
	this->li = -1;
}

template<class TElemType>
TQueue<TElemType>::TQueue(const TQueue& q)
{
	size = q.size;
	count = q.count;
	hi = q.hi;
	li = q.li;
	int index = hi;
	this->elems = new TElemType[size];
	if (q.IsEmpty())
		return;
	while (index != li)
	{
		elems[index] = q.elems[index];
		index = (++index) % size;
	}
	elems[index] = q.elems[index];
}

template<class TElemType>
TQueue<TElemType>::~TQueue()
{
	delete[] elems;
}

template<class TElemType>
bool TQueue<TElemType>::IsEmpty()const
{
	return(count == 0);
}

template<class TElemType>
bool TQueue<TElemType>::IsFull()const
{
	return(count == size);
}

template<class TElemType>
void TQueue<TElemType>::Push(TElemType q)
{
	if (IsFull())
		throw M_Exeption("queue is full");
	count++;
	li = ++li % size;
	elems[li] = q;
}

template<class TElemType>
TElemType TQueue<TElemType>::Pop()
{
	if (IsEmpty())
		throw M_Exeption("queue is empty");
	count--;
	TElemType p = elems[hi];
	(++hi) % size;
	return p;
}