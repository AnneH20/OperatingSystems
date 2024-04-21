#include "first_come_first_served.hpp"

#include <iostream>

namespace cse4733 {

void first_come_first_served::run(std::vector<std::shared_ptr<cse4733::Process>>& processes)
{
    int completion_time = 0;
    int total_waiting = 0;
    int total_turnaround = 0;

    // TODO:
    //
    // For all processes
    for (auto item : processes)
    {
    //   Add the process burst time to completion time (how long to run process)
        completion_time += item->get_burst_time();
    //   Set the process completion time 
        item->set_completion_time(completion_time);
    //   Determine the amount of time it took to finish process execution
        int turnaround_time = item->get_completion_time() - item->get_arrival_time();
    //   Set the process turnaround time
        item->set_turnaround_time(turnaround_time);
    //   Add turnaround time to the total turnaround time
        total_turnaround += turnaround_time;
    //
    //   Determine the amount of time the process waited for execution.
        int waiting_time = item->get_turnaround_time() - item->get_burst_time();
    //   Set the process waiting time
        item->set_waiting_time(waiting_time);
    //   Add waiting time to the total waiting time
        total_waiting += waiting_time;
    }

    std::cout << "FCFS Scheduling:" << std::endl
              << "  Process ID\tCompletion Time\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << std::endl;
    for (auto item : processes)
    {
        std::cout << "  " << *item << std::endl;
    }
    std::cout << "  Average waiting time (tics): " << total_waiting / processes.size() << std::endl;
    std::cout << "  Average turnaround time (tics): " << total_turnaround / processes.size() << std::endl << std::endl;
}

}

