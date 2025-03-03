#include <iostream>
#include <string>

void show_last();

int main() {
    std::string input;
    std::string top_in;

    std::cout << "Enter a line of text(Top)";
    // std::cin >> top_in;
    std::getline(std::cin >> std::ws, top_in);

    
    std::cout << "Enter a line of text: ";
    // std::cin >> input;
    std::getline(std::cin, input);
    // std::getline(std::cin >> std::ws, input); // reading stops unless a 'Enter' is provided
    // Use `std::cin >> std::ws` to flush out previous content (not needed, 'Enter' for example)

    std::cout << "Top input was: " << top_in << std::endl;
    std::cout << "You entered: " << input << std::endl;
    show_last();
    
    return 0;
}

void show_last() {
    std::clog << "Program ended" << std::endl;
}