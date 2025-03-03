#include <iostream>
#include <cmath>

int main() {
    double a, b, c;

    std::cout << "Please enter triangle side A and B (90°): ";
    // Example: input '3 4↓'
    std::cin >> a >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    std::cout << "Side C: " << c << std::endl;
    std::cout << "Total triangle sides: " << a << ',' << b << ',' << c <<std::endl;

    return 0;
}