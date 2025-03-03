#include <iostream>

// Array is a base data structure that can hold multiple 
// values (same type) are accessed by an index number

int main() {
    // Initialize an array like below:
    std::string cars[] = {"Car1", "Car2", "Car3"};
    // We can modify the value by index
    cars[0] = "First car";

    // Or initialize the size firstly
    double fib_list[5];
    fib_list[0]=1;
    fib_list[1]=1;
    fib_list[2]=2;
    fib_list[3]=3;
    fib_list[4]=5;

    std::cout << "Car 0: " << cars[0] << std::endl;
    std::cout << "Car 1: " << cars[1] << std::endl;
    std::cout << "Car 2: " << cars[2] << std::endl;

    std::cout << "Fib array: " << fib_list[0] << ", " << fib_list[1] << " ..." << std::endl;

    return 0;
}