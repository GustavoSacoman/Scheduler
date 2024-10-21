#include <iostream>
#include "Process.h"
#include "../include/Process.h"
#include <atomic>
#include "../include/Dispatcher.h"


//Priority 1 to 10
int main() {

	std::vector<Process> low_process;
	std::vector<Process> high_process;
	std::vector<Process> allList;
	Process* p = new Process(5555, High, 0, 10, 'R');
	Process* g = new Process(2222, Idle, 0, 5, 'R');
	Process* h = new Process(3333, Normal, 0, 25, 'R');
	Process* i = new Process(1000, Real_time, 0, 3, 'R');
	Process* l = new Process(7777, Below_normal, 0, 3, 'R');

	allList.push_back(*p);
	allList.push_back(*h);
	allList.push_back(*i);
	allList.push_back(*g);
	allList.push_back(*l);

	for (auto& temp : allList) {
		if (temp.priority >= 3)
			high_process.push_back(temp);
		else
			low_process.push_back(temp);
	}

	std::thread creating_queue_low(creating_queue, std::ref(low_process));
	std::thread creating_queue_high(creating_queue, std::ref(high_process));
	creating_queue_low.join();
	creating_queue_high.join();



	
	std::thread running_low_process(priority_process_running, std::ref(low_process));
	
	std::thread interrupt_low(ready_process);
	interrupt_low.join();
	running_low_process.join();

	


	delete p;
	delete g;
	delete h;
	delete i;
	delete l;


}
