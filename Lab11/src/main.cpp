#include <iostream>
#include <thread>
#include <queue>
#include <random>
#include <chrono>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <semaphore.h>

const int QUEUE_SIZE_LIMIT = 10;
const int NUM_RANDOM_NUMBERS = 100;

std::queue<int> sharedQueue;
std::atomic<bool> shouldContinue(true);
std::mutex mutex;
std::condition_variable cv;
sem_t semaphore;

void producerThread()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 50);

    // TODO (part 1):
    // 1. FOR i from 0 to 99 DO:
    for (int i = 0; i < NUM_RANDOM_NUMBERS; i++) {
    //    a. Wait on a semaphore to allow consumer to empty the queue
        sem_wait(&semaphore);
    //    b. Create a std::lock_guard using the mutex to enter the critical section
        std::lock_guard<std::mutex> lock(mutex);
    //    c. Generate a random integer
        int num = distribution(generator);
    //    d. Push number to the shared queue
        sharedQueue.push(num);
    //    e. Write the number to the console output, "Produced: <num>"
        std::cout << "Produced: " << num << std::endl;
    //    f. Notify all threads waiting on the semaphore
        sem_post(&semaphore);
    }
    // 2. Set 'shouldContinue' to false
    shouldContinue = false;
    // 3. Notify all threads waiting on the semaphore
    sem_post(&semaphore);
    // End TODO part 1

}

/**
 * @brief Determine if the calling thread should wait.
 *
 * IF the variable sharedQueue is NOT EMPTY OR IF the variable shouldContinue is FALSE
 *   return TRUE
 * ELSE
 *   return FALSE
 * @return
 */
bool shouldWait()
{
    return !sharedQueue.empty() || !shouldContinue;
}

void consumerThread()
{
    while (true)
    {

	// TODO (part 2):
	//
        // 1. Create a std::unique_lock
        std::unique_lock<std::mutex> lock(mutex);
        // 2. Wait on the condition variable
        cv.wait(lock, shouldWait);
        //    a. Call shouldWait will return TRUE if this thread should wait on the conditional
        // 3. IF the sharedQueue is NOT EMPTY THEN
        if (!sharedQueue.empty()) {
        //    a. Get an item from the queue
            int num = sharedQueue.front();
        //    b. Delete item from the queue
            sharedQueue.pop();
        //    c. Write the consumed integer to console, "Consumed: <num>"
            std::cout << "Consumed: " << num << std::endl;
        //    d. Signal that a slot is available in the queue by calling sem_post
            sem_post(&semaphore);
        }
        // 4. IF shouldContinue is false and the sharedQueue is empty THEN
        if (!shouldContinue && sharedQueue.empty()) {
        //    Terminate loop
            break;
        }
	// End TODO part 2

    }
}

int main()
{
    // Initialize the semaphore
    sem_init(&semaphore, 0, QUEUE_SIZE_LIMIT);

    // Create and launch the producer and consumer threads
    std::thread producer(producerThread);
    std::thread consumer(consumerThread);

    // Wait for the producer thread to finish and join with the consumer thread
    producer.join();
    consumer.join();

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}





