//
//  TTTGame.hpp
//  Tic-Tac-Toe
//
//  Created by Dezel Davis on 2/4/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef TTTGame_hpp
#define TTTGame_hpp

#include "GameClass.hpp"

class TTTGame: public Game{
private:
    char tttboard[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    int Spot = 0;
    std::string UserInput = "Invalid.";
    bool Player1Turn = true;
    bool EndGame = false;
    bool AI = false;
    
    //Prints instructions on how to play
    void Instructions();
    //Prints out tic-tac-toe
    void PrintBoard();
    //Checks whether winning conditions are meant & ends game if so
    void WinCondition();
    //Places X or O depending on player turn
    void PlaceMark();
    //Switches the player's turn
    void SwitchTurns();
    //Prints whose turn it is
    void PrintPlayer();
    //Prints who won
    void WhoWon();
    //Checks for proper user input
    bool CheckInput();
    //Checks if the spot is taken
    bool SpotTaken();
    //Checks if the board if full & ends games if so
    void TieCheck();
    //Sets the option for an AI opponent
    void AIOption();
    //Controls how the AI makes an choice
    void AIBrain();
    
public:
    //Plays tic-tac-toe game
    bool PlayGame() override;
    //Resets data members for new game
    bool Reset() override;
};


#endif /* TTTGame_hpp */
