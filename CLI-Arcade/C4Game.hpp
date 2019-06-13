//
//  C4Game.hpp
//  Connect4
//
//  Created by Dezel Davis on 4/18/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef C4Game_hpp
#define C4Game_hpp

#include "GameClass.hpp"

class C4Game: public Game{
private:
    int C4Board[6][7] = {0};
    std::string PlayerChoice = "Invalid";
    int PlayerPiece = 5;
    bool Invaild = true;
    bool Gamewon = false;
    bool Playerturn = true;
    int CNum = 0;
    
    //These keep track of column fill (MUST REMAIN MUTABLE, DO NOT CONST)
    int FirstCFill = 5;
    int SecondCFill = 5;
    int ThirdCFill = 5;
    int FourthCFill = 5;
    int FithCFill = 5;
    int SixthCFill = 5;
    int SeventhCFill = 5;
    
    void DisplayPlayer();
    void DisplayBoard();
    void PlayerInput();
    bool CheckRow();
    bool CheckColum();
    bool CheckDiagonal();
    bool CheckOppDiagonal();
    bool BoardFilled();
    
public:
    //The game loop where all private functions are called
    bool PlayGame() override;
    bool Reset() override;
};

#endif /* C4Game_hpp */
