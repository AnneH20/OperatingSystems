#include "round_robin.hpp"

#include<algorithm>
#include<queue>

namespace cse4733 {

void round_robin::run(std::vector<std::shared_ptr<cse4733::Process>>& processes, int quantum)
{
    int n = processes.size();
    int time = 0;
    int total_waiting = 0;
    int total_turnaround = 0;
    std::queue<std::shared_ptr<cse4733::Process>> ready_queue;

    // For all arriving processes in processes list
    //   Add process to ready queue
    //   Remove process from processes list
    // EndFor
    for (auto item : processes)
    {
        ready_queue.push(item);
        
    }

    // TODO:
    //
    // Loop until all processes are removed from the ready queue
    while (!ready_queue.empty())
    {
    //   Get process from ready queue
        auto current_process = ready_queue.front();
        ready_queue.pop();
    //   Execute the process for the quantum or remaining time, whichever is smaller
        int execution_time = std::min(quantum, current_process->get_remaining_time());
    //   Add execution time to time
        time += execution_time;
    //   Set the remaining time for the process
        current_process->set_remaining_time(current_process->get_remaining_time() - execution_time);
    //   If the remaining time for the process is not zero THEN
        if (current_process->get_remaining_time() > 0)
        {
    //     Add process to the back of the ready queue
            ready_queue.push(current_process);
        }
    //   Else
        else
        {
    //     Set the completion time for the process
            current_process->set_completion_time(time);
    //     Set the turnaround time for the process
            int turnaround_time = current_process->get_completion_time() - current_process->get_arrival_time();
            current_process->set_turnaround_time(turnaround_time);
    //     Add turnaround time to turnaround time total
            total_turnaround += turnaround_time;
    //     Set the waiting time for the process
            int waiting_time = current_process->get_turnaround_time() - current_process->get_burst_time();
            current_process->set_waiting_time(waiting_time);
    //     Add waiting time to waiting time total
            total_waiting += waiting_time;
    //   End If
        }
    // End Loop
    }

    std::cout << "Round Robin Scheduling:\n";
    std::cout << "Process ID\tCompletion Time\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (auto obj : processes) {
        std::cout << "  " << *obj << std::endl;
    }
    std::cout << "  Average Waiting Time: " << (double)total_waiting / n << std::endl;
    std::cout << "  Average Turnaround Time: " << (double)total_turnaround / n << std::endl;
}

}

