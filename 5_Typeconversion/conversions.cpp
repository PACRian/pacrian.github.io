#include <iostream>
// To fullfill type conversion, two ways:
// Explicit one: (<conversion_type>) <value>
// Implicit one: automatic

int main() {

    char x = 100;

    int correct, question;
    correct=8; question=10;
    double scores = correct/question * 100;
    double true_scores = correct/(double) question * 100;

    std::cout << x << (char) 101 << 'c' << std::endl;
    std::cout << "Correction: <Wrong(without conversion)>" << scores << std::endl;
    std::cout << "Correction: <True(with conversion)>" << true_scores << std::endl;
    return 0;
}