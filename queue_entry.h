#pragma once

class QueueEntry
{
public:
	QueueEntry(unsigned long pId):
		mId(pId)
	{
	}

	QueueEntry(const QueueEntry& pEntry)
	{
		mId = pEntry.mId;
	};

	QueueEntry(QueueEntry&& pEntry) noexcept
	{
		mId = pEntry.mId;
		pEntry.mId = 0;
	}

	unsigned long getId()
	{
		return mId;
	}

private:
	unsigned long mId;
};
