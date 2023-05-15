#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int main() {
  srand(time(0)); // initialize random seed
  int minNumber = 1;
  int maxNumber = 1000;
  int numberToGuess = rand() % (maxNumber - minNumber + 1) + minNumber; // generate a random number between 1 and 1000
  int guess, numGuesses = 0;

  cout << "I'm thinking of a number between " << minNumber << " and " << maxNumber << ". Can you guess what it is?" << endl;

  while (guess != numberToGuess) {
    cout << "Enter your guess: ";
    cin >> guess;
    numGuesses++;

    if (guess < numberToGuess) {
      cout << "Too low. ";
    } else if (guess > numberToGuess) {
      cout << "Too high. ";
    }

    if (numGuesses == 1) {
      cout << "You're off to a good start." << endl;
    } else if (numGuesses == 5) {
      cout << "You've made five guesses already. You might want to try a different strategy." << endl;
    } else if (numGuesses == 10) {
      cout << "You've made ten guesses already. Maybe you should take a break and come back later." << endl;
    } else if (numGuesses % 3 == 0) {
      cout << "You've made " << numGuesses << " guesses so far." << endl;
    }
  }

  cout << "Congratulations! You guessed the number in " << numGuesses << " guesses." << endl;

  if (numGuesses <= 5) {
    cout << "You're a natural at this!" << endl;
  } else if (numGuesses <= 10) {
    cout << "Not bad. You're getting the hang of it." << endl;
  } else if (numGuesses <= 20) {
    cout << "You could use a bit more practice, but you're on the right track." << endl;
  } else {
    cout << "Looks like you need to brush up on your guessing skills." << endl;
  }

  return 0;
}
