#include <iostream>

int main() {
    std::string names[] = {"Jim", "Anna", "Bob", "Lucy"};

    std::cout << "Below is a namelist:" <<std::endl;
    size_t index = 0;
    for (const std::string name : names) {
        std::cout << "Pos: " << index << ' ' << name << ", \n";
        ++ index;
    }

    std::cout << std::endl;
    return 0;
}

