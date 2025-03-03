#include <iostream>

std::string concatString(std::string str1, std::string str2);

int main() {
    std::string firstName;
    std::string lastName;

    while (firstName.empty() || lastName.empty()) {
        std::cout << "Input your first name: ";
        std::getline(std::cin, firstName);
        std::cout << "Input your last name: ";
        std::getline(std::cin, lastName);
    }

    std::string fullName = concatString(firstName, lastName);
    std::cout << "Your full name is: " << fullName << std::endl;
}

std::string concatString(std::string str1, std::string str2) {
    return str1 + " " + str2;
}