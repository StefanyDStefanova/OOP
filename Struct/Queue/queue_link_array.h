#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <cassert>

template <typename T>
struct Elem
{
	T data;
	Elem<T>* next;
};

template <typename T>
class Queue
{
private:
	Elem<T>* front;
	Elem<T>* back;

	//???????
	void copyQueue(const Queue&);
	void deleteQueue();

public:
	Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	~Queue();

	bool isEmpty() const;
	void push(const T&);
	void pop(T&);
	void head(T&) const;

	int length();

	void print() const;
};


template <typename T>
bool Queue<T>::isEmpty() const
{
	return back == nullptr;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& r)
{
	front = back = NULL;
	Elem<T>* p = r.front;
	while (p)
	{
		push(p->data);
		p = p->next;
	}
}

template <typename T>
void Queue<T>::deleteQueue()
{
	T x;
	while (!isEmpty())
	{
		pop(x);
	}
}


template <typename T>
Queue<T>::Queue() :front(NULL), back(NULL) {}

template <typename T>
Queue<T>::Queue(const Queue<T>& r)
{
	copyQueue(r);
}

template <typename T>
Queue<T>& Queue<T>::operator= (const Queue<T>& r)
{
	if (this != &r)
	{
		deleteQueue();
		copyQueue(r);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	deleteQueue();
}


template <typename T>
void Queue<T>::push(const T& x)
{
	Elem<T>* p = new Elem<T>;

	assert(p != NULL);

	p->data = x;
	p->next = NULL;

	(back) ? back->next = p : front = p;
	back = p;
}

template <typename T>
void Queue<T>::pop(T& x)
{
	if (isEmpty())
	{
		std::cerr << "The queue is empty.\n";
	}

	Elem<T>* p = front;
	x = p->data;

	if (p == back)
	{
		back = NULL;
		front = NULL;
	}
	else front = p->next;

	delete p;
}

template <typename T>
void Queue<T>::head(T& x) const
{
	if (isEmpty())
	{
		std::cerr << "The queue is empty.\n";
	}
	x = front->data;
}

template <typename T>
void Queue<T>::print() const
{
	T x;
	while (!isEmpty())
	{
		std::cout << x << " ";
		pop(x);
	}
	std::cout << std::endl;
}

template <typename T>
int Queue<T>::length()
{
	T x;
	int n = 0;
	while (!isEmpty())
	{
		n++;
		pop(x);
	}
	return n;
}

#endif
