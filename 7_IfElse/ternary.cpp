#include <iostream>

int main() {
    // ternary operator ?: = replacement to an if/else statement
    // Syntax: condition ? exp1: exp2;
    // equal to `exp1` if `condition` is true

    int num;
    std::string msg;

    std::cout << "Enter a positive integal: ";
    std::cin >> num;
    
    num < 0 && std::cout << "The input is not positive.\n";
    if (num<0) {return 1;}  //negative
    // num < 0 && std::cout << "The input is not positive.\n" && (return 1, true);
    // condition ? op1: op2; ternary manner
    // condition && op;      short-circuit manner

    // num > 0 ? std::cout << std::endl : std::cout << "The input is not positive.";

    msg = num % 2 ? " is odd.":" is eval.";

    std::cout << "The number " << num << msg <<std::endl;
    return 0;
}