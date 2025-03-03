#include <iostream>
#include <limits>
#include <string>

int main() {
    // `const` is used to assign a const
    const float PI=3.14;
    // which should not be changed.
    float r=3;
    std::string input;

    std::cout << "Please enter the radius of the circle (Default: 3): ";
    std::getline(std::cin, input);
    if (input.empty()) {
        r = 3;
    } else {
        r = std::stof(input);
    }

    std::cout<<"The area of the circle "<< "(Radius=" << r << ") is:"<<PI*r*r<<'\n';
    return 0;
}