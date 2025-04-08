#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;

    Process(int i, int b) {
        id = i;
        burst_time = b;
        waiting_time = 0;
        turnaround_time = 0;
    }
};

// Comparator function to sort processes by burst time
bool compareByBurstTime(const Process& a, const Process& b) {
    return a.burst_time < b.burst_time;
}

void calculateWaitingTime(vector<Process>& proc) {
    proc[0].waiting_time = 0;

    for (size_t i = 1; i < proc.size(); i++) {
        proc[i].waiting_time = proc[i-1].waiting_time + proc[i-1].burst_time;
    }
}

void calculateTurnaroundTime(vector<Process>& proc) {
    for (size_t i = 0; i < proc.size(); i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void printResults(const vector<Process>& proc) {
    cout << "Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& p : proc) {
        cout << p.id << "\t\t" << p.burst_time << "\t\t" << p.waiting_time << "\t\t" << p.turnaround_time << endl;
    }
}

int main() {
    // Initialize processes with {ID, Burst Time}
    vector<Process> proc = { {1, 6}, {2, 8}, {3, 7}, {4, 3} };

    // Step 1: Sort processes based on burst time (SJF rule)
    sort(proc.begin(), proc.end(), compareByBurstTime);

    // Step 2: Calculate waiting and turnaround times
    calculateWaitingTime(proc);
    calculateTurnaroundTime(proc);

    // Step 3: Display results
    printResults(proc);

    return 0;
}
