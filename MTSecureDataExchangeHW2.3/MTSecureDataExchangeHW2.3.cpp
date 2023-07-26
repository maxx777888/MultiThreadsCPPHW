#include <iostream>
#include <mutex>



class Data {
public:
    int num1;
    int num2;
    std::mutex mtx;

    static void print_data(const Data& some_data) {
        std::cout << some_data.num1 << " " << some_data.num2 << std::endl;
    }
};

void swap_lock(Data& data1, Data& data2) {

    std::lock(data1.mtx, data2.mtx);

    std::lock_guard<std::mutex> lock1(data1.mtx, std::adopt_lock);
    int temp = data1.num1;
    data1.num1 = data2.num1;
    data2.num1 = temp;

    std::lock_guard<std::mutex> lock2(data2.mtx, std::adopt_lock);
    temp = data2.num2;
    data2.num2 = data1.num2;
    data1.num2 = temp;
}
void swap_unique_lock(Data& data1, Data& data2) {

    std::unique_lock<std::mutex> lock1(data1.mtx, std::defer_lock);
    int temp = data1.num1;
    data1.num1 = data2.num1;
    data2.num1 = temp;


    std::unique_lock<std::mutex> lock2(data2.mtx, std::defer_lock);
    temp = data2.num2;
    data2.num2 = data1.num2;
    data1.num2 = temp;

    std::lock(lock1, lock2);
}

void swap_scoped_lock(Data& data1, Data& data2) {
    std::scoped_lock(data1.mtx, data2.mtx);

    int temp = data1.num1;
    data1.num1 = data2.num1;
    data2.num1 = temp;

    temp = data2.num2;
    data2.num2 = data1.num2;
    data1.num2 = temp;
}


int main() {

    Data data1(20, 10), data2(50, 40);
    std::cout << "=========== Starting data ===============" << std::endl;
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);
    std::cout << "=========================================" << std::endl;

    std::cout << "Swapping using lock() - >" << std::endl;
    swap_lock(data1, data2);
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);
    std::cout << "=========================================" << std::endl;

    std::cout << "Swapping using unique_lock() - >" << std::endl;
    swap_unique_lock(data1, data2);
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);
    std::cout << "=========================================" << std::endl;

    std::cout << "Swapping using scoped_lock() - >" << std::endl;
    swap_scoped_lock(data1, data2);
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);

    return 0;
}
