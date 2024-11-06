#include <queue>
#include <chrono>
#include <iostream>
#include "../include/Process.h"
#include <mutex>
#include <atomic>
#include "../include/Dispatcher.h"

std::atomic<bool> flag(true);
std::mutex mtx;
std::condition_variable cv;

void ready_process() {

	Process* cut = new Process(125, Real_time, 0, 3, 'R');

	if (cut->priority > 3)
	{
		
		flag = false;
		std::cout << "Process is ready to run" << std::endl;
		
		start(cut);
		changeSituation(cut);

	}
	else
	{
		std::cout << "Process is not ready to run" << std::endl;

	}

	flag = true;
	delete cut;
}


std::vector<Process> priority_process_running(std::vector<Process> list_process) {



	for (int i{ 0 }; i < list_process.size(); i++) {

		while (flag == false) {

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
			Process temp = list_process[i];

			if (temp.state_process == 'R') {

				start(&temp);

				if (temp.runtime_initial == temp.runtime_final)
				{
					changeSituation(&temp);
					list_process.erase(list_process.begin() + i);
					i--;
				}
				else
				{
					list_process[i] = temp;
				}
			}
		}
	
	return list_process;
}

void start(Process* p) {

	flag = true;

	std::lock_guard<std::mutex> lock(mtx);
	for (int i{ 0 }; i < 10 && p->runtime_initial != p->runtime_final && flag == true; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));


		p->runtime_initial++;
		std::cout << "Initial: " << p->runtime_initial << "\n";
		std::cout << "Final: " << p->runtime_final << "\n";
		std::cout << p->pid << "\n";


	}
	cv.notify_all();

}
void changeSituation(Process* process) {

	process->state_process = 'E';
}







