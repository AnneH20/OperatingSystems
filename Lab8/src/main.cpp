#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <boost/program_options.hpp>

// Thread local storage for the number
thread_local int number = 2;
thread_local int prime = 2;

bool isPrime(int number) {
    if(number < 2) return false;
    for(int i = 2; i * i <= number; i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

void work(int id) {
    // TODO (part 1):
    // 1. Use high resolution clock in std::chrono to mark the start time.
    auto start = std::chrono::high_resolution_clock::now();
    // 2. Use duration in std::chrono to keep track of the elapsed time.
    std::chrono::duration<double> elapsed;

    // 3. While true
    while (true) {
        //    a. If number contains a prime number, update prime
        if (isPrime(number)) {
            prime = number;
        }
        //    b. Increment number
        number ++;
        //    c. Current thread voluntary context switch.
        std::this_thread::yield();
        //    d. Calculate elapsed time using high resolution clock in std::chrono
        auto end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        //    e. If elapsed is equal to or greater than 30.0, break;   
        if (elapsed.count() >= 30.0) {
            break;
        }      
    }


    // END TODO (part 1)



    std::stringstream os;
    os << "Thread " << id << " ended. "
       << "Total run time: " << elapsed.count()
       << " seconds. Largest prime calculated: " << prime;
    std::cout << std::flush << os.str() << std::endl;
}



int main(int argc, char *argv[]) {
    try {
        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("threads", boost::program_options::value<int>(), "set the number of threads")
        ;

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }

        // TODO (part 2): 
        // 1. Get the number of threads, N, from the command line
        int numThreads; 
        if (vm.count("threads")) {
            numThreads = vm["threads"].as<int>();
        }
        // 2. Create N threads and put into a vector
        std::vector<std::thread> threads;
        for (int i = 0; i < numThreads; i++) {
            threads.emplace_back(work, i);
        }

        // 3. Have the main thread join() on all threads in the vector 
        for (auto& thread : threads) {
            thread.join();
        }

        // END TODO (part 2)




    }
    catch(std::system_error& e) {
        std::cerr << "System error: " << e.what() << "\n";
        return 1;
    }
    catch(boost::program_options::invalid_option_value& e) {
        std::cerr << "Invalid option value: " << e.what() << "\n";
        return 1;
    }
    catch(boost::program_options::unknown_option& e) {
        std::cerr << "Unknown option: " << e.what() << "\n";
        return 1;
    }
    catch(boost::program_options::multiple_occurrences& e) {
        std::cerr << "Multiple occurrences of the same option: " << e.what() << "\n";
        return 1;
    }
    catch(std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

