#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std::chrono_literals;

//Общая переменная, которая будет отслеживать кол-во клиентов в очереди
thread_local int q_count = 0;

//Метод которые увеличивает переменную клиентов 
void clients_count(int q) {
    q_count = 0;    
    while (q_count < q) 
    {       
        std::this_thread::sleep_for(1000ms);
        q_count++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        std::cout << "Clients added to the queue " << q_count << std::endl;
    }   
}
//Метод которые уменьшает переменную клиентов 
void operator_count(int q) {
    q_count = q;   
    for (int i = 0; i < q; i++) 
    {  
        std::this_thread::sleep_for(2003ms);
        q_count--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        std::cout << "There are still customers in the queue " << q_count << std::endl;
    }   
}

int main()
{
    int queque = 0;
    do {
        std::cout << "Enter the max number of clients in the queque:" << std::endl;
        std::cin >> queque;

    } while (queque <= 0);

    std::thread t1(clients_count,queque);
    std::thread t2(operator_count, queque);

    t1.join();
    t2.join();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
