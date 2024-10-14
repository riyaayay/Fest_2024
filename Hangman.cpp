#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string selectRandomWord() {
    vector<string> words = {"programming", "hangman", "computer", "challenge", "developer"};
    return words[rand() % words.size()]; // Select a random word from the list
}

void displayCurrentState(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // random number generation

    string wordToGuess = selectRandomWord();
    vector<char> guessedLetters;
    int maxAttempts = 6;
    int wrongGuesses = 0;

    cout << "Welcome to Hangman!" << endl;

    while (wrongGuesses < maxAttempts) {
        cout << "\nCurrent state: ";
        displayCurrentState(wordToGuess, guessedLetters);

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        // Check if the letter has already been guessed
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You've already guessed that letter. Try again." << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        // Check if the guessed letter is in the word
        if (wordToGuess.find(guess) != string::npos) {
            cout << "Good guess!" << endl;
        } else {
            wrongGuesses++;
            cout << "Wrong guess! You have " << maxAttempts - wrongGuesses << " attempts left." << endl;
        }

        // Check if the word has been fully guessed
        bool wordGuessed = true;
        for (char c : wordToGuess) {
            if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
                wordGuessed = false;
                break;
            }
        }

        if (wordGuessed) {
            cout << "Congratulations! You've guessed the word: " << wordToGuess << endl;
            break;
        }
    }

    if (wrongGuesses == maxAttempts) {
        cout << "You've run out of attempts! The word was: " << wordToGuess << endl;
    }

    return 0;
}
