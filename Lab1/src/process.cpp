#include <process.hpp>

#include <iostream>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>


namespace cse4733 {

    process::process(const std::string& path, const std::vector<std::string>& args)
        : processId(-1), executablePath(path), arguments(args) {}

    bool process::execute() {

        std::vector<char*> argv;
        for (const auto& arg : arguments) {
            argv.push_back(const_cast<char*>(arg.c_str()));
        }
        argv.push_back(nullptr);

        // TODO
        // 1. Fork the parent process to create a child process.
        pid_t c = fork();
        // 2. If the fork fails, display an error message and exit.
        if (c < 0) 
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        // 3. If the fork succeeds, continue with the parent and child processes.
        // 4. In the parent process:
        else if (c > 0)
        {
        //    - Display the parent process ID (PID).
            std::cout << "Parent PID: " << getpid() << std::endl;        
        //    - Display the child's PID.
            std::cout << "Child PID: " << c << std::endl;
        //    - Display a message indicating the role as "Parent".
            std::cout << "Role: Parent" << std::endl;         
        //    - Wait for the child process to terminate using the wait() system call.
            wait();
        //    - Display a message indicating the termination of the child process.
            std::cout << "Child bye bye" << std::endl;
        //    - Exit the parent process.
            exit(EXIT_SUCCESS);
        }
        
        // 5. In the child process:
        else
        {
        //    - Display the child's PID.        
            std::cout << "Child PID: " << getpid() << std::endl;
        //    - Display the parent's PID.
            std::cout << "Parent PID: " << getppid() << std::endl;
        //    - Display a message indicating the role as "Child".                    
            std::cout << "Role: Child" << std::endl;
	//    - Use evecvp to execute command string found in executablePath
	//      and arguments contained in 'argv'
	    if (execvp(executablePath.c_str(), argv.data()))
	    {
	        perror("Error");
	        exit(EXIT_FAILURE);
	    }
        //    - Sleep for a few seconds using the sleep() system call.
            sleep(1);
        //    - Exit the child process. 
            exit(EXIT_SUCCESS);
        }
        return true;
    }

    void process::wait() {
      int status;
      waitpid(processId, &status, 0);
    }

pid_t process::get_id() const {
	return this->processId;
}

} // namespace cse4733
