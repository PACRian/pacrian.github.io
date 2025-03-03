#include <iostream>

// A `switch-case` syntax looks like:
// switch (expression)
// {
// case constant expression:
//     /* code */
//     break;

// default:
//     break;
// }


int main() {
    int type;
    const double PI=3.1415926;
    double area;
    // Your code here

    std::cout << "Please enter the caculator type (1-Square, 2-Circle, 3-Rect): ";
    std::cin >> type;

    std::cout << "You choose type: " << type << std::endl;

    if(type == 1) {
        double side;
        std::cout << "The square side is:";
        std::cin >> side;
        area = side*side;
    }else if(type==2) {
        double radius;
        std::cout << "The radius is:";
        std::cin >> radius;
        area = PI*radius*radius;
    }else if(type==3) {
        double x, y;
        std::cout << "Enter two sides: (space for sep)";
        std::cin >> x >> y;
        area = x*y;
    }

    std::cout << "The area is: " << area <<std::endl;
    return 0;
}