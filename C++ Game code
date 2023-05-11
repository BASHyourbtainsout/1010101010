#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(NULL)); //initialize random number generator
  int secretNum = rand() % 100 + 1; //generate random number between 1 and 100
  int guess;

  do {
    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    if (guess < secretNum) {
      cout << "Too low, try again." << endl;
    } else if (guess > secretNum) {
      cout << "Too high, try again." << endl;
    } else {
      cout << "Correct! You guessed the secret number." << endl;
      break; //exit loop when guess is correct
    }
  } while (true);

  return 0;
}
