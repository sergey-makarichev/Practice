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
	if(q.size <= 0)
		throw M_Exeption("wrong size");
	size = q.size;
	count = q.count;
	this->elems = new TPriorityQueueElem[q.size];
	if (q.IsEmpty())
		return;
	for (int i = 0; i < q.count; i++)
		elems[i] = q[i];
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
	bool flag = false;
	int mid, s_ind;
	int i1 = 0;
	int i2 = count - 1;
	while (i1 <= i2)
	{
		mid = (i1 + i2) / 2;
		if (elems[mid] == q)
		{ 
			s_ind = mid - 1;
			break;
		}
		else if (elems[mid] < q)
			i1 = mid + 1;
		else
			i2 = mid - 1;
	}
    for (int i = 0; i < count; i++)//binary search
    {
        if (q < elems[i])
        {
			count++;
            for (int j = count; j > i; j--)
                elems[j] = elems[j - 1];
            flag = true;
            elems[i] = q;
            return;
        }
    }
	if (!flag)
	{
		count++;
		elems[count - 1] = q;
	}
}

TPriorityQueueElem TQueue<TPriorityQueueElem>::Pop()
{
	if (IsEmpty())
		throw M_Exeption("queue is empty");
	count--;
	TPriorityQueueElem p = elems[count - 1];
	return p;
}




