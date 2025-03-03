#include <iostream>

int num = 1; // This is a global variable

int main() {

    int num = 3; // This is a local variable

    std::cout << "Show `num`: " << num << std::endl;
    std::cout << "Show `::num` (local) : " << ::num << std::endl;
    std::cin.clear();
    fflush(stdin);

    return 0;
}