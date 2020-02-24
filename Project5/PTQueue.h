#pragma once
#include "TQueue.h"
#include "Exception.h"

using namespace std;

template<>
class TQueue<TPriorityQueueElem>
{
private:
	int size;
	int count;
	TPriorityQueueElem* elems;
public:
	TQueue(int size = 10);
	TQueue(const TQueue<TPriorityQueueElem>& q);
	~TQueue();
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(TPriorityQueueElem q);
	TPriorityQueueElem Pop();
};

TQueue<TPriorityQueueElem>::TQueue(int size)
{
	if (size <= 0)
		throw M_Exeption("wrong size");
	this->size = size;
	this->elems = new TPriorityQueueElem[size];
	this->count = 0;
}

TQueue<TPriorityQueueElem>::TQueue(const TQueue<TPriorityQueueElem>& q)
{
	size = q.size;
	count = q.count;
	this->elems = new TPriorityQueueElem[q.size];
	if (q.IsEmpty())
		return;
	for (int i = 0; i < q.count; i++)
		elems[i] = q.elems[i];
}

TQueue<TPriorityQueueElem>::~TQueue()
{
	delete[] elems;
}

bool TQueue<TPriorityQueueElem>::IsEmpty()const
{
	return(count == 0);
}

bool TQueue<TPriorityQueueElem>::IsFull()const
{
	return(count == size);
}

void TQueue<TPriorityQueueElem>::Push(TPriorityQueueElem q)
{
	if (IsFull())
		throw M_Exeption("queue is full");
	if (IsEmpty())
	{
		elems[count] = q;
		count++;
		return;
	}
	int mid = 0;
	int i1 = 0;
	int i2 = count - 1;
	while (i1 <= i2)
	{
		mid = (i1 + i2) / 2;
		if (elems[mid] == q)
			i1 = i2 + 1;
		else if (elems[mid] < q)
			i1 = mid + 1;
		else 
			i2 = mid - 1;
	}
	if (i1 > mid)
	{
		for (int j = count; j > mid; j--)
			elems[j] = elems[j - 1];
		elems[mid + 1] = q;
		count++;
		return;
	}
	else if (i2 <= mid)
	{
		for (int j = count; j > mid - 1; j--)
			elems[j] = elems[j - 1];
		elems[mid] = q;
		count++;
		return;
	}
}

TPriorityQueueElem TQueue<TPriorityQueueElem>::Pop()
{
	if (IsEmpty())
		throw M_Exeption("queue is empty");
	TPriorityQueueElem p = elems[count - 1];
	count--;
	return p;
}




