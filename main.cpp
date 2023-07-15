#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

const int MAX_GUESSES = 5;
const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;
const int DEPOSIT_AMOUNT = 10;

int generateRandomNumber() {
    srand(static_cast<unsigned int>(time(0)));
    return (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
}

void playGame() {
    int randomNumber = generateRandomNumber();
    int guess;
    int numGuesses = 0;
    bool isWinner = false;
    
    cout << "Guess the number between " << MIN_NUMBER << " and " << MAX_NUMBER << "!\n";
    
    while (numGuesses < MAX_GUESSES) {
        cout << "Enter your guess: ";
        cin >> guess;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            cout << "Invalid guess. Please enter a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
            continue;
        }
        
        numGuesses++;
        
        if (guess < randomNumber) {
            cout << "Too low!\n";
        } else if (guess > randomNumber) {
            cout << "Too high!\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << numGuesses << " tries!\n";
            isWinner = true;
            break;
        }
    }
    
    if (!isWinner) {
        cout << "Out of guesses! The number was " << randomNumber << ". Better luck next time!\n";
    }
}

int main() {
    string playerName;
    int numPlayers;
    int totalMoney = 0;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "How many players? ";
    cin >> numPlayers;
    
    if (cin.fail() || numPlayers <= 0) {
        cout << "Invalid input. Please enter a positive number of players.\n";
        return 1;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter the name of Player " << (i + 1) << ": ";
        getline(cin, playerName);
        
        cout << "Player " << playerName << ", please deposit $" << DEPOSIT_AMOUNT << " to play.\n";
        
        totalMoney += DEPOSIT_AMOUNT;
        
        playGame();
    }
    
    cout << "The game is over!\n";
    cout << "The total money collected is $" << totalMoney << ". Congratulations to the winners!\n";
    
    return 0;
}
