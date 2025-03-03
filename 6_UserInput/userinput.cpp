#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;

    std::cout << "What is your age?" <<std::endl;
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}