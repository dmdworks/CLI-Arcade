//
//  TTTGame.cpp
//  Tic-Tac-Toe
//
//  Created by Dezel Davis on 2/4/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "TTTGame.hpp"

//Provides main functions of game
bool TTTGame::PlayGame(){
    //Seed random number generator with time
    srand(time(0));
    
    //Introduces the game
    std::cout << "TIC-TAC-TOE" << std::endl;
    AIOption();
    Instructions();

    //Main Loop
    while(!EndGame){
        if(!Player1Turn && AI){
            PrintPlayer();
            do{
                AIBrain();
            }while(SpotTaken());
        }else{
            //Checks for proper input
            do{
                PrintPlayer();
                std::cout << "Choose your spot number: ";
                getline(std::cin, UserInput);
            }while(CheckInput());
        }
        
    //Places the approiate mark
    PlaceMark();
    //Switch turns
    SwitchTurns();
    //Print the tic-tac-toe board
    PrintBoard();
    //Checks if X or O have a complete pattern
    WinCondition();
    //Checks for a tie
    TieCheck();
    
    //End of Main Loop
    }

//End of Play game fucntion
    return false;
}

//Instructions on how to play
void TTTGame::Instructions(){
    std::cout << "Choose the number for the corresponding spot you wish to take." << std::endl;
    std::cout << "1 " << "2 " << "3" << std::endl;
    std::cout << "4 " << "5 " << "6" << std::endl;
    std::cout << "7 " << "8 " << "9" << std::endl;
}

//Outputs the tic-tac toe board
void TTTGame::PrintBoard(){
    for(int row = 0; row <= 2; ++row){
        for(int column = 0; column <= 2; ++column){
            std::cout << tttboard[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

//Check if X or O have a complete pattern
void TTTGame::WinCondition(){
    if(tttboard[0][0] == 88 && tttboard[0][1] == 88 && tttboard[0][2] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[1][0] == 88 && tttboard[1][1] == 88 && tttboard[1][2] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[2][0] == 88 && tttboard[2][1] == 88 && tttboard[2][2] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][0] == 88 && tttboard[1][0] == 88 && tttboard[2][0] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][1] == 88 && tttboard[1][1] == 88 && tttboard[2][1] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][2] == 88 && tttboard[1][2] == 88 && tttboard[2][2] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][0] == 88 && tttboard[1][1] == 88 && tttboard[2][2] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][2] == 88 && tttboard[1][1] == 88 && tttboard[2][0] == 88){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][0] == 79 && tttboard[0][1] == 79 && tttboard[0][2] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[1][0] == 79 && tttboard[1][1] == 79 && tttboard[1][2] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[2][0] == 79 && tttboard[2][1] == 79 && tttboard[2][2] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][0] == 79 && tttboard[1][0] == 79 && tttboard[2][0] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][1] == 79 && tttboard[1][1] == 79 && tttboard[2][1] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][2] == 79 && tttboard[1][2] == 79 && tttboard[2][2] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][0] == 79 && tttboard[1][1] == 79 && tttboard[2][2] == 79){
        WhoWon();
        EndGame = true;
    }else if(tttboard[0][2] == 79 && tttboard[1][1] == 79 && tttboard[2][0] == 79){
        WhoWon();
        EndGame = true;
    }else{
        EndGame = false;
    }
}

//Places the X or O
void TTTGame::PlaceMark(){
    switch(Spot){
        case 1:
            if(Player1Turn){
                tttboard[0][0] = 88;
            }else{
                tttboard[0][0] = 79;
            }
            break;
        case 2:
            if(Player1Turn){
                tttboard[0][1] = 88;
            }else{
                tttboard[0][1] = 79;
            }
            break;
        case 3:
            if(Player1Turn){
                tttboard[0][2] = 88;
            }else{
                tttboard[0][2] = 79;
            }
            break;
        case 4:
            if(Player1Turn){
                tttboard[1][0] = 88;
            }else{
                tttboard[1][0] = 79;
            }
            break;
        case 5:
            if(Player1Turn){
                tttboard[1][1] = 88;
            }else{
                tttboard[1][1] = 79;
            }
            break;
        case 6:
            if(Player1Turn){
                tttboard[1][2] = 88;
            }else{
                tttboard[1][2] = 79;
            }
            break;
        case 7:
            if(Player1Turn){
                tttboard[2][0] = 88;
            }else{
                tttboard[2][0] = 79;
            }
            break;
        case 8:
            if(Player1Turn){
                tttboard[2][1] = 88;
            }else{
                tttboard[2][1] = 79;
            }
            break;
        case 9:
            if(Player1Turn){
                tttboard[2][2] = 88;
            }else{
                tttboard[2][2] = 79;
            }
            break;
        default:
            std::cout << "Please enter an accepted number." << std::endl;
    }
    
}

//Switch Player turns
void TTTGame::SwitchTurns(){
    if(!Player1Turn){
        Player1Turn = true;
    }else{
        Player1Turn = false;
    }
}

//Prints whose turn it is
void TTTGame::PrintPlayer(){
    if(Player1Turn){
        std::cout << "Player 1, your turn." << std::endl;
    }else if(AI){
        std::cout << "AI's turn." << std::endl;
    }else{
        std::cout << "Player 2, your turn." << std::endl;
    }
}

//Prints congrats to winning player based on turn
void TTTGame::WhoWon(){
    if(!Player1Turn){
        std::cout << "Player 1, you have won." << std::endl;
    }else if(AI){
        std::cout << "The AI has won." << std::endl;
    }else{
        std::cout << "Player 2, you have won." << std::endl;
    }
}

//Guards against any improper user input
bool TTTGame::CheckInput(){
    std::stringstream check(UserInput);
    int num = 0;
    if(check >> num){
        Spot = num;
        if(Spot > 9 || Spot < 1){
            std::cout << "INVALID INPUT: Please enter a number between 1 & 9." << std::endl;
            return true;
        }else if(SpotTaken()){
            std::cout << "INVALID INPUT: Spot is taken." << std::endl;
            return true;
        }
        return false;
    }else{
        std::cout << "INVALID INPUT: Please enter a number." << std::endl;
        return true;
    }
}

//Makes sure no spots are stolen from players
bool TTTGame::SpotTaken(){
    switch(Spot){
        case 1:
            if(tttboard[0][0] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 2:
            if(tttboard[0][1] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 3:
            if(tttboard[0][2] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 4:
            if(tttboard[1][0] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 5:
            if(tttboard[1][1] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 6:
            if(tttboard[1][2] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 7:
            if(tttboard[2][0] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 8:
            if(tttboard[2][1] != 46){
                return true;
            }else{
                return false;
            }
            break;
        case 9:
            if(tttboard[2][2] != 46){
                return true;
            }else{
                return false;
            }
            break;
        default:
            return true;
    }
}

//Check if all spots are taken without a winner
void TTTGame::TieCheck(){
    int TieCounter = 0;
    for(int row = 0; row <= 2; ++row){
        for(int column = 0; column <= 2; ++column){
            if(tttboard[row][column] != 46){
                ++TieCounter;
            }
        }
    }
    if(TieCounter == 9 && EndGame == false){
        std::cout << "The game has ended in a tie." << std::endl;
        EndGame = true;
    }
}

//Asks player if they want to go against AI
void TTTGame::AIOption(){
    std::cout << "Would you like to play against the AI? (y or n)" << std::endl;
    std::string Response = "n";
    bool Invalid = true;
    do{
        getline(std::cin, Response);
        if(Response == "y"){
            std::cout << "You are now in single-player mode." << std::endl;
            AI = true;
            Invalid = false;
        }else if(Response == "n"){
            std::cout << "You are now in two-player mode." << std::endl;
            Invalid = false;
        }else{
            std::cout << "y or n?" << std::endl;
        }
    }while(Invalid);
}

//AI thought process
void TTTGame::AIBrain(){
    if(tttboard[0][0] == 88 && tttboard[0][1] == 88 && tttboard[0][2] == 46){
        Spot = 3;
    }else if(tttboard[1][0] == 88 && tttboard[1][1] == 88 && tttboard[1][2] == 46){
        Spot = 6;
    }else if(tttboard[2][0] == 88 && tttboard[2][1] == 88 && tttboard[2][2] == 46){
        Spot = 9;
    }else if(tttboard[0][0] == 88 && tttboard[1][0] == 88 && tttboard[2][0] == 46){
        Spot = 7;
    }else if(tttboard[0][1] == 88 && tttboard[1][1] == 88 && tttboard[2][1] == 46){
        Spot = 8;
    }else if(tttboard[0][2] == 88 && tttboard[1][2] == 88 && tttboard[2][2] == 46){
        Spot = 9;
    }else if(tttboard[0][0] == 88 && tttboard[1][1] == 88 && tttboard[2][2] == 46){
        Spot = 9;
    }else if(tttboard[0][2] == 88 && tttboard[1][1] == 88 && tttboard[2][0] == 46){
        Spot = 7;
    }else if(tttboard[0][0] == 88 && tttboard[0][1] == 46 && tttboard[0][2] == 88){
        Spot = 2;
    }else if(tttboard[1][0] == 88 && tttboard[1][1] == 46 && tttboard[1][2] == 88){
        Spot = 5;
    }else if(tttboard[2][0] == 88 && tttboard[2][1] == 46 && tttboard[2][2] == 88){
        Spot = 8;
    }else if(tttboard[0][0] == 88 && tttboard[1][0] == 46 && tttboard[2][0] == 88){
        Spot = 4;
    }else if(tttboard[0][1] == 88 && tttboard[1][1] == 46 && tttboard[2][1] == 88){
        Spot = 5;
    }else if(tttboard[0][2] == 88 && tttboard[1][2] == 46 && tttboard[2][2] == 88){
        Spot = 6;
    }else if(tttboard[0][0] == 88 && tttboard[1][1] == 46 && tttboard[2][2] == 88){
        Spot = 5;
    }else if(tttboard[0][2] == 88 && tttboard[1][1] == 46 && tttboard[2][0] == 88){
        Spot = 5;
    }else if(tttboard[0][0] == 46 && tttboard[0][1] == 88 && tttboard[0][2] == 88){
        Spot = 1;
    }else if(tttboard[1][0] == 46 && tttboard[1][1] == 88 && tttboard[1][2] == 88){
        Spot = 4;
    }else if(tttboard[2][0] == 46 && tttboard[2][1] == 88 && tttboard[2][2] == 88){
        Spot = 7;
    }else if(tttboard[0][0] == 46 && tttboard[1][0] == 88 && tttboard[2][0] == 88){
        Spot = 1;
    }else if(tttboard[0][1] == 46 && tttboard[1][1] == 88 && tttboard[2][1] == 88){
        Spot = 2;
    }else if(tttboard[0][2] == 46 && tttboard[1][2] == 88 && tttboard[2][2] == 88){
        Spot = 3;
    }else if(tttboard[0][0] == 46 && tttboard[1][1] == 88 && tttboard[2][2] == 88){
        Spot = 1;
    }else if(tttboard[0][2] == 46 && tttboard[1][1] == 88 && tttboard[2][0] == 88){
        Spot = 3;
    }else{
        Spot = (rand() % 8) + 1;
    }
    
}

bool TTTGame::Reset(){
    for(int row = 0; row <= 2; ++row){
        for(int column = 0; column <= 2; ++column){
            tttboard[row][column] = 46;
        }
    }
    Spot = 0;
    UserInput = "Invalid.";
    Player1Turn = true;
    EndGame = false;
    AI = false;
    
    return true;
}
