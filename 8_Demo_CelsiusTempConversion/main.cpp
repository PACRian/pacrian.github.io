#include <iostream>

int main() {
    char unit;
    int isvalid;
    double temp;

    std::cout << "What unit would you like to convert to(F/C): ";
    std::cin >> unit;

    isvalid=1;
    if(unit == 'F' || unit == 'f') {
        std::cout << "Enter  the tempreture in Celusis: ";
        std::cin >> temp;

        temp = 1.8*temp + 32;
    } else if(unit == 'C' || unit == 'c') {
        std::cout << "Enter  the tempreture in Fahrenheit: ";
        std::cin >> temp;
        temp -= 32;
        temp /= 1.8;
    } else {
        isvalid=0;
        std::cout << "Wrong unit input."<<std::endl;
    }

    isvalid && std::cout << "Temperature is: " << temp << unit << std::endl;
    return 0;
}