#include <iostream>

/*
  Basic `for` loop demo:
  Create Fibonacci sequence, with formulation as follows:
  $$ f(i) = f(i-1) + f(i+1) $$
*/

template<class T>
T get(std::istream& is){
  T result;
  is >> result;
  return result;
}
// get<int>(std::cin)

int main() {
    int a, b, tmp, len;
    a=1;
    b=1;
    
    std::cout << "Enter the sequent length: ";
    std::cin >> len;
    for (int i = 0; i < len; i++) {
        std::cout << "f(" << i << ") = " << a << ", golden ratio: "<< a/(double) b << std::endl;


        tmp=b;
        b=a+b;
        a=tmp;

    }

    return 0;
}