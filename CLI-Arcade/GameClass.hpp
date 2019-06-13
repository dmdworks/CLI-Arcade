//
//  GameClass.hpp
//  CLI-Arcade
//
//  Created by Dezel Davis on 4/22/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef GameClass_hpp
#define GameClass_hpp

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

class Game{
public:
    virtual bool PlayGame(){return false;}
    virtual bool Reset(){return false;}
};

#endif /* GameClass_hpp */
