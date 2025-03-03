# include <iostream>

int main() {
    int rows, cols;

    std::cout << "How many rows? ";
    std::cin >> rows;

    std::cout << "How many clumns? ";
    std::cin >> cols;

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }

    return 0;
}