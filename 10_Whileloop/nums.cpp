#include <iostream>

int main() {
    // Your code here
    int number;

    while (number < 0){
        std:: cout << "Enter a positive #: " << std::endl;
        std::cin >> number;
    }

    // The while-loop may not work as expected, 
    // when variable initialization.

    do {
        std:: cout << "<SEC-loop> Enter a positive #: ";
        std::cin >> number;
    }while (number < 0);

    std::cout << "This # is: " << number << std::endl;
    return 0;
}