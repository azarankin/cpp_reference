#include <iostream>
#include <atomic>
#include <thread>
#include <vector>





std::atomic<int> counter(0); // Atomic counter initialized to 0

void increment()
{
    //counter = 50;
    counter.store(50, std::memory_order_relaxed); //change the value
    for (int i = 0; i < 1000; ++i) 
    {
        counter += 1;   //counter.fetch_add(1, std::memory_order_seq_cst);  //stronger (with Memory Barrier)
        counter.fetch_add(1, std::memory_order_relaxed); // Atomic increment, (no Memory Barrier)
        
    }
}

int main()
{
    std::vector<std::thread> threads;

    // Launch multiple threads
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(increment));
    }

    // Join threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final counter value: " << counter.load() << '\n'; // Should be 10000
    return 0;
}



#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> metric(0); // Atomic metric for monitoring

void worker()
{
    for (int i = 0; i < 100; ++i) {
        metric.fetch_add(1, std::memory_order_relaxed); // Update metric
    }
}

int main2()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(worker);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Metric value: " << metric.load(std::memory_order_relaxed) << '\n'; // May be slightly stale
    return 0;
}





#include <iostream>
#include <atomic>
#include <random>
#include <thread>

std::atomic<int> seed(42); // Thread-safe seed

void generate_random_numbers()
{
    int local_seed = seed.fetch_add(1, std::memory_order_relaxed); // Unique seed for each thread
    std::mt19937 generator(local_seed /*43*/); //ramdom number
    std::cout << "Random number: " << generator() << '\n';
}

int main3()
{
    std::thread t1(generate_random_numbers);
    std::thread t2(generate_random_numbers);

    t1.join();
    t2.join();
    return 0;
}



std::atomic<bool> flag(false);
int shared_data = 0;

void producer()
{
    shared_data = 42; // Update shared data
    flag.store(true, std::memory_order_relaxed); // Notify consumer
}

void consumer()
{
    while (!flag.load(std::memory_order_relaxed)) {} // Spin-wait for flag
    std::cout << "Shared data: " << shared_data << '\n'; // May print stale value
}