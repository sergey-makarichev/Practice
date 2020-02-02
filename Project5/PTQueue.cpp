#include "PTQueue.h"

void PTQueue::Push(float q, int pr)
{
	if (IsFull())
		throw M_Exeption("queue is full");
	count++;
	if (li == -1)
	{
		li = ++li % size;
		elems[li] = q;
		prioritet[li] = pr;
		return;
	}
	int index = hi;
	while (prioritet[index] <= pr && index != this->li + 1)
	{
		index = ++index % size;
	}
	if (index > li)
	{
		elems[index] = q;
		prioritet[index] = pr;
		li = ++li % size;
		return;
	}
	for (int i = li; i != index - 1; i = (--i + size) % size)
	{
		elems[i + 1] = elems[i];
		prioritet[i + 1] = prioritet[i];
	}
	elems[index] = q;
	prioritet[index] = pr;
	li = ++li % size;
}

PTQueue::PTQueue(int size)
{
	this->size = size;
	this->elems = new float[size];
	this->prioritet = new int[size];
	this->count = 0;
	this->hi = 0;
	this->li = -1;
}

PTQueue::~PTQueue()
{
	delete[] prioritet;
}

PTQueue::PTQueue(const PTQueue& q)
{
	size = q.size;
	count = q.count;
	hi = q.hi;
	li = q.li;
	int index = hi;
	this->elems = new float[size];
	this->prioritet = new int[size];
	if (q.IsEmpty())
		return;
	while (index != li)
	{
		elems[index] = q.elems[index];
		prioritet[index] = q.prioritet[index];
		index = (++index) % size;
	}
	elems[index] = q.elems[index];
	prioritet[index] = q.prioritet[index];
}