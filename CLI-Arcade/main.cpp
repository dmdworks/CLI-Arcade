//
//  main.cpp
//  CLI-Arcade
//
//  Created by Dezel Davis on 4/19/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "C4Game.hpp"
#include "TTTGame.hpp"
#include "HMGame.hpp"
#include "GameClass.hpp"

int main(int argc, const char * argv[]) {
    using namespace std;
    string UserInput = "";
    char PlayAgain = 'n';
    bool Invalid = true;
    int GameChoice = 0;
    bool GameRunning = true;
    Game* CurrentGame = nullptr;
    
while(Invalid){
    cout << "COMMANDLINE GAMES" << endl;
    cout << "What game would you like to play?" << endl;
    cout << "1. Tic-Tac-Toe (1 or 2 player)" << endl;
    cout << "2. Connect 4 (2 player)" << endl;
    cout << "3. Hangman (1 player)" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter the game number: ";
    getline(cin, UserInput);
    stringstream check(UserInput);
    cout << endl;
    
    if(check >> GameChoice){
    switch(GameChoice){
        case 1:
            Invalid = false;
            CurrentGame = new (nothrow) TTTGame; //I know this old-fashion but I wanted to keep lib use minimal for this
            if(!CurrentGame){
                cout << "Error: Memory allocation for game failed." << endl;
                return 1;
            }
            break;
        case 2:
            Invalid = false;
            CurrentGame = new (nothrow) C4Game;
            if(!CurrentGame){
                cout << "Error: Memory allocation for game failed." << endl;
                return 1;
            }
            break;
        case 3:
            Invalid = false;
            CurrentGame = new (nothrow) HMGame;
            if(!CurrentGame){
                cout << "Error: Memory allocation for game failed." << endl;
                return 1;
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid Option. Please choose a number between 1-3." << endl;
            Invalid = true;
            break;
    }
    }else{
        cout << "Please enter a number." << endl;
        Invalid = true;
    }
}
    
    do{
        GameRunning = CurrentGame->PlayGame();
        cout << "Play again? Y/N?" << endl;
        cout << "Enter Choice: ";
        UserInput.clear();
        getline(cin, UserInput);
        stringstream check(UserInput);
        if(check >> PlayAgain){
            PlayAgain = tolower(PlayAgain);
            if(PlayAgain == 'y'){
                GameRunning = CurrentGame->Reset();
            }
        }
        cout << endl;
    }while(GameRunning);
    
    delete CurrentGame;
    
    cout << "Thanks for playing. Ending program." << endl;
    return 0;
}
