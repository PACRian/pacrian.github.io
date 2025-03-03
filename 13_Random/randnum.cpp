#include <iostream>
#include <cstdlib>

// pseudeo-random
// Ref links below:
// 1. [rand](https://cplusplus.com/reference/cstdlib/rand/)
// 2. [srand](https://cplusplus.com/reference/cstdlib/srand/)

int main() {
    // Seed the random number generator
    std::srand(time(NULL));

    // To get a pseudo-random integral number, use `rand()` function
    std::cout << "The maximum rand number RAND_MAX = " << RAND_MAX;


    // Generate random number multiple times
    for (int i=0; i<10; i++) {
        std::cout << "[Info]" << "<" << i << ">" << " Random number (0~100): " << std::rand()%100 << std::endl; 
    }

    return 0;
}