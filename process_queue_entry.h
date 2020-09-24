#pragma once

#include <iostream>
#include "queue_entry.h"

void ProcessQueueEntry(QueueEntry& pEntry)
{
	std::cout << pEntry.getId() << std::endl;
};
