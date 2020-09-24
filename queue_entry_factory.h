#pragma once
#include "queue_entry.h"

QueueEntry& CreateANewEntry()
{
	static unsigned long entryID = 0;

	return *(new QueueEntry(entryID++));
};
