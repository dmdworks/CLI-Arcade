//
//  HMGame.hpp
//  Hangman
//
//  Created by Dezel Davis on 4/22/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef HMGame_hpp
#define HMGame_hpp

#include "GameClass.hpp"

class HMGame: public Game{
private:
    std::string HiddenWord = "";
    //This is the word shown to the player
    std::string ScreenWord = "";
    //This stores the hanged man's state
    std::string Man[7] = {""};
    //This is used to index the Man[] array
    int ManCount = 6;
    //Stores guessed letters
    std::vector<char> UsedLetters;
    
    //Checks the user's guess against their previous guesses
    bool LetterUsed(char guess);
    //Gets a word for a text file, returns success status of word
    bool SetWord();
    //If SetWord() successed, this sets the hangman game up for the set word
    void SetUp();
    void PrintIntro();
    //This handles the guessing part of the game
    bool MainLoop();
    
public:
    //This is for the main function to know the game is over
    bool PlayGame() override;
    bool Reset() override;
};

#endif /* HMGame_hpp */
