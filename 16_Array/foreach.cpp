#include <iostream>

void showSyms(char sym_arr[], int size);
// foreach loop: loop that eases the taversal over an iterable object
// Syntax:
// for (<data_T> <var>: <array>) {
// // main code.
//}
int main() {
    int row_nums[] = {1, 2, 3, 4, 5};
    char syms[] = {'*', '.'};


    for (int num : row_nums) {
        for (int i=0; i<num; i++) {
            showSyms(syms, sizeof(syms)/sizeof(syms[0]));
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}

// If the array is not passed by its pointer, 
// register a `size`
void showSyms(char sym_arr[], int size) {
    
    for (int i=0; i<size; i++) {
        std::cout << sym_arr[i] << ' ';
    }
}