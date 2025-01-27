#pragma once

namespace UFG
{
	template <typename T>
	class QueueNode
	{
	public:
		QueueNode<T>* prev;
		QueueNode<T>* next;
		T* data;
	};

	template <typename T>
	class ThreadSafeQueue
	{
	public:
		QueueNode<T> head;
		QueueNode<T> tail;
		qMutex mutex;
	};
}