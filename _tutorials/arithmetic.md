---
layout: post
title: "Arithmetic operations in C++"
date: 2025-03-01
categories: ["C++ tutorials"]
tags: ["C++", "arithmtic", "data types"]
excerpt: "Basic operations like `min` and `max` functions"
---

# Arithmetic



## Brief

The `cmath` library in C++ provides a variety of mathematical functions that are useful for performing arithmetic operations. Here are some common functions and related examples.



## Min or Max

`std::max` and `std::min`, these functions are used to find the maximum and minimum values between two numbers.Below is a simple [example]().

```c++
#include <iostream>

int main() {
    int x = 3;
    double y = 3.56;

    double zmax = std::max((double)x, y);
    double zmin = std::min((double)x, y);

    std::cout << "The minimum of " << x << " and " << y << " is: " << zmin << std::endl;
    std::cout << "The maximum of " << x << " and " << y << " is: " << zmax << std::endl;
    return 0;
}
```



## Square function: `sqrt` 

This function computes the square root of a number (`float` type). It is used in both [sqrt.cpp](vscode-file://vscode-app/d:/Programs/VScode/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html) and [calcTriangle.cpp](vscode-file://vscode-app/d:/Programs/VScode/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html) to calculate the square root of a given number. 

```c++
#include <iostream>
#include <cmath> // Required for sqrt

int main() {
    double number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    double result = sqrt(number);
    std::cout << "The square root of " << number << " is " << result << std::endl;
    return 0;
}
```



## Power function: `pow`

This function raises a number to the power of another number. It is used in [calcTriangle.cpp](vscode-file://vscode-app/d:/Programs/VScode/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html) to calculate the hypotenuse of a right-angled triangle using the Pythagorean theorem.

```c++
#include <iostream>
#include <cmath> // Required for pow and sqrt

int main() {
    double a, b;
    std::cout << "Please enter triangle side A and B (90°): ";
    std::cin >> a >> b;

    double c = sqrt(pow(a, 2) + pow(b, 2));
    std::cout << "Side C: " << c << std::endl;
    return 0;
}
```

