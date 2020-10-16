#include <iostream>

#include "thread_safe_queue.h"
#include "queue_entry_factory.h"
#include "process_queue_entry.h"

/*
	Provide a high level imlementation for a thread safe message queue with multiple producer thread and a single consumer thread.
	Implement Push, Pop accessor methods.
	Concentrate on locking and thread waiting mechanism.
	Use high level data structures, STL::queue
*/

/*
	Driver code
*/

int main()
{
	ThreadSafeQueue<QueueEntry> safeQueue;

	auto producer = [](ThreadSafeQueue<QueueEntry>& safeQueue)
	{
		while (true)
		{
			QueueEntry ent = CreateANewEntry();
			safeQueue.Push(ent);
		}
	};

	auto consumer = [](ThreadSafeQueue<QueueEntry>& safeQueue)
	{
		while (true)
		{
			QueueEntry ent = safeQueue.Pop();
			ProcessQueueEntry(ent);
		}
	};

	std::thread producerThread(producer, std::ref(safeQueue));

	std::thread consumerOneThread(consumer, std::ref(safeQueue));
	std::thread consumerTwoThread(consumer, std::ref(safeQueue));


	producerThread.join();

	consumerOneThread.join();
	consumerTwoThread.join();

	return 0;
}
