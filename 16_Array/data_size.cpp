#include <iostream>

int main() {

    // A double object contains 8 bytes.
    double x = 3.56;
    std::cout << "sizeof(x) = " << sizeof(x) << " bytes\n";
    std::cout << "sizeof(double) = " << sizeof(double) << " bytes\n";

    // A string object contains a pointer, that takes 32 bytes
    std::string label = "format";
    std::string label2 = "long long int";
    std::cout << "sizeof(label1) = " << sizeof(label) << " bytes, label = " << label << std::endl;
    std::cout << "sizeof(label2) = " << sizeof(label2) << " bytes, label = " << label2 << std::endl;
    std::cout << "sizeof(std::string) = " << sizeof(std::string) << " bytes\n";

    // When applying `sizeof` to an array
    char grades[] = {'A', 'B', 'C', 'D', 'E'};
    std::cout << "sizeof(grades) = " << sizeof(grades) << " bytes\n";
    for (int i=0; i<sizeof(grades)/sizeof(grades[0]); i++) {
        std::cout << "sizeof(grades[" << i << "]) = " << sizeof(grades[i]) << " bytes, while grades[" << i << "] = " <<  grades[i] << std::endl;
    }
    
    std::cout << "Such that we can determine the array length: " << sizeof(grades)/sizeof(grades[0]) << std::endl;
    return 0;
}