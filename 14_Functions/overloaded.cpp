#include <iostream>

// Overloadded function can work at different parameter groups
void sum_two_vals();
int sum_two_vals(int val1, int val2);
std::string sum_two_vals(std::string a, std::string b);

int main() {

    sum_two_vals();
    std::cout << "sum_two_vals(1, 2) = " << sum_two_vals(1, 2) << std::endl;
    std::cout << "sum_two_vals(\"Hello\", \" world\") = " << sum_two_vals("Hello", " world") << std::endl;

    return 0;
}

void sum_two_vals() {
    std::cout << "Help: `sum_two_vals()` can sum two elements by their types." << std::endl;
}

int sum_two_vals(int val1, int val2) {
    return val1 + val2;
}

std::string sum_two_vals(std::string a, std::string b) {
    return a.append(b);
    // return a;
}

