#include <thread>
#include <memory>
#include <mutex>

std::mutex mtx;
 // Locks immediately

int func1()
{
    mtx.lock();
    //progress
    mtx.unlock();
}

int func2()
{
    std::unique_lock<std::mutex> lock(mtx); //std::lock_guard<std::mutex> lock(mtx); 
    //progress
}


int func2()
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    //progress
    lock.lock();
    //progress
    //lock.unlock();
}



main()
{

}

