//
//  montyHall.cpp
//  MontyHall
//
//  Created by Otto Sipe on 4/21/12.
//  EECS 203 Monty Hall Video
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int doors, choice, prizeDoor, openDoor = 0;
    char repick;
    
    cout << "How many Doors: ";
    cin >> doors;
    while (doors <= 2) {
        cout << "More doors needed, retry: ";
        cin >> doors;
    }
    
    srand ( time(NULL) );
    prizeDoor = rand() % doors + 1;
    
    cout << "What door do you want to choose? ";
    cin >> choice;
    
    while ( choice > doors || choice < 1) {
        cout << "Please retry: ";
        cin >> choice;
    } 
    
    cout << "Odds of winning: " << 1/(double)doors <<endl;
    
    do {
        srand ( time(NULL) );
        openDoor = rand() % doors + 1;
    } while (openDoor == prizeDoor || openDoor == choice);
    cout << "Monty Opens door " << openDoor << endl;
    
    
    cout << "Odds if you pick a new door: " << (1 - 1/(double)doors)/((double)doors-2) <<endl;

    cout << "Would you like to pick a new door? (y/n) ";    
    cin >> repick;
    
    if (repick == 'y') {
        cout << "What door do you want to choose? ";
        cin >> choice;
        while (choice == openDoor) {
            cout << "That door is open, retry: ";
            cin >> choice;
        }
    } 
    
    if (choice == prizeDoor) cout << "YOU WIN!" << endl;
    else cout << "You lose!" << endl;
    
    return 0;
}

