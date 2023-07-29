#include <iostream>
#include <vector>
#include <thread>
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

//Метод выводит содержимое вектора на консоль
void print_vec(const std::vector<int>& vector) {
    for (auto& v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
//Метод сортирует вектор с наименьшего числа к наибольшему
void sort_by_choice(std::vector<int>& v, std::promise<std::vector<int>> prom)
{    
    for (int i = 0; i < v.size() - 1; i++) 
    {
        int min_index = i;
        int min_num = v[i];
        bool min_found{ false };

        for (int j = i + 1; j < v.size(); j++) 
        {               
            if (min_num > v[j])
            {
                min_index = j;
                min_num = v[j];
                min_found = true;
            }
        }
        if (min_found) {
            std::swap(v[i], v[min_index]);
        }
    }
    prom.set_value(v);
}



int main()
{
    setlocale(LC_ALL, "Russian");

    int vec_size = 20;
    std::vector<int> vec = create_vector(vec_size);
    std::cout << "Start order: -> ";
    print_vec(vec);

    std::promise<std::vector<int>> prom;
    auto ft_res = prom.get_future();
    auto ft = std::async(sort_by_choice, std::ref(vec), std::move(prom));
    
    ft.get();

  
    std::cout << "New order: -> ";
    print_vec(vec);

}
