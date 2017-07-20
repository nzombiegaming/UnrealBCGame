//
//  FBullCowGame.hpp
//  Bulls and cows
//
//  Created by Nathan on 7/6/17.
//  Copyright © 2017 NzombieGaming. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

//#include <stdio.h>

#endif /* FBullCowGame_hpp */
#include <string>


using int32 = int;
using FString = std::string;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
    
    
};
enum class EGuessStatus // to reuse names in enum make it a class to make it strongly typed enum
{
    OK,
    Not_Isogram,
    Length,
    Invalid_Character,
    Case_Sensitive,
    
};

class FBullCowGame {

public:
    FBullCowGame(); // Constructor
    int32 GetMaxTries() const;//int32 GetIsogramLength();//string GetGuess();//string GetAnswer();
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuess(std::string) const;
    void Reset();//TODO Make a more rich return value.
 

    FBullCowCount SubmitGuess(FString);
    
    
//PLease try and ignore this and focus above^^^^^
private:
    //Set in constructor
    int32 MyCurrentTry;
    int32 MyMaxTries ;//TODO make this universal so it only needs to be changes in one location.
    //bool IsIsogram();//(string) eventually
    FString MyHiddenWord;

};
