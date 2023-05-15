#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAP_SIZE = 10; // constant for size of the map
const int NUM_ROOMS = 5; // constant for number of rooms in the dungeon
const char WALL = '#'; // character for walls of dungeon
const char ROOM = '.'; // character for rooms of dungeon
const char PLAYER = '@'; // character for the player
const char TREASURE = '$'; // character for the treasure

// function to print out the game map
void printMap(char map[][MAP_SIZE], int playerX, int playerY) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (i == playerY && j == playerX) {
        cout << PLAYER << " ";
      } else {
        cout << map[i][j] << " ";
      }
    }
    cout << endl;
  }
}

// function to generate the dungeon map
void generateDungeon(char map[][MAP_SIZE], int& treasureX, int& treasureY) {
  // initialize the map with walls
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map[i][j] = WALL;
    }
  }

  // randomly generate rooms in the dungeon
  srand(time(0));
  for (int room = 0; room < NUM_ROOMS; room++) {
    int roomSize = rand() % 4 + 3; // random size between 3 and 6
    int startX = rand() % (MAP_SIZE - roomSize - 1) + 1; // random starting X coordinate for room
    int startY = rand() % (MAP_SIZE - roomSize - 1) + 1; // random starting Y coordinate for room
    for (int i = 0; i < roomSize; i++) {
      for (int j = 0; j < roomSize; j++) {
        map[startY + i][startX + j] = ROOM;
      }
    }
  }

  // randomly generate the treasure location in the dungeon
  treasureX = rand() % MAP_SIZE;
  treasureY = rand() % MAP_SIZE;
  map[treasureY][treasureX] = TREASURE;
}

int main() {
  char dungeon[MAP_SIZE][MAP_SIZE];
  int playerX, playerY;
  int treasureX, treasureY;
  bool gameOver = false;

  // generate the dungeon and place the player
  generateDungeon(dungeon, treasureX, treasureY);
  playerX = rand() % MAP_SIZE;
  playerY = rand() % MAP_SIZE;
  dungeon[playerY][playerX] = PLAYER;

  cout << "Welcome to the dungeon crawler! Find the treasure ("
       << TREASURE << ") and get out alive!\n\n";

  while (!gameOver) {
    printMap(dungeon, playerX, playerY);

    // get the player's move
    char move;
    cout << "Enter your move (WASD): ";
    cin >> move;

    // update the player's position
    switch (move) {
      case 'W':
        if (playerY > 0 && dungeon[playerY - 1][playerX] != WALL) {
          playerY--;
        }
        break;
      case 'A':
        if (playerX > 0 && dungeon[playerY][playerX - 1] != WALL) {
          playerX--;
        }
        break;
      case 'S':
        if (playerY < MAP_SIZE - 1 && dungeon[playerY + 1][playerX] != WALL) {
          playerY++;
        }
        break;
      case 'D':
        if (playerX < MAP_SIZE - 1 && dungeon[playerY][playerX + 1] != WALL) {
          playerX++;
        }
        break;
      default:
        cout << "Invalid move. Try again." << endl;
        continue; // restart the loop to get a valid move
    }

    // check if the player found the treasure or hit a trap
    if (playerX == treasureX && playerY == treasureY) {
      cout << "You found the treasure! Congratulations, you win!" << endl;
      gameOver = true;
    } else if (dungeon[playerY][playerX] == WALL) {
      cout << "You hit a wall. Ouch!" << endl;
    }
  }

  return 0;
}
