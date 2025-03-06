---
layout: post
title: "在 C++ 中使用类型转换"
date: 2025-03-04
categories: ["C++ 教程"]
tags: ["C++", "类型转换"]
image: /assets/img/type-conversion.png
excerpt: "你想尝试隐式还是显式类型转换？"
lang: zh
translations:
  - lang: en
    url: /tutorials/Type%20conversion/
  - lang: zh
    url: /tutorials/Type%20conversion_zh/
  
---

## 简介

C++ 中的类型转换是指将一个值从一种数据类型转换为另一种数据类型。主要有两种类型转换：

+ **隐式**：自动执行。例如，将 `int` 转换为 `double`。
+ **显式（类型转换）**：由程序员使用转换操作符手动执行。例如，使用 `(double)` 将 `int` 转换为 `double`。



## 示例分析

提供的代码演示了隐式和显式类型转换，如下所示：

```cpp
#include <iostream>
// 要实现类型转换，有两种方式：
// 显式：(<转换类型>) <值>
// 隐式：自动

int main() {

    char x = 100;

    int correct, question;
    correct = 8; question = 10;
    double scores = correct / question * 100;
    double true_scores = correct / (double) question * 100;

    std::cout << x << (char) 101 << 'c' << std::endl;
    std::cout << "Correction: <错误（无转换）>" << scores << std::endl;
    std::cout << "Correction: <正确（有转换）>" << true_scores << std::endl;
    return 0;
}
```

程序输出如下：

```bash
de

Correction: <错误（无转换）>80

Correction: <正确（有转换）>80
```



- 第一行打印对应 ASCII 值 100 和 101 的字符，后跟 'c'。
- 第二行显示没有显式转换的除法结果，由于**整数除法**，这是不正确的。这里，`correct` 和 `question` 都是整数。除法 `correct / question` 作为整数除法执行，结果是一个整数（向下取整）。这个结果在赋值给 `scores` 时被隐式转换为 `double`。
- 第三行显示了显式转换为 `double` 的正确结果。这里，`question` 在除法之前被显式转换为 `double`（`(double) question`）。这确保了除法作为浮点除法执行，结果更准确。
