//
//  C4Game.cpp
//  Connect4
//
//  Created by Dezel Davis on 4/18/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "C4Game.hpp"
//Game loop
bool C4Game::PlayGame(){
    std::cout << "CONNECT 4" << std::endl;
    do{
        DisplayPlayer();
        DisplayBoard();
        PlayerInput();
        if(CheckRow()){
            Gamewon = true;
        }else if(CheckColum()){
            Gamewon = true;
        }else if(CheckDiagonal()){
            Gamewon = true;
        }else if(CheckOppDiagonal()){
            Gamewon = true;
        }else if(BoardFilled()){
            Gamewon = true;
            std::cout << "The game has ended in a tie." << std::endl;
            DisplayBoard();
            return false;
        }
    }while(!Gamewon);
    DisplayPlayer();
    DisplayBoard();
    return false;
}

//Shows whose turn it is, switches turns, and shows the game winner as well
void C4Game::DisplayPlayer(){
    if(!Gamewon){
        if(Playerturn){
            std::cout << "Player 1, your turn." << std::endl;
            PlayerPiece = 5;
            Playerturn = !Playerturn;
        }else{
            std::cout << "Player 2, your turn." << std::endl;
            PlayerPiece = 7;
            Playerturn = !Playerturn;
        }
    }else{
        if(!Playerturn){
            std::cout << "Player 1, you have won." << std::endl;
        }else{
            std::cout << "Player 2, you have won." << std::endl;
        }
    }
}

//Show the current state of the game board
void C4Game::DisplayBoard(){
    for(int s = 1; s <= 7; ++s){
        std::cout << s << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    for(int r = 0; r < 6; ++r){
        for(int c = 0; c < 7; ++c){
            std::cout << C4Board[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

//Places the piece and guards against inproper input
void C4Game::PlayerInput(){
    do{
        std::cout << "Choose the column number you want to go down: ";
        getline(std::cin,PlayerChoice);
        std::cout << std::endl;
        std::stringstream check(PlayerChoice);
        
        if(check >> CNum){
            switch(CNum){
                case 1:
                    if(FirstCFill != -1){
                        C4Board[FirstCFill][0] = PlayerPiece;
                        --FirstCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 1st column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                case 2:
                    if(SecondCFill != -1){
                        C4Board[SecondCFill][1] = PlayerPiece;
                        --SecondCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 2nd column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                case 3:
                    if(ThirdCFill != -1){
                        C4Board[ThirdCFill][2] = PlayerPiece;
                        --ThirdCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 3rd column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                case 4:
                    if(FourthCFill != -1){
                        C4Board[FourthCFill][3] = PlayerPiece;
                        --FourthCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 4th column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                case 5:
                    if(FithCFill != -1){
                        C4Board[FithCFill][4] = PlayerPiece;
                        --FithCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 5th column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                case 6:
                    if(SixthCFill != -1){
                        C4Board[SixthCFill][5] = PlayerPiece;
                        --SixthCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 6th column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                case 7:
                    if(SeventhCFill != -1){
                        C4Board[SeventhCFill][6] = PlayerPiece;
                        --SeventhCFill;
                        Invaild = false;
                    }else{
                        std::cout << "The 7th column is filled." << std::endl;
                        Invaild = true;
                    }
                    break;
                default:
                    std::cout << "Invailed number." << std::endl;
                    Invaild = true;
                    break;
            }
        }else{
            std::cout << "Please enter a number." << std::endl;
            Invaild = true;
        }
        
    }while(Invaild);
    
}

//Checks for four pieces going across
bool C4Game::CheckRow(){
    int PieceCount = 0;
    
    for(int r = 0; r < 6; ++r){
        for(int c = 0; c < 7; ++c){
            if(C4Board[r][c] == PlayerPiece){
                PieceCount += 1;
            }else{
                if(!(PieceCount >= 4)){
                    PieceCount = 0;
                }
            }
        }
        if(!(PieceCount >= 4)){
            PieceCount = 0;
        }
    }
    
    if(PieceCount >= 4){
        Gamewon = true;
    }
    
    return Gamewon;
}

//Checks for four pieces going down
bool C4Game::CheckColum(){
    int PieceCount = 0;
    int RCount = 0;
    
    while(RCount < 7){
        for(int r = 0; r < 6; ++r){
            if(C4Board[r][RCount] == PlayerPiece){
                PieceCount += 1;
            }else{
                if(!(PieceCount >= 4)){
                    PieceCount = 0;
                }
            }
        }
        if(!(PieceCount >= 4)){
            PieceCount = 0;
        }
        ++RCount;
    }
    
    if(PieceCount >= 4){
        Gamewon = true;
    }
    
    return Gamewon;
}

//Checks for four pieces going diagonal
/*The diagonal checks are long winded but it's the same process as the other checks repeated
 with some offseting in ording to make the coodinates diagonal
 */
bool C4Game::CheckDiagonal(){
    int Rpos = 0;
    int Cpos = 0;
    int Yoffset = 0;
    int Xoffset = 2;
    int Itcount = 0;
    int PieceCount = 0;
    
    while(!(Itcount >= 4)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        ++Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    --Xoffset;
    
    while(!(Itcount >= 5)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        ++Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    --Xoffset;
    
    while(!(Itcount >= 6)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        ++Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Yoffset;
    
    while(!(Itcount >= 6)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        ++Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Yoffset;
    
    while(!(Itcount >= 5)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        ++Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Yoffset;
    
    while(!(Itcount >= 4)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        ++Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    return false;
}

//Checks the opposite diagonals
bool C4Game::CheckOppDiagonal(){
    int Rpos = 4;
    int Cpos = 0;
    int Yoffset = 0;
    int Xoffset = 0;
    int Itcount = 0;
    int PieceCount = 0;
    
    while(!(Itcount >= 4)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        --Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 4;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Yoffset;
    
    while(!(Itcount >= 5)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        --Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 4;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Yoffset;
    
    while(!(Itcount >= 6)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        --Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 4;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Xoffset;
    
    while(!(Itcount >= 6)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        --Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 0;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Xoffset;
    
    while(!(Itcount >= 5)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        --Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 4;
        Cpos = 0;
        Itcount = 0;
    }
    
    ++Xoffset;
    
    while(!(Itcount >= 4)){
        if(C4Board[Rpos+Yoffset][Cpos+Xoffset] == PlayerPiece){
            PieceCount += 1;
        }else{
            if(PieceCount != 4){
                PieceCount = 0;
            }
        }
        --Rpos;
        ++Cpos;
        ++Itcount;
    }
    if(PieceCount >= 4){
        return true;
    }else{
        PieceCount = 0;
        Rpos = 4;
        Cpos = 0;
        Itcount = 0;
    }
    return false;
}

//Checks if the whole board is filled, thus unplayable
bool C4Game::BoardFilled(){
    int FillCounter = 0;
    
    for(int r = 0; r < 6; ++r){
        for(int c = 0; c < 7; ++c){
            if(C4Board[r][c] != 0){
                ++FillCounter;
            }
        }
    }
    
    if(FillCounter == 42){
        return true;
    }
    
    return false;
}

bool C4Game::Reset(){
    for(int r = 0; r < 6; ++r){
        for(int c = 0; c < 7; ++c){
            C4Board[r][c] = 0;
        }
    }
    PlayerChoice = "Invalid";
    PlayerPiece = 5;
    Invaild = true;
    Gamewon = false;
    Playerturn = true;
    CNum = 0;
    
    FirstCFill = 5;
    SecondCFill = 5;
    ThirdCFill = 5;
    FourthCFill = 5;
    FithCFill = 5;
    SixthCFill = 5;
    SeventhCFill = 5;
    
    return true;
}
