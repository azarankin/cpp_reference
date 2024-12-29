#include <iostream>
#include <mutex>

std::mutex mtx;

void critical_section() {
    std::lock_guard<std::mutex> lock(mtx); // Locks the mutex
    // Critical section
    std::cout << "Inside critical section\n";
    // Mutex is unlocked automatically when `lock` goes out of scope
}