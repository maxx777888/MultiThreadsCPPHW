#include <iostream>
#include <random>
#include <vector>
#include <future>



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
//Метод проверяет ячейку вектора и если число четное выводит на консоль
void print_even_number(int i) 
{
    if (i % 2 == 0) 
    {
        std::cout << i << "\t";
    }
}


template<typename It, typename Func>
void for_each_async(It begin, It end, Func func) 
{
    auto cur_size = std::distance(begin, end);
    if (cur_size <= 5) {
        
        std::for_each(begin, end, func);
        return;
    }
    auto mid = begin;
    std::advance(mid, cur_size / 2);
    
    auto ft_res = std::async(for_each_async<It, Func>, begin, mid, func);
    for_each_async(begin, mid, func);

}

int main()
{
    int vec_size = 10;
    std::vector<int> vec = create_vector(vec_size);

    //Проверка на работу с лямбдо функцией 
    for_each_async(vec.begin(), vec.end(), [](int i) {
        std::cout << i << "\t";
        });

    std::cout << std::endl;
    std::cout << "Output of even numbers in a vector: " << std::endl;
    //Проверка на работу с функцией
    for_each_async(vec.begin(), vec.end(), print_even_number);

}

