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

void progress_bar(int x, int y, int w, double progress, char s_bar) {
    int fill_w = static_cast<int> (w * progress);
    int empty_w = w - fill_w;
    put_cur(x, y);
    for (int i = 0; i < fill_w; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << s_bar;
    }

    for (int i = 0; i < empty_w; i++)
        std::cout << " ";
}

void print_progress_bar(int id, int n_thread, int bar_length) {
    int prog_x = 7;
    int prog_y = id;
    int b_width = bar_length;
    double bar = 0;


    auto start = std::chrono::steady_clock::now();
    double speed = 0.03;
    while (bar < 1) {
        std::unique_lock ul(mtx);
        put_cur(1, prog_y);
        std::cout << " " << ((bar + speed >= 1) ? 1 * 100 : bar * 100) << "% ";
        progress_bar(prog_x, prog_y, b_width, bar, '#');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        std::cout << " Поток: " << id << " Идентификатор потока: " << std::this_thread::get_id() << std::endl;
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