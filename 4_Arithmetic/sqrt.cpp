#include <iostream>
#include <cmath>

// Check below ref link for more about `cmath`:
// https://cplusplus.com/reference/cmath/fmax/

int main() {
    double number, result, rv;

    std::cout << "Enter a number: ";
    std::cin >> number;

    result = sqrt(number);
    rv = round(result);

    std::cout << "The square root of " << number << " is " 
    << result << "(Rounded as " << rv << ")" << std::endl;
    std::cout << "Round check: " << rv << "^2 = " << pow(rv, 2) << std::endl;

    printf ("fmax (100.0, 1.0) = %f\n", fmax(100.0,1.0));
    return 0;
}