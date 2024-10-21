#include "../include/Dispatcher.h"
#include <thread>
#include <mutex>

std::mutex mtx;

void creating_queue(std::vector<Process>& list_process) {

	//Create the process to test

	while (true) {
		//reorganize list for priority
		std::lock_guard<std::mutex> lock(mtx);
		std::priority_queue<Process, std::vector<Process>, ComparePriority> queue_process;

		for (int i{ 0 }; i < list_process.size(); i++) {
			queue_process.push(list_process[i]);
		}


		for (int i{ 0 }; i < list_process.size(); i++) {
			list_process[i] = queue_process.top();
			queue_process.pop();
		}
	}

}
void add_process_queue(const Process& new_process, std::vector<Process>& list_process) {
	std::lock_guard<std::mutex> lock(mtx);
	list_process.push_back(new_process);
}