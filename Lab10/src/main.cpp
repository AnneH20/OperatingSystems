#include <iostream>
#include <queue>
#include <thread>
#include <random>
#include <condition_variable>
#include <atomic>

std::queue<int> temperatureQueue;
std::mutex queueMutex;
std::condition_variable queueCV;
std::atomic<bool> isThread1Running(true);

bool shouldWakeUp()
{
    return !temperatureQueue.empty() || !isThread1Running;
}

void pushTemperature(int temperature)
{
    // TODO (part 1):  
    //
    // Implement the logic to push temperature onto the queue
    // using a mutex and condition variable for synchronization.
    // Make sure to notify the consumer thread after pushing the temperature.
    // 
    //     1. Acquire the lock on the queueMutex using std::unique_lock.
    std::unique_lock<std::mutex> lock(queueMutex);
    //     2. Wait until the condition variable queueCV is signaled and the size of the temperatureQueue is less than 10.
    queueCV.wait(lock, []() {
        return temperatureQueue.size() < 10;
        });
    //     3. Push the temperature value onto the temperatureQueue.
    temperatureQueue.push(temperature);
    //     4. Print a message indicating that Thread 1 pushed the temperature value onto the queue.
    std::cout << "Thread 1 pushed a temperature value of " << temperature << " onto the queue" << std::endl;
    //     5. Notify all threads waiting on the condition variable queueCV.
    queueCV.notify_all();

    // End TODO part 1

}

void thread1()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 50);

    // TODO: (part 2)
    // 
	// 1. Set the variable i to 0.
    int i = 0;
        //
	// 2. Enter a loop while i is less than 100:
    while (i < 100) {
	//     a. Sleep for 100 milliseconds to simulate processing time.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//     b. Generate a random temperature using the random number generator dist.
        int temperature = dist(gen);
	//     c. Call the pushTemperature function with the generated temperature.
        pushTemperature(temperature);
	//     d. Increment the value of i by 1.
        ++i;
    }
        //
	// 3. Set the value of isThread1Running to false.
    isThread1Running = false;
	// 4. Notify all threads waiting on the condition variable queueCV.
    queueCV.notify_all();

        // End TODO part 2

}

void convertTemperature(int temperature)
{
    // Convert temperature to Celsius
    double celsius = (temperature - 32) * 5 / 9.0;
    std::cout << "Thread 2 converted temperature: " << temperature << "F to " << celsius << "C" << std::endl;
}

void convertAndReportTemperature()
{
    // TODO (part 3):
    //
    // 1. Enter a loop while the isThread1Running flag is true or the temperatureQueue is not empty.
    while (isThread1Running || !temperatureQueue.empty()) {
    // 2. Acquire the lock on the queueMutex.
        std::unique_lock<std::mutex> lock(queueMutex);
    // 3. Wait until the condition variable queueCV is signaled and either the temperatureQueue is not empty or isThread1Running is true.
        queueCV.wait(lock, [](){ 
            return !temperatureQueue.empty() || !isThread1Running; 
        });
    // 4. If the temperatureQueue is not empty:
        if (!temperatureQueue.empty()) {
    //     a. Retrieve the front temperature value from the temperatureQueue.
            int temperature = temperatureQueue.front();
    //     b. Remove the front temperature value from the temperatureQueue.
            temperatureQueue.pop();
    //     c. Release the lock on the queueMutex.
            lock.unlock();
    //     d. Call the convertTemperature function with the retrieved temperature value.
            convertTemperature(temperature);
        }
    }
    // End TODO part 3

}

int main()
{
    std::thread t1(thread1);
    std::thread t2(convertAndReportTemperature);

    t1.join();
    t2.join();

    std::cout << "Threads completed." << std::endl;

    return 0;
}
