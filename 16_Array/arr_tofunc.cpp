#include <iostream>
#include <tuple>

void showPrice(double prices[], int size);
double getTotalPrice(double prices[], int size);
std::tuple<int, double> getMaxPrice(double prizes[], int size);

int main() {
    double prizes[] = {11.92, 5.37, 8.94, 19.84};
    int size = sizeof(prizes) / sizeof(prizes[0]);

    std::cout << "The prizes list: ";
    showPrice(prizes, size);
    std::cout << "The total prize is: " << getTotalPrice(prizes, size) << std::endl;
    std::cout << "The maximum prize is:" << std::get<1>(getMaxPrice(prizes, size));
    std::cout << " at position: " << std::get<0>(getMaxPrice(prizes, size)) << std::endl;
    
    return 0;
}

void showPrice(double prices[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << prices[i] << ", ";
    }
    std::cout << std::endl;
}
double getTotalPrice(double prices[], int size) {
    double total = 0;
    for (int i=0; i<size; i++) {
        total += prices[i];
    }
    return total;
}

std::tuple<int, double> getMaxPrice(double prizes[], int size) {
    int maxInd = 0;
    double maxP = 0;
    for (int i=0; i<size; i++) {
        if (prizes[i] > maxP) {
            maxP = prizes[i];
            maxInd = i;
        }
    }
    return std::make_tuple(maxInd, maxP);
}