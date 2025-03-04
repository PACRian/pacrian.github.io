---
layout: post
title: "Use `typedef` in C++"
date: 2025-03-04
categories: ["C++ tutorials"]
tags: ["C++", "Input/Output", "User Input"]
excerpt: "The `typedef` keyword —— alias for an existing data type."
---


<!-- 在header添加操作按钮 -->
<div class="code-header">
  <span class="lang-label">Python</span>
  <div class="code-actions">
    <button class="copy-btn" title="Copy code">⎘</button>
    <button class="expand-all" title="Expand all">↕</button>
  </div>
</div>


## Brief 

The `typedef` keyword in C++ is used to create an alias for an existing data type. This can make code more readable and easier to manage, especially when dealing with complex data types. The syntax of `typedef` is as follows:

```c++
typedef existing_type new_alias;
```



## Example

For example, if you have a complex type you can create a simpler alias for it using `typedef`:

```c++
typedef std::vector<std::pair<std::string, int>> pairs_t;
```

This allows you to use [pairs_t](vscode-file://vscode-app/d:/Programs/VScode/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html) instead of the longer type name throughout your code. See the [demo](~/cworkshop/cpphello/3_Typedef/typedef_demo.cpp) to check for checking more info about how to use `typedef`.

```c++
#include <iostream>
#include <vector>

// Creating an alias for a vector of pairs using typedef
typedef std::vector<std::pair<std::string, int>> pairs_t;
typedef std::string text_t;
// equivalent to below:
using text_t = std::string;

int main() {
    // Using the alias pairs_t

    // Using the alias text_t
    text_t fmsg = "First key: ";
    text_t emsg = ", First value: ";

    std::cout << fmsg << pairs[1].first << emsg << pairs[1].second << '\n';
    std::cout << pairs[0].first << ", " << pairs[0].second << '\n';

    return 0;
}
```

