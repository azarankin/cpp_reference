#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx;

void defer_lock_example() {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    lock.lock();
    std::cout << "Deferred lock acquired\n";
}

void adopt_lock_example() {
    mtx.lock();
    std::unique_lock<std::mutex> lock(mtx, std::adopt_lock);
    std::cout << "Adopted lock acquired\n";
}

void try_lock_example() {
    std::unique_lock<std::mutex> lock(mtx, std::try_to_lock);
    if (lock.owns_lock()) {
        std::cout << "Try-lock succeeded\n";
    }
    else {
        std::cout << "Try-lock failed\n";
    }
}

void timed_lock_example() {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    if (lock.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "Timed lock succeeded\n";
    }
    else {
        std::cout << "Timed lock failed\n";
    }
}

int main() {
    std::thread t1(defer_lock_example);
    std::thread t2(adopt_lock_example);
    std::thread t3(try_lock_example);
    std::thread t4(timed_lock_example);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
