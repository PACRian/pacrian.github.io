# Type conversion

## Brief

Type conversion in C++ refers to converting a value from one data type to another. There are two main types of type conversion:

+ **Implicit**: it is automatically performed. For example, converting an `int` to a `double`.
+ **Explicit (Type Casting)**: Manually performed by the programmer using casting operators. For example, converting an `int` to a `double` using `(double)`.



## Example analysis

The provided code demonstrates both implicit and explicit type conversion as follows:

```cpp
#include <iostream>
// To fulfill type conversion, two ways:
// Explicit one: (<conversion_type>) <value>
// Implicit one: automatic

int main() {

    char x = 100;

    int correct, question;
    correct = 8; question = 10;
    double scores = correct / question * 100;
    double true_scores = correct / (double) question * 100;

    std::cout << x << (char) 101 << 'c' << std::endl;
    std::cout << "Correction: <Wrong(without conversion)>" << scores << std::endl;
    std::cout << "Correction: <True(with conversion)>" << true_scores << std::endl;
    return 0;
}
```

The program outputs the following:

```bash
de

Correction: <Wrong(without conversion)>80

Correction: <True(with conversion)>80
```



- The first line prints the characters corresponding to ASCII values 100 and 101, followed by 'c'.
- The second line shows the result of the division without explicit conversion, which is incorrect due to **integer division**. Here, `correct` and `question` are both integers. The division `correct / question` is performed as integer division, resulting in an integer (floored). This result is then implicitly converted to `double` when assigned to `scores`.
- The third line shows the correct result with explicit conversion to `double`. Here, `question` is explicitly cast to `double` before the division (`(double) question`). This ensures that the division is performed as floating-point division, resulting in a more accurate result.