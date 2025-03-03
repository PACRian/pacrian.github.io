#include <iostream>

namespace arithm
{
    int num_students=20;
    int num_groups=6;
} // namespace arithm


int main() {
    using namespace arithm;
    
    int remainers = num_students % num_groups;

    std::cout << "Students remains:" << remainers << std::endl;
    return 0;
}