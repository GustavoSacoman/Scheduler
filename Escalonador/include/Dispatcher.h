#pragma once
#include <queue>
#include <vector>
#include "Process.h"
auto creating_queue(std::vector<Process>& list_process);
extern std::atomic<bool> add_process_flag;