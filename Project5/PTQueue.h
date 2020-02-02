#pragma once
#include "TQueue.h"
#include "Exception.h"

class PTQueue : public TQueue
{
private:
	int* prioritet;
public:
	void Push(float q, int prioritet);
	PTQueue(int size);
	PTQueue(const PTQueue& q);
	~PTQueue();
};