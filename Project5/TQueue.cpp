#include "TQueue.h"
using namespace std;

TQueue::TQueue(int size)
{
	this->size = size;
	this->elems = new float[size];
	this->count = 0;
	this->hi = 0;
	this->li = -1;
}

TQueue::TQueue(const TQueue& q)
{
	size = q.size;
	count = q.count;
	hi = q.hi;
	li = q.li;
	int index = hi;
	this->elems = new float[size];
	if (q.IsEmpty())
		return;
	while (index != li)
	{
		elems[index] = q.elems[index];
		index = (++index) % size;
	}
	elems[index] = q.elems[index];
}

TQueue::~TQueue()
{
	delete[] elems;
}

bool TQueue::IsEmpty()const
{
	return(count == 0);
}

bool TQueue::IsFull()const
{
	return(count == size);
}

void TQueue::Push(float q)
{
	if (IsFull())
		throw M_Exeption("queue is full");
	count++;
	li = ++li % size;
	elems[li] = q;
}

float TQueue::Pop()
{
	if (IsEmpty())
		throw M_Exeption("queue is empty");
	count--;
	float p = elems[hi];
	(++hi) % size;
	return p;
}

ostream& operator<< (ostream& out, const TQueue& q)
{
	if (q.IsEmpty())
		throw M_Exeption("queue is empty");
	for (int i = q.hi; i <= q.li; (++i) % q.size)
	{
		out << q.elems[i] << "  ";
	}
	return out;
}