#ifndef SHORTEST_JOB_FIRST_HPP
#define SHORTEST_JOB_FIRST_HPP

#include <process.hpp>

#include <iostream>
#include <memory>
#include <vector>

namespace cse4733 {

class shortest_job_first
{
private:


    // Comparator function for SJF scheduling
    bool static compare(const std::shared_ptr<cse4733::Process>& a,
                        const std::shared_ptr<cse4733::Process>& b);

public:

    /**
     * @brief Execute the shortest_job_first algorithm
     */
    void run(std::vector<std::shared_ptr<cse4733::Process>>& processes);
};


} // namespace cse4733

#endif // SHORTEST_JOB_FIRST_HPP
