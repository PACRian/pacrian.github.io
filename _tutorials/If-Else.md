---
layout: post
title: "If-else in C++"
date: 2025-03-04
categories: ["C++ tutorials"]
tags: ["C++", "if-else", "conditional statements"]
excerpt: "'If-else' —— Conditional statements"
---

# If-Else





## Example 

The [ternary.cpp]() file contains a simple C++ program that demonstrates the use of the ternary operator and short-circuit evaluation. Below are several points:

1. **Short-Circuit Evaluation**:
   - The program uses a short-circuit evaluation with the `&&` operator to print a message if the input is negative: `num < 0 && std::cout << "The input is not positive.\n"`
   - An `if` statement is used to return early if the input is negative: `if (num < 0) { return 1; }`.
2. **Ternary Operator**:
   - The ternary operator is used to determine if the number is odd or even and set the `msg` variable accordingly: `msg = num % 2 ? " is odd." : " is even."`.

The program demonstrates conditional statements, and the use of the ternary operator in C++.

Besides, another demo about the conversion between the Celusis and Fahrenheit is presented [here]() for a small exercise about the `if-else` syntax.