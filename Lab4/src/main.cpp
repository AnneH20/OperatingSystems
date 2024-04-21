#include <atomic>
#include <iostream>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

std::atomic_int signal_terminate(0);
std::atomic_int counter(0);
std::atomic_int sleep_value(1);

// Signal handler function for SIGINT
void handleSIGINT(int signal)
{
    // TODO:
    // - Report the receipt of interrupt signal
    std::cout << "Received interrupt signal" << std::endl;
    // - Report the number of forks counter
    std::cout << "Number of forks counter = " << counter.load() << std::endl;
    // - Set signal_terminate to one
    signal_terminate = 1;
}

// Signal handler function for SIGUSR1
void handleSIGUSR1(int signal)
{
    // TODO:
    // - Report the receipt of user signal 1
    std::cout << "Received user signal 1" << std::endl;
    // - Report the number of forks counter
    std::cout << "Number of forks counter = " << counter.load() << std::endl;
    // - Add one to sleep_value
    sleep_value++;
    // - Report the increased thread sleep value
    std::cout << "New thread sleep value = " << sleep_value << std::endl;
}

// Signal handler function for SIGALRM
void handleSIGALRM(int signal)
{
    // TODO: 
    // - Report the receipt of the alarm signal
    std::cout << "Received alarm signal" << std::endl;
    // - Subtract one from sleep_value
    sleep_value--;
    // - Report the decreased thread sleep value
    std::cout << "New thread sleep value = " << sleep_value << std::endl;
}

int main()
{
    auto pid = getpid();

    // Register signal handlers
    signal(SIGINT, handleSIGINT);
    signal(SIGUSR1, handleSIGUSR1);
    signal(SIGALRM, handleSIGALRM);

    // Main program logic
    std::cout << "(Processs ID: " << pid << "). Running the program. Press Ctrl+C to send SIGINT." << std::endl;

    // Send SIGUSR1 Signal to add to sleep counter
    kill(pid, SIGUSR1);

    // Send SIGALRM after five seconds to decrease sleep counter
    alarm(5);

    // Simulating a long-running process

    while (signal_terminate.load() != 1)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            std::cerr << "Failed to fork a child process." << std::endl;
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process
            // - Report the child process identification number using getpid()
            std::cout << "Child process ID is " << getpid() << std::endl;
	    // - Have the child process sleep for X seconds. X = sleep_value
            sleep(sleep_value);
            // - Terminate child process using exit()
            exit(0);
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            std::cout << "Child process " << pid << " has exited with status: " << WEXITSTATUS(status) << std::endl;
        }

        counter++;
    }

    return 0;
}

