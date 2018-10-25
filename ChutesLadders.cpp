// Eli Gatchalian
// p3.cpp
// February 19, 2014

// Purpose: To play the game Chutes & Ladder with the user

// Input: Answer if user wants to play and names for two players

// Processing: If the user inputs that he wants to play, the game will jump
//  into a while loop where it first asks the name for two players. After
//  asking the names, the program goes into another while loop where it will
//  only break if either one of the player reaches square 100 first. The user
//  must press enter until either one reaches 100. Once a player has reached
//  100, the game will end and ask if they want to play again. The first
//  while loop will only break if the user inputs that he does not want to
//  play anymore.

// Output: The program will output a welcome message, an indication of how
//  the most recent turn played out, a win message, and a goodbye message.

// Examples: playerOne: 74, output: "Player 1 Square: 73. Player 2 Spin!"
//           playerTwo: 88, output: "Player 2 Square: 88. Player 1 Spin!"
//           playerOne: 80, output: "You landed on a ladder! Move 20 squares
//                                   forward. You landed on 100, you win! Game
//                                   over!!"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

const int WIN = 100;
const int LOW = 1;
const int HIGH = 6;
const char YES = 'y';

char welcomeMessage();
// Asks user if they want to play after briefly explaining the game

int chutesLadder(int spinLocation);
// Checks location of both players to see if they landed on a chutes or ladder
// IN: spinLocation

int spin();
// Gives a number for players to move from 1 to 6

int takeTurn(int location, int thisSpin);
// Takes turn for both players
// IN: location, thisSpin

int checker(int spinLocation, int chutesOrLadder, int thisSpin, int afterChutesOrLadderPosition);
// Checks location of both players after each turn
// IN: spinLocation, chutesOrLadder, thisSpin, afterChutesOrLadderPosition

void winMessage(int location, string name);
// Prints message indicating who won the game
// IN: location, name

void goodbyeMessage();
// Prints goodbye message to user

int main() {
    int spinLocation, thisSpin;
    int chutesOrLadder, afterChutesOrLadderPosition;
    int playerOneLocation, playerTwoLocation;
    char decision;
    string playerOne, playerTwo;
    
    decision = welcomeMessage();
    while (tolower(decision) == YES){
        cout << "Enter player one's name: ";
        cin >> playerOne;
        cout << endl << endl;
        cout << "Enter player two's name: ";
        cin >> playerTwo;
        cout << endl << endl;
        cin.ignore();
        cout << "Press enter to begin.";
        cin.ignore();

        while (playerOneLocation != WIN && playerTwoLocation != WIN){
            cout << playerOne << " press enter to spin.";
            cin.ignore();
            thisSpin = spin();
            spinLocation = takeTurn(playerOneLocation, thisSpin);
            chutesOrLadder = chutesLadder(spinLocation);
            afterChutesOrLadderPosition = spinLocation + chutesOrLadder;
            checker(spinLocation, chutesOrLadder, thisSpin, afterChutesOrLadderPosition);
            playerOneLocation = afterChutesOrLadderPosition;
            winMessage(playerOneLocation, playerOne);

            if (playerOneLocation != WIN){
                cout << playerTwo << " press enter to spin.";
                cin.ignore();
                thisSpin = spin();
                spinLocation = takeTurn(playerTwoLocation, thisSpin);
                chutesOrLadder = chutesLadder(spinLocation);
                afterChutesOrLadderPosition = spinLocation + chutesOrLadder;
                checker(spinLocation, chutesOrLadder, thisSpin, afterChutesOrLadderPosition);
                playerTwoLocation = afterChutesOrLadderPosition;
                winMessage(playerTwoLocation, playerTwo);
            }
            
        }
        cout << "If you would like to play again, enter 'y': ";
        cin >> decision;
    }
    goodbyeMessage();
    return 0;
}

char welcomeMessage(){
    char answer;
    
    cout << endl << endl << endl;
    cout << "Welcome to the game Chutes & Ladders brought to you by Fly By Night Games!" << endl;
    cout << "You will be racing with a computer to see who reaches square 100 first!" << endl;
    cout << endl << endl << endl;
    cout << "Would you like to play? (y/n) ";
    cin >> answer;
    cout << endl << endl << endl;
    return answer;
}

int chutesLadder(int spinLocation){
    switch(spinLocation){
        case 1: return 37;
        case 4: return 10;
        case 9: return 12;
        case 23: return 21;
        case 28: return 56;
        case 36: return 8;
        case 51: return 15;
        case 71: return 19;
        case 80: return 20;
        case 98: return -20;
        case 95: return -20;
        case 93: return -20;
        case 87: return -63;
        case 64: return -4;
        case 62: return -43;
        case 56: return -3;
        case 49: return -38;
        case 48: return -22;
        case 16: return -10;
        default: return 0;
    }
}

int spin() {
    srand(time(0));
    return (LOW + rand() % HIGH);
}

int takeTurn(int location, int thisSpin) {
    if (location + thisSpin <= WIN){
        return location + thisSpin;
        
    }else
        return location;
}

int checker(int spinLocation, int chutesOrLadder, int thisSpin, int afterChutesOrLadderPosition) {
    cout << "You spun a " << thisSpin << ". You are on square " << spinLocation << "." << endl;
    if (chutesOrLadder < 0){
        cout << "You landed on a chute! Please move back " << abs(chutesOrLadder)
            << " squares." << endl;
        cout << "You are now on square " << afterChutesOrLadderPosition << "." << endl;
    }else if (chutesOrLadder > 0){
        cout << "You landed on a ladder! Please move forward "
		 << abs(chutesOrLadder) << " squares." << endl;
        cout << "You are now on square " << afterChutesOrLadderPosition << "." << endl;
    }
    cout << endl << endl;
    return 0;
}

void winMessage(int location, string name) {
    if (location == WIN){
        cout << "Congratulations " << name << "!! You win!" << endl;
        cout << endl << endl << endl;
    }
}

void goodbyeMessage() {
    cout << endl << endl << endl;
    cout << "Thanks for playing!" << endl;
    cout << endl << endl << endl;
}
