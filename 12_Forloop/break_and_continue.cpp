#include <iostream>

/*
  Basic `for` loop demo:
  Create Fibonacci sequence, with formulation as follows:
  $$ f(i) = f(i-1) + f(i+1) $$
*/

int main() {

    std::cout << "Display y=x^2, at even points.\n";
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            continue;
            // odd
        }

        std::cout << "f(" << i << ") = " << i*i << std::endl;
    }

    return 0;
}