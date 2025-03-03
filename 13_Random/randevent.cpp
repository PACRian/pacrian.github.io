#include <iostream>
#include <ctime>

int main() {

    srand(time(0));
    int rand_num = rand() % 5 + 1; // 1, 2, ..., 5

    std::cout << "You win a ";
    switch (rand_num)
    {
    case 1: std::cout << "Sticker !";
        break;
    case 2: std::cout << "concert tickets !";
        break;
    case 3: std::cout << "free lunch !";
        break;
    case 4: std::cout << "none (sorry) !";
        break;
    case 5: std::cout << "gift card !";
        break;
    default:
        break;
    }

    std::cout << std::endl;
    return 0;
}