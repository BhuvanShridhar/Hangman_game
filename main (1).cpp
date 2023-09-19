#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<string> words = {"programming", "hangman", "computer", "algorithm", "cplusplus", "openai"};
const int maxAttempts = 6;

string getRandomWord() {
    srand(time(0));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

int main() {
    string wordToGuess = getRandomWord();
    string guessedWord(wordToGuess.length(), '_');
    int remainingAttempts = maxAttempts;

    cout << "Welcome to Hangman!" << endl;

    while (remainingAttempts > 0) {
        cout << "Word to guess: " << guessedWord << endl;
        cout << "Remaining attempts: " << remainingAttempts << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        bool guessedCorrectly = false;
        for (int i = 0; i < wordToGuess.length(); ++i) {
            if (wordToGuess[i] == guess) {
                guessedWord[i] = guess;
                guessedCorrectly = true;
            }
        }

        if (!guessedCorrectly) {
            cout << "Incorrect guess. Try again." << endl;
            remainingAttempts--;
        }

        if (guessedWord == wordToGuess) {
            cout << "Congratulations! You've guessed the word: " << wordToGuess << endl;
            break;
        }
    }

    if (guessedWord != wordToGuess) {
        cout << "Sorry, you've run out of attempts. The word was: " << wordToGuess << endl;
    }

    return 0;
}
