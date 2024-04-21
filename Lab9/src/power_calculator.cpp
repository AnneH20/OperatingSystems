#include <cse4733/power_calculator.hpp>

#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

namespace cse4733 {

PowerCalculator::PowerCalculator(): is_running(true) {}

void PowerCalculator::start() {
    std::thread t1(&PowerCalculator::thread1_task, this);
    std::thread t2(&PowerCalculator::thread2_task, this);

    t1.join();
    t2.join();
}

// Generates random pairs (base, power) of numbers and pushes them to a queue
void PowerCalculator::thread1_task() {


    // TODO (part 1):
    // 1. Create an instance of std::random_device
    std::random_device randomDevice;
    // 2. Create an instance of std::mt19937
    std::mt19937 gen(randomDevice());
    // 3. Create a uniform integer distribution for the integer values (1 - 100).
    //    Use the std::uniform_int_distribution.
    std::uniform_int_distribution<int> dist(1, 100);
    // 4. Create a uniform integer distribution for the power value (1-10).
    //    Use the std::uniform_int_distribution.
    std::uniform_int_distribution<int> power_dist(1, 10);
    // 5. Set the time limit to 50 microseconds
    auto timeLimit = std::chrono::microseconds(50);
    // 6. Capture the start time using std::chrono
    auto startTime = std::chrono::steady_clock::now();
    // 7. Create elapsed time variable using std::chrono::duration
    std::chrono::microseconds elapsedTime;
    // 8. WHILE (true)
    while (true) {
    //    a. Create an instance of std::lock_guard
        std::lock_guard<std::mutex> lock(mtx);
    //    b. Get a random value from the uniform int distribution
        int randomValue = dist(gen);
    //    c. Get a random power value from the uniform int distribution
        int randomPower = power_dist(gen);
    //    d. Add random value and random power to the queue
        data_queue.push(std::make_pair(randomValue, randomPower));
    //    e. Calculate elapsed time from now to start time
        elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - startTime);
    //    f. If elapsed time exceeds the limit then break out of while loop.
        if (elapsedTime > timeLimit) {
            break;
        }
    }
    // 7. Set is_running to false.
    is_running = false;

    // End TODO (part 1)


}

// Pulls the number pairs from the queue, calculates the base raised to the power, and prints the result
void PowerCalculator::thread2_task() {


    // TODO (part 2):
    // 1. While the is_running is true and the queue is not empty
    while (is_running || !data_queue.empty()) {
    //    a. Create an instance of std::lock_guard
        std::lock_guard<std::mutex> lock(mtx);
    //    b. IF the queue is not empty, THEN grab the integer value and power value from the queue
        if (!data_queue.empty()) {
            auto pair = data_queue.front();
            data_queue.pop();
        
    //    c. IF the integer value and power value are not zero THEN
            if (pair.first != 0 && pair.second != 0) {
    //       1) calculate the power value
                long powerValue = std::pow(pair.first, pair.second);
    //       2) Write power results to the console (e.g. Power of 2 raised to the 2 is 4)
                std::cout << pair.first << " to the power of " << pair.second << " is " << powerValue << std::endl;
            }
        }
    }
    // End TODO (part 2)

}

}
