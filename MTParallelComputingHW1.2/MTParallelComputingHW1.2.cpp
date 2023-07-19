#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <condition_variable>

//Метод который выводит кол-во аппаратных ядер
std::once_flag flag;
void print_cpu() {
    std::cout << "Количество аппаратных ядер " << std::thread::hardware_concurrency() << std::endl;
    /*std::cout << std::endl;
    std::cout << std::endl;*/
}

//Создаем вектор и заполняем его случайными числами
std::vector<int> create_vector(int size) {
    std::vector<int> vec(size);
    int r = (rand() % 100) + 1;
    std::srand(std::time(nullptr) + r);
    for (int i = 0; i < size; ++i) {
        vec[i] = (rand() % 100) + 1;
    }
    return vec;
}
//Метод на случай если надо вывести содержимое вектора на консоль
void print_vec(const std::vector<int>& vector) {
    for (auto& v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}


//Метод суммирует два вектора между сбой
void sum_vectors(std::vector<int>& a, std::vector<int>& b, std::vector<int>& sum,
    int start, int end)
{
    std::call_once(flag, print_cpu);

    for (int i = start; i < end; i++) {
        sum[i] = a[i] + b[i];
    }

}

//Подсчет времени операции суммирования в потоке 
double time_count(std::vector<int>& a, std::vector<int>& b, std::vector<int>& sum, int n_thread)
{
    //std::vector<int> vec_t = size_split(n_thread, v_size);

    std::vector<std::thread> vec_thread;
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < n_thread; i++)
    {
        vec_thread.push_back(std::thread(sum_vectors, std::ref(a), std::ref(b), std::ref(sum),
            (i * a.size()) / n_thread, ((i + 1) * a.size()) / n_thread));

    }

    for (auto& v : vec_thread) {
        v.join();
    }
    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    double duration = delta.count() / 1000.0;

    return duration;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<std::pair<int, double>> data;
    int vec_size = 1000;


    for (int i = 0; i < 4; ++i) {

        auto v1 = create_vector(vec_size);
        auto v2 = create_vector(vec_size);
        std::vector<int> sum_result(v1.size());
        data.push_back(std::make_pair(vec_size, time_count(v1, v2, sum_result, 1)));
        data.push_back(std::make_pair(vec_size, time_count(v1, v2, sum_result, 2)));
        data.push_back(std::make_pair(vec_size, time_count(v1, v2, sum_result, 4)));
        data.push_back(std::make_pair(vec_size, time_count(v1, v2, sum_result, 8)));
        data.push_back(std::make_pair(vec_size, time_count(v1, v2, sum_result, 16)));
        vec_size *= 10;
    }

    std::cout << "        ";
    /*for (int i = 0; i < data.size(); i+=5) {
        std::cout << std::setw(1) << data[i].first << "\t ";
    }*/
    std::cout << std::endl;
    std::cout << std::setw(4) << "1 поток    ";
    for (int i = 0; i < data.size(); i += 5) {
        std::cout << data[i].second << "s" << "\t";
    }
    std::cout << std::endl;
    std::cout << std::setw(4) << "2 потока   ";
    for (int i = 1; i < data.size(); i += 5) {
        std::cout << std::setw(4) << data[i].second << "s" << "\t";
    }
    std::cout << std::endl;
    std::cout << std::setw(4) << "4 потока   ";
    for (int i = 2; i < data.size(); i += 5) {
        std::cout << std::setw(4) << data[i].second << "s" << "\t";
    }
    std::cout << std::endl;
    std::cout << std::setw(4) << "8 потоков  ";
    for (int i = 3; i < data.size(); i += 5) {
        std::cout << std::setw(4) << data[i].second << "s" << "\t";
    }
    std::cout << std::endl;
    std::cout << std::setw(4) << "16 потоков ";
    for (int i = 4; i < data.size(); i += 5) {
        std::cout << std::setw(4) << data[i].second << "s" << "\t";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    /*for (const auto& elem : data) {
        std::cout << elem.first << " -> " << elem.second <<"s" << std::endl;
    }*/


}
