#pragma once

/*
	Sources:

		https://stackoverflow.com/questions/36762248/why-is-stdqueue-not-thread-safe

*/

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class ThreadSafeQueue
{
public:
	ThreadSafeQueue()
	{};

	void Push(T& pEntry)
	{
		std::unique_lock<std::mutex> lock(mMutex);
		mQueue.push(std::move(pEntry));
		lock.unlock();
		mCond.notify_one();
	}

	T Pop()
	{
		std::unique_lock<std::mutex> lock(mMutex);
		while (mQueue.empty())
		{
			// wait for data
			mCond.wait(lock);
		}
		
		T entry = mQueue.front();
		mQueue.pop();
		return entry;
	}

private:
	std::queue<T> mQueue;
	std::mutex mMutex;
	std::condition_variable mCond;
};
