#include "PTQueue.h"
#include "TQueue.h"
#include "Exception.h"

using namespace std;

int main()
{
	try
	{
		TQueue<TPriorityQueueElem> q(4);
		TPriorityQueueElem a(2, 4);
		TPriorityQueueElem b(13, 8);
		TPriorityQueueElem c(1, 2);
		TPriorityQueueElem p(98, 16);
		q.Push(a);
		q.Push(b);
		q.Push(c);
		q.Push(p);
		cout << q.Pop();
		cout << q.Pop();
		cout << q.Pop();
		cout << q.Pop();
	}
	catch (const M_Exeption & exception)
	{
		cerr << " Error: " << exception.what() << endl;


	}

	system("pause");
	return 0;

}