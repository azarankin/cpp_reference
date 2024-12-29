#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void critical_section() {
    if (mtx.try_lock()) { // Try to lock the mutex without blocking
        std::cout << "Thread " << std::this_thread::get_id() << " acquired the lock.\n";
        mtx.unlock(); // Unlock the mutex
    }
    else {
        std::cout << "Thread " << std::this_thread::get_id() << " failed to acquire the lock.\n";
    }
}

int main() {
    std::thread t1(critical_section);
    std::thread t2(critical_section);

    t1.join();
    t2.join();

    return 0;
}
