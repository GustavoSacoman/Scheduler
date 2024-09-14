
struct Process
{
	const int pid{};
	int runtime_initial{};
	int runtime_final{};
	enum criticaly { non_critical, medium, critical, very_critical };
	
};


