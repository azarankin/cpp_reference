#include <thread>
#include <functional>
#include <iostream>
#include <exception>
#include <sstream>

void execute_on_another_thread(std::function<void()> background_task)
{
    // Declare an exception_ptr to capture any exceptions in the thread.
    std::exception_ptr exp_ptr = nullptr;

    // Start a new thread to run the background task.
    std::thread t([&]() {
        try
        {
            background_task(); // Run the task
        }
        catch (...)
        {
            exp_ptr = std::current_exception(); // Capture any exception
        }
        });

    t.join(); // Wait for the thread to finish

    // Check if an exception was thrown in the thread
    if (exp_ptr)
    {

        //try{
    	std::rethrow_exception(exp_ptr); // Rethrow the caught exception
        //} catch (const std::exception& e) {
            //std::cout << "Exception caught: " << e.what() << std::endl;
        //}
    }
    else
    {
        std::cout << "No exceptions occurred." << std::endl;
    }
}

// A sample task that throws an exception


int main()
{
    // Execute the task on another thread and handle exceptions
    try
    {
        execute_on_another_thread([&]()
        {
        	std::stringstream msg;
            msg << "Something went wrong!\n" << "Error in thread id " << std::this_thread::get_id() << "\n";
            throw std::runtime_error(msg.str().c_str());
        });
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught:\n" << e.what() << '\n';
    }
    return 0;
}
