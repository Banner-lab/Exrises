#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template<typename T>
class QueueTp
{
private:
	enum { Q_SIZE = 10 };
	struct Node
	{
		T item;
		Node* next;
	};
	
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTp(const QueueTp& q) :qsize(0) { }
	QueueTp& operator=(const QueueTp& q) { return *this; }
public:
	QueueTp(int qs = Q_SIZE);
	~QueueTp();
	bool is_empty()const;
	bool is_full()const;
	int queuecount()const;
	bool enqueue(const T it);
	bool dequeue(T& a);
};
template<typename T>
QueueTp<T>::QueueTp(int qs) :qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

template<typename T>
QueueTp<T>::~QueueTp()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<typename T>
bool QueueTp<T>::is_empty()const
{
	return items == 0;
}

template<typename T>
bool QueueTp<T>::is_full()const
{
	return items == qsize;
}

template<typename T>
int QueueTp<T>::queuecount()const
{
	return items;
}

template<typename T>
bool QueueTp<T>::enqueue(const T it)
{
	if (is_full())
		return false;
	Node* add = new Node;
	add->item = it;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<typename T>
bool QueueTp<T>::dequeue(T& it)
{
	if (is_empty())
		return false;
	it = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}

#endif // !QUEUE_H_
