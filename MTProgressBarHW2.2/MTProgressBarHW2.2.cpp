#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cmath>
#include <Windows.h>

std::mutex mtx;

//Метод устанавливает курсор в консоли на указанную позицию
void put_cur(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
        {
            static_cast<SHORT>(x), static_cast<SHORT>(y)
        });
}


void progress_bar(int x, int y, int w, double progress, char s_bar, bool flag, int& start_point) {

    int fill_w = static_cast<int> (w * progress);
    int empty_w = w - fill_w;

    put_cur(x + start_point, y);
    for (int i = start_point; i < fill_w; i++) {
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << s_bar;
    }
    if (flag) {
        for (int j = 0; j < empty_w - 1; j++) {
            std::cout << ".";
        }
        flag = false;
    }

    start_point = fill_w;
}

void print_progress_bar(int id, int n_thread, int bar_length) {

    int prog_x = 7;
    int prog_y = id;
    int b_width = bar_length;
    double bar = 0;


    auto start = std::chrono::steady_clock::now();
    double speed = 0.03;
    bool flag = true;
    int bar_start = 0;
    while (bar < 1) {

        mtx.lock();
        put_cur(1, prog_y);
        std::cout << " " << ((bar + speed >= 1) ? 1 * 100 : bar * 100) << "% ";
        progress_bar(prog_x, prog_y, b_width, bar, '#', flag, bar_start);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        put_cur(prog_x + b_width, prog_y);
        std::cout << " Поток: " << id;
        put_cur(prog_x + b_width + 11, prog_y);
        std::cout << " Идентификатор потока: " << std::this_thread::get_id() << std::endl;
        mtx.unlock();
        bar += speed;

    }
    std::lock_guard lg(mtx);
    auto end = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    double duration = std::round((delta.count() / 1000.0) * 100) / 100;
    std::cout << std::endl;

    //put_cur(0, id + n_thread);
    put_cur(bar_length + 47, id);
    std::cout << " Время работы потока №" << id << " -> " << duration << "s " << std::endl;

}

int main() {
    setlocale(LC_ALL, "Russian");
    int number_threads = 10;
    int bar_length = 20;
    std::vector<std::thread> vec_thread;

    for (int i = 0; i < number_threads; i++)
    {
        vec_thread.push_back(std::thread(print_progress_bar, i + 1, number_threads + 1, bar_length));
    }

    for (auto& v : vec_thread) {
        v.join();
    }
    put_cur(0, number_threads);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}