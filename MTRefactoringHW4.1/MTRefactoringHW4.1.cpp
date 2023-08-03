#include <iostream>
#include <Windows.h>
#include "Line.h"
#include "Square.h"
#include "Qube.h"

int main()
{
    //Необходимые настройки для работы с русским языком
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Line l(1, 4, 2, 5);
    Qube q(1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
    l.print_shape();
    l.make_shift(2, 3);
    l.print_shape();

    q.print_shape();
    std::cout << "Площадь куба равна = " << q.getSquare() << std::endl;

}
