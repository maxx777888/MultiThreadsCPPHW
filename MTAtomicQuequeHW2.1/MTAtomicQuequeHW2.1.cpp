#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <Windows.h>

using namespace std::chrono_literals;

//Общая переменная, которая будет отслеживать кол-во клиентов в очереди
std::atomic<int> q_count;

//Метод которые увеличивает переменную клиентов 
void clients_count(int q) {

    for (int i = 0; i < q; i++)
    {
        std::this_thread::sleep_for(1000ms);
        q_count++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        std::cout << "Clients added to the queue " << q_count.load() << std::endl;
    }
}
//Метод которые уменьшает переменную клиентов 
void operator_count(int q) {

    for (int i = 0; i < q; i++)
    {
        std::this_thread::sleep_for(2000ms);
        q_count--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        std::cout << "There are still customers in the queue " << q_count.load() << std::endl;
    }
}

int main()
{
    int queque = 0;
    do {
        std::cout << "Enter the max number of clients in the queque:" << std::endl;
        std::cin >> queque;

    } while (queque <= 0);

    //Работа с различными способами упорядочения доступа к памяти
    //q_count.store(0, std::memory_order_seq_cst);
    //q_count.store(0, std::memory_order_consume); //НЕ работает
    //q_count.store(0, std::memory_order_acquire); //НЕ работает
    //q_count.store(0, std::memory_order_release); 
    //q_count.store(0, std::memory_order_acq_rel); //НЕ работает
    q_count.store(0, std::memory_order_relaxed);


    std::thread t1(clients_count, queque);
    std::thread t2(operator_count, queque);

    t1.join();
    t2.join();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
