#include "shortest_job_first.hpp"

#include<algorithm>

namespace cse4733 {


// Comparator function for SJF scheduling
bool shortest_job_first::compare(const std::shared_ptr<cse4733::Process>& a,
                                    const std::shared_ptr<cse4733::Process>& b) {
    return a->get_burst_time() < b->get_burst_time();
}

void shortest_job_first::run(std::vector<std::shared_ptr<cse4733::Process>>& processes)
{
    int current_time = 0;
    int total_waiting = 0;
    int total_turnaround = 0;

    // TODO:
    // Step 1: Sort processes from shortest to longest
    std::sort(processes.begin(),
              processes.end(),
              compare);

    // Step 2: Find the highest arrival time for the processes
    int highest_arrival_time = 0;
    for (auto& item : processes)
    {
        highest_arrival_time = std::max(highest_arrival_time, item->get_arrival_time());
    }
    for (auto& item : processes)
    {
    //         Set arrival time for all processes to highest arrival time plus one        
        item->set_arrival_time(highest_arrival_time + 1);
    }    

    // Step 3:
    // For all processes
    for (auto& item : processes)
    {
        // Without this, turnaround time calculations are incorrect
        // due to completion time being less than arrival time.
        if (current_time < item->get_arrival_time())
        {
            current_time = item->get_arrival_time();
        }
        
        //   Set the completion time for the process to previous completion_time plus burst time
        int completion_time = current_time + item->get_burst_time();
        item->set_completion_time(completion_time);
        current_time = completion_time;
        //   Set the turn around time for the process to completion time minus arrival time
        int turnaround_time = item->get_completion_time() - item->get_arrival_time();
        item->set_turnaround_time(turnaround_time);
        //   Calculate the wait time to completion minus burst time
        int wait_time = item->get_turnaround_time() - item->get_burst_time();
        //   Set the wait time for the process
        item->set_waiting_time(wait_time);
        //   Increment total wait time
        total_waiting += wait_time;
        //   Increment total turnaround time
        total_turnaround += turnaround_time;
    }

    std::cout << "SJF Scheduling:" << std::endl;
    std::cout << "Process ID\tCompletion Time\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << std::endl;
    for (auto item : processes)
    {
        std::cout << "  " << *item << std::endl;
    }
    std::cout << "  Average waiting time (tics): " << total_waiting / processes.size() << std::endl;
    std::cout << "  Average turnaround time (tics): " << total_turnaround / processes.size() << std::endl << std::endl;
}
}