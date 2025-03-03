#include <iostream>

double square(double len);

int main() {
    double length;

    std::cout << "Input the square length: ";
    std::cin >> length;

    std::cout << "Square area: " << square(length) << " (with length = " << length << " )" << std::endl;
    return 0;
}

double square(double len) {
    double r = len*len;
    return r;
}