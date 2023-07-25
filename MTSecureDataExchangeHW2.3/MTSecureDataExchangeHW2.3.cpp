#include <iostream>
#include <mutex>


class Data {
public:

    Data(int data_) { this->data = data_;}

    Data() { this->data = 0; }

    void swap_lock(Data& data_x, Data& data_y) 
    {
        mut.lock();
        int temp = data_x.data;
        data_x.data = data_y.data;
        data_y.data = temp;
        mut.unlock();
    }
    void swap_unique_lock(Data& data_x, Data& data_y)
    {
        std::unique_lock ul(mut);
        int temp = data_x.data;
        data_x.data= data_y.data;
        data_y.data = temp;
        ul.unlock();
    }

   void swap_scope_lock(Data& data_x, Data& data_y)
    {
        std::scoped_lock sl(mut);
        int temp = data_x.data;
        data_x.data = data_y.data;
        data_y.data = temp;
        
    }

    static void print_data(const Data& some_data) {
        std::cout << some_data.data << std::endl;
    }

private:
    int data;
    std::mutex mut;
};

int main() {
    
    Data data1(20), data2(55), obj;
    std::cout << "=========== Starting data ===============" << std::endl;
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);
    std::cout << "=========================================" << std::endl;
    std::cout << "Swapping two objects using lock() - >" << std::endl;
    obj.swap_lock(data1, data2);
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);

    std::cout << "Swapping two objects using unique_lock() - >" << std::endl;
    obj.swap_unique_lock(data1, data2);
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);

    std::cout << "Swapping two objects using scoped_lock() - >" << std::endl;
    obj.swap_unique_lock(data1, data2);
    std::cout << "Data1 - > ";
    Data::print_data(data1);
    std::cout << "Data2 - > ";
    Data::print_data(data2);
    
    return 0;
}
