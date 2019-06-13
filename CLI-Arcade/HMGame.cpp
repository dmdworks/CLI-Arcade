//
//  HMGame.cpp
//  Hangman
//
//  Created by Dezel Davis on 4/22/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "HMGame.hpp"

//Checks the user's guess against their previous guesses
bool HMGame::LetterUsed(char guess){
    for(int i = 0; i < UsedLetters.size(); ++i){
        if(guess == UsedLetters[i]){
            return true;
        }
    }
    return false;
}

//Gets a word for a text file, returns success status of word
bool HMGame::SetWord(){
    srand(time(0));
    std::string InputWord = "";
    
    std::ifstream Words;
    Words.open("Words.txt", std::ios_base::in);
    if(!Words.is_open()){
        std::cout << "Error: Word file failed to open. Words.txt should be in same directory as app." << std::endl;
        return false;
    }
    int RandNum = (rand()%230)+1;
    int LineNum = 0;
    while(getline(Words, InputWord)){
        ++LineNum;
        
        if(LineNum == RandNum){
            HiddenWord = InputWord;
        }
    }
    Words.close();
    return true;
}

//If SetWord() successed, this sets the hangman game up for the set word
void HMGame::SetUp(){
    //Vector is initialized to size of english alphabet
    UsedLetters.reserve(26);
    
    //Dashes are used to represent unguessed letters
    for(int i = 0; i < HiddenWord.length(); ++i){
        HiddenWord[i] = tolower(HiddenWord[i]);
        ScreenWord += "_";
    }
    
    //Strings present the man and are stored in Man[] array
    std::string ManEmpty = " ____\n";
    ManEmpty += " |  |\n";
    ManEmpty += "    |\n";
    ManEmpty += "    |\n";
    ManEmpty += "    |\n";
    ManEmpty += "____|_\n";
    
    std::string ManHead = " ____\n";
    ManHead += " |  |\n";
    ManHead += " O  |\n";
    ManHead += "    |\n";
    ManHead += "    |\n";
    ManHead += "____|_\n";
    
    std::string ManTorso = " ____\n";
    ManTorso += " |  |\n";
    ManTorso += " O  |\n";
    ManTorso += " |  |\n";
    ManTorso += "    |\n";
    ManTorso += "____|_\n";
    
    std::string ManLArm = " ____\n";
    ManLArm += " |  |\n";
    ManLArm += " O  |\n";
    ManLArm += " |\\ |\n";
    ManLArm += "    |\n";
    ManLArm += "____|_\n";
    
    std::string ManRArm = " ____\n";
    ManRArm += " |  |\n";
    ManRArm += " O  |\n";
    ManRArm += "/|\\ |\n";
    ManRArm += "    |\n";
    ManRArm += "____|_\n";
    
    std::string ManLLeg = " ____\n";
    ManLLeg += " |  |\n";
    ManLLeg += " O  |\n";
    ManLLeg += "/|\\ |\n";
    ManLLeg += "  \\ |\n";
    ManLLeg += "____|_\n";
    
    std::string ManDead = " ____\n";
    ManDead += " |  |\n";
    ManDead += " O  |\n";
    ManDead += "/|\\ |\n";
    ManDead += "/ \\ | \n";
    ManDead += "____|_\n";
    
    Man[6] = ManEmpty;
    Man[5] = ManHead;
    Man[4] = ManTorso;
    Man[3] = ManLArm;
    Man[2] = ManRArm;
    Man[1] = ManLLeg;
    Man[0] = ManDead;
}

void HMGame::PrintIntro(){
    std::cout << "HANGMAN" << std::endl;
    std::cout << Man[6] << std::endl;
    for(int i = 0; i < HiddenWord.length(); ++i){
        std::cout << ScreenWord[i] << " ";
    }
    std::cout << std::endl;
}

//This handles the guessing part of the game
bool HMGame::MainLoop(){
    while(ScreenWord != HiddenWord){
        //Theses need to be reset every loop which is why they are declared here
        int GuessCount = 0;
        char Guess = ' ';
        bool Invalid = true;
        std::string UserInput = "";
        while(Invalid){
            std::cout << "Guess a letter (or the whole word) in the " << HiddenWord.length() << " letter hidden word: ";
            getline(std::cin, UserInput);
            std::stringstream Input(UserInput);
            if(UserInput == HiddenWord){
                std::cout << "Congrats, you have guessed the whole word!" << std::endl;
                return false;
            }else if(Input >> Guess){
                Invalid = false;
            }else{
                std::cout << "Please enter a single letter." << std::endl;
            }
            if(LetterUsed(Guess)){
                std::cout << "Letter has been used." << std::endl;
                Invalid = true;
            }
            UsedLetters.push_back(Guess);
        }
        
        for(int i = 0; i < HiddenWord.length(); ++i){
            if(HiddenWord[i] == Guess){
                ScreenWord[i] = HiddenWord[i];
                ++GuessCount;
            }
        }
        if(!(GuessCount >= 1)){
            --ManCount;
        }
        std::cout << Man[ManCount] << std::endl;
        for(int i = 0; i < HiddenWord.length(); ++i){
            std::cout << ScreenWord[i] << " ";
        }
        std::cout << std::endl;
        if(ManCount == 0){
            std::cout << "The man has died. The hidden word was " << HiddenWord << "." << std::endl;
            return false;
        }
    }
    std::cout << "Congrats, you have won." << std::endl;
    return false;
}

//This is for the main function to know the game is over
bool HMGame::PlayGame(){
    if(!SetWord()){
        return false;
    }else{
        SetUp();
    }
    
    PrintIntro();
    //MainLoop() also returns a bool
    return MainLoop();
}

bool HMGame::Reset(){
    ManCount = 6;
    UsedLetters.clear();
    ScreenWord.clear();
    
    return true;
}
