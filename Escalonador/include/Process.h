#pragma once
#include <iostream>
#include <vector>
#include <thread>

enum PriorityClass
{
	Idle,
	Below_normal,
	Normal,
	Above_normal,
	High,
	Real_time
};

struct Process
{
	unsigned int pid{};
	PriorityClass priority{};
	int runtime_initial{};
	int runtime_final{};
	char state_process;

	Process(int id, PriorityClass priority, int initial, int runtime_final, char state) :
		pid(id), priority(priority), state_process(state),
		runtime_initial(initial), runtime_final(runtime_final) {};
};



struct ComparePriority
{
	bool operator()(const Process& p1, const Process& p2) const
	{
		if (p1.runtime_initial > 0) 
			return p1.priority > p2.priority;
		
		return p1.priority < p2.priority;
	}
};




std::vector<Process> priority_process_running(std::vector<Process> list_process);

void start(Process* p);
void changeSituation(Process* process);
void ready_process();