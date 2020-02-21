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
	TQueue(const TQueue& q);
	~TQueue();
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(TPriorityQueueElem q);
	TPriorityQueueElem Pop();
	void sort();
	friend ostream& operator<< (ostream& out, const TQueue& q);
	friend istream& operator>> (istream& in, TQueue& q);
};

TQueue<TPriorityQueueElem>::TQueue(int size)
{
	if (size <= 0)
		throw M_Exeption("wrong size");
	this->size = size;
	this->elems = new TPriorityQueueElem[size];
	this->count = 0;
}

TQueue<TPriorityQueueElem>::TQueue(const TQueue& q)
{
	if(q.size <= 0)
		throw M_Exeption("wrong size");
	size = q.size;
	count = q.count;
	this->elems = new TPriorityQueueElem[q.size];
	if (q.IsEmpty())
		return;
	int i = 0;
	while (i != count-1)
	{
		elems[i] = q.elems[i];
		i++;
	}
	sort();
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
    for (int i = 0; i < count; i++)
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

void TQueue<TPriorityQueueElem>::sort()
{
	if (count == 1)
		return;
	int j;
	for (int i = 1; i < count; i++)
	{
		TPriorityQueueElem tmp = elems[i];
		j = i - 1;
		while (j >= 0 && elems[j] > tmp)
		{
			elems[j + 1] = elems[j];
			elems[j] = tmp;
			j--;
		}
	}
}


