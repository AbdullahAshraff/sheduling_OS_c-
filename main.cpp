#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
	static string algorithm;
	int process_id;
	int arrival_time;
	int burst_time;
	int remaining_time;
	Process();
	Process(int process_id,int arrival_time,int burst_time);
	bool operator<(Process &other);
};

string Process::algorithm = "Not Determined";

Process::Process(int process_id,int arrival_time,int burst_time)
{
	this->process_id = process_id;
	this->arrival_time = arrival_time;
	this->burst_time = burst_time;
	this->remaining_time = burst_time;
}
bool Process::operator<(Process &other){
	if (Process::algorithm == "FCFS"){
		return this->arrival_time < other.arrival_time;
	}
	if (Process::algorithm == "SJF"){
		return this->burst_time < other.burst_time;
	}
	throw std::invalid_argument("the algorithm is not defined. put FCFS or SJF");
}

void scheduling_algorithm(vector<Process> &prs){

	sort(prs.begin(),prs.end());
	cout << "the scedule of process ids is as following:\n";
	for(auto x:prs)
	cout << x.process_id<<'\n';
	
}
int main(){
	Process::algorithm = "FCFS";
	Process p1 = Process(1,0,9);
	Process p2 = Process(2,4,4);
	Process p3 = Process(3,2,9);
	Process p4 = Process(4,1,9);
	vector<Process> prs{p1,p2,p3,p4};


	scheduling_algorithm(prs);


}
