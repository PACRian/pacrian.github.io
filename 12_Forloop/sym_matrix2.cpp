# include <iostream>
#include <cassert>

int main() {
    int rows, cols, pass_col_id;

    std::cout << "How many rows? ";
    std::cin >> rows;

    std::cout << "How many clumns? ";
    std::cin >> cols;

    std::cout << "Input the pass column index:";
    std::cin >> pass_col_id;

    assert(pass_col_id < cols && "pass_col_id should be less than cols");

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {

            if (j == pass_col_id) {
                std::cout << "& ";
                continue;
            }

            std::cout << "* ";
        }
        std::cout << '\n';
    }

    return 0;
}