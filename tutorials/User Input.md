# User Input

## Brief

Processing user input is a fundamental aspect of many C++ programs. Here’s a simple introduction to handling user input using the `std::cin` and `std::getline` functions.



## Basics about `std::cin` and `std::getline`

The `std::cin` object is used to read input from the standard input stream (usually the keyboard). It is typically used for reading single words or values. Check the [demo ](userinput.cpp) .

For reading entire lines of input, including spaces, `std::getline` is used. This function reads characters from the input stream until a newline character is encountered.



## Example 

The provided code in [proclines.cpp]() demonstrates how to read multiple lines of user input using `std::getline` in C++. The code reads two lines of input from the user, one for the "top" input and another for the general input.

When reading multiple lines of input, it’s important to handle any leftover newline characters in the input buffer. This can be done using `std::ws` to ignore leading whitespace.

```c++
#include <iostream>
#include <string>

void show_last();

int main() {
    std::string input;
    std::string top_in;

    std::cout << "Enter a line of text(Top)";
    std::getline(std::cin >> std::ws, top_in);

    
    std::cout << "Enter a line of text: ";
    std::getline(std::cin >> std::ws, input); // reading stops unless a 'Enter' is provided
    // Use `std::cin >> std::ws` to flush out previous content (not needed, 'Enter' for example)

    std::cout << "Top input was: " << top_in << std::endl;
    std::cout << "You entered: " << input << std::endl;
    
    return 0;
}
```

The key point in above code is `std::getline(std::cin >> std::ws, top_in)`, that reads a line of input into `top_in`, ensuring that any leading whitespace is ignored.