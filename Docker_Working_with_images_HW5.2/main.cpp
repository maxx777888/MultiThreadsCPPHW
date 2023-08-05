#include <iostream>
#include <sstream>

int main()
{
    std::string phone_number = "1234567890";
    std::stringstream ss;
    ss << "+7(" << phone_number.substr(0, 3) << ") " << phone_number.substr(3, 3) << "-" << phone_number.substr(6, 2)<< "-" <<phone_number.substr(8) ;
    std::string formatted_phone_number = ss.str();

    std::cout << "Исходный номер телефона: " << phone_number << std::endl;
    std::cout << "Форматированный номер телефона: " << formatted_phone_number << std::endl;

    return 0;
}