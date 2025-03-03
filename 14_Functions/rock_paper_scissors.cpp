#include <iostream>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player);

int main() {
    char user;
    srand(time(NULL));

    std::cout << "Match begin!" << std::endl;
    user = getUserChoice();
    chooseWinner(user);
    std::cout << "Match ended!" << std::endl;


    return 0;
}

char getUserChoice() {
    char choice;

    do {
        std::cout << "Please input yor choice (1-scissor; 2-rock; 3-paper): ";
        std::cin >> choice;
        choice = choice - '0';
    } while (choice != 3 && choice != 1 && choice !=2);

    return choice;
    
}

char getComputerChoice() {
    char choice = (rand() % 3) + 1;
    return choice;
}

void showChoice(char choice) {
    switch (choice)
    {
    case 1: std::cout << "Choose scissor" << std::endl;
        break;
    case 2: std::cout << "Choose rock" << std::endl;
        break;
    case 3: std::cout << "Choose paper" << std::endl;
        break;
    
    default:
        std::cout << "Invalid choice." << std::endl;
    }
}

void chooseWinner(char player) {
    player = (int) player;
    char computer = getComputerChoice();

    std::cout << "Human: ";
    showChoice(player);
    std::cout << "Computer: ";
    showChoice(computer);

    if (player == computer) {
        std::cout << "A tier" << std::endl;
    }
    else if (player == 3 && computer == 1) {
        std::cout << "Computer wins." << std::endl;
    }
    else if (player == 1 && computer == 3) {
        std::cout << "Human wins." << std::endl;
    }
    else if (player > computer) {
        std::cout << "Human wins." << std::endl;
    }
    else {
        std::cout << "Computer wins." << std::endl;
    }
}