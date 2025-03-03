#include <iostream>

// `min` and `max` function is provided in the `std` scope.
int main() {
    // Your code here
    int x = 3;
    double y = 3.56;

    double zmax, zmin;

    zmax = std::max((double) x, y); 
    // This two must be of the same type.
    zmin = std::min((double) x ,y);

    std::cout<< "The minimum of " << x << " and " << y << " is: " << zmin <<std::endl;
    std::cout<< "The maximum of " << x << " and " << y << " is: " << zmax <<std::endl;
    return 0;
}