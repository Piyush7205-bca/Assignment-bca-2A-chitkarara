#include <iostream>
#include <cstdlib>
#include <ctime>

class GuessTheNumber {
private:
    int computerGeneratedNumber;
    int userGuessedNumber;

public:
    void generateRandomNumber() {
        // Generate a random number between 1 and 100
        srand(time(0));
        computerGeneratedNumber = rand() % 100 + 1;
    }

    void startGame() {
        int attempts = 0;
        while (true) {
            std::cout << "Guess the number: ";
            std::cin >> userGuessedNumber;
            attempts++;

            if (userGuessedNumber < computerGeneratedNumber) {
                std::cout << "Attempt: " << attempts << "\nMessage: Guessed number is smaller than computer generated number\n";
            } else if (userGuessedNumber > computerGeneratedNumber) {
                std::cout << "Attempt: " << attempts << "\nMessage: Guessed number is greater than computer generated number\n";
            } else {
                std::cout << "Attempt: " << attempts << "\nMessage: Congratulation you won the game in " << attempts << " attempts\n";
                break;
            }
        }
    }
};

int main() {
    GuessTheNumber game;
    game.generateRandomNumber();
    game.startGame();
    return 0;
}
