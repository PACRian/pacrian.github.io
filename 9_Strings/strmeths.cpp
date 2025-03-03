#include <iostream>

/*
 For more about `string`, check : https://cplusplus.com/reference/string/string/
*/

void show_str();

namespace str_op {
    std::string istr;
}

int main() {
    using namespace str_op;

    std::cout << "---------- String methods demo -------------\n";
    // std::string istr; 

    std::cout << "Input string: ";
    std::getline(std::cin, istr);

    std::cout << "Your string is: " << istr << std::endl;

    std::cout << "String length: " << istr.length() << std::endl;

    std::cout << "string.empty() is: " << istr.empty() << std::endl;

    std::cout << "string.append(\"_ext\") is: " << istr.append("_ext") << std::endl;

    std::cout << "string.insert(0, \"prefix_\") is: " << istr.insert(0, "prefix_") << std::endl;

    show_str();

    std::cout << "string.erase(0, 3) is: " << istr.erase(0, 3) << std::endl;

    show_str();

    std::cout << "The first character is (by invoking string.at(0)): " << istr.at(0) << std::endl;

    std::cout << "The second character is (by invoking string.at(1)): " << istr.at(1) << std::endl;

    std::cout << "The last character is (by invoking string.back()): " << istr.back() << std::endl;

    std::cout << "--------------------------------------------\n";
    return 0;
}

void show_str() {
    using namespace str_op;

    std::cout << "Your string is: " << istr << std::endl;
}