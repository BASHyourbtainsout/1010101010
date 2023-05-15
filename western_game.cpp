#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // seed random number generator with current time
    int ammo = 0; // start with 0 ammo
    int shield = 0; // no shield active
    int lives = 5; // start with 5 lives
    int reloads = 0; // count number of reloads
    int bazooka = 0; // no bazooka acquired yet
    bool game_over = false;
    
    while (!game_over) { // repeat until game ends
        cout << "Enter your choice (1=reload, 2=shield, 3=shoot): ";
        int choice;
        cin >> choice;
        cout << endl;
        
        // computer chooses randomly between shield and shoot
        int computer_choice = rand() % 2 + 2; // 2=shield, 3=shoot
        
        if (choice == 1) { // reload
            ammo++;
            reloads++;
            if (reloads >= 10) { // acquire bazooka after 10 reloads
                bazooka = 1;
                cout << "You acquired a bazooka!" << endl;
            }
        } else if (choice == 2) { // shield
            shield = 1;
            cout << "You activated your shield!" << endl;
        } else if (choice == 3) { // shoot
            if (shield) { // shield blocks a shot
                shield = 0; // deactivate shield
                cout << "You used your shield to block the computer's shot!" << endl;
            } else if (ammo > 0) { // shoot and decrease ammo
                ammo--;
                cout << "You shot the computer!" << endl;
                if (bazooka) { // bazooka wins the game
                    cout << "You destroyed the computer with your bazooka! You win!" << endl;
                    game_over = true;
                }
            } else { // out of ammo
                cout << "You ran out of ammo!" << endl;
            }
        } else { // invalid choice
            cout << "Invalid choice!" << endl;
        }
        
        // computer's turn
        if (!game_over) { // skip if game already ended
            if (computer_choice == 2) { // computer activates shield
                cout << "The computer activates its shield!" << endl;
            } else if (ammo > 0) { // computer shoots if it has ammo
                ammo--;
                cout << "The computer shoots at you!" << endl;
                if (shield) { // your shield blocks a shot
                    shield = 0; // deactivate shield
                    cout << "Your shield blocked the computer's shot!" << endl;
                } else { // deduct one life if no shield
                    lives--;
                    cout << "You got hit! You have " << lives << " lives left." << endl;
                    if (lives <= 0) { // game over if out of lives
                        cout << "You ran out of lives! Game over!" << endl;
                        game_over = true;
                    }
                }
            } else { // computer out of ammo
                cout << "The computer ran out of ammo!" << endl;
            }
        }
    }
    
    return 0;
}
