#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> dataQueue; // Shared data structure
std::mutex mtx;            // Mutex for synchronizing access
std::condition_variable cv; // Condition variable
bool done = false;         // Flag to indicate the producer is done

// Producer function
void producer() {
    for (int i = 1; i <= 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        {
            std::lock_guard<std::mutex> lock(mtx);
            dataQueue.push(i);
            std::cout << "Produced: " << i << '\n';
        }
        cv.notify_one(); // Notify the consumer
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true; // Signal that production is complete
    }
    cv.notify_all(); // Notify any remaining consumers
}

// Consumer function
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !dataQueue.empty() || done; }); // Wait for data or completion
        while (!dataQueue.empty()) {
            int value = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consumed: " << value << '\n';
        }
        if (done) break; // Exit loop if production is complete
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
