#include "../include/Dispatcher.h"
#include <thread>
#include <atomic>

extern std::atomic<bool> add_process_flag{ false };

void dispatcher(std::vector<Process>& list_process) {

	if (list_process.empty()) return;

	while (list_process.size() >= 0) {

	}

}
auto creating_queue(std::vector<Process>& list_process) {
	
	std::priority_queue<Process, std::vector<Process>, ComparePriority> queue_process;
		for (int i{ 0 }; i < list_process.size(); i++) {
			queue_process.push(list_process[i]);
		}
	return queue_process;
}
inline void add_process_queue(const Process& new_process, std::vector<Process>& list_process) {
	add_process_flag = true;
	list_process.push_back(new_process);
	add_process_flag = false;
}