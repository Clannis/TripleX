#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty) {
    // Print welcome messages to the terminal
    cout << "\n\nYou are a secret agent breaking into a LEVEL[" << Difficulty << "] secure server room...\n";
    cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProdect to the terminal
    cout << "+ There are 3 numbers in the code.";
    cout << "\n+ The codes add-up to: " << CodeSum;
    cout << "\n+ The codes multiply to give: " << CodeProduct;
    cout << "\nEnter your guess: ";

    // Store player's guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        cout << "\nThat was the correct code. You hacked into server and extracted the file!";
        return true;
    } else {
        cout << "\nYou guessed wrong. The guards have been alerted! Try to get in again before they arrive.";
        return false;
    }
}

int main() {
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty) { // Loop the game until all levels are completed
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }
    
    cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";

    return 0;
}