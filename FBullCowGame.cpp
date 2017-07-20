//
//  FBullCowGame.cpp
//  Bulls and cows
//
//  Created by Nathan on 7/6/17.
//  Copyright © 2017 NzombieGaming. All rights reserved.
//

#include "FBullCowGame.hpp"
//using int32 = int;



FBullCowGame::FBullCowGame()//Set at run time Constructor
{
    Reset();
}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();} //ERROR implicit conversion loses integer precision

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    
    return;
};


bool FBullCowGame::IsGameWon() const
{
    
    return 0;
} 

//Recieves valid guess incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
    bool valid = false;//unused
    //Incriment turn number
    MyCurrentTry++;
    
    //setup a return variable
    FBullCowCount BullCowCount;
    
    //loop through all letters
    int32 MyHiddenWordLength = MyHiddenWord.length();//ERROR implicit conversion loses integer precision
    
    
    
    
    /*if (guess.length() == MyHiddenWord.length()) {
     valid = true;
     }else{
     //std::cout << "Please enter a valid guess";
     MyCurrentTry--;
     }*/
    
    for (int32 i = 0; i < MyHiddenWordLength; i++)
    {//compare each letter against the hidden word
        for (int32 j = 0; j< MyHiddenWord.length(); j++)
        {
            if (guess[i] == MyHiddenWord[j])//If they match then
            {
                if(i ==j ){
                    BullCowCount.Bulls++ ;// Incriment bull if matching place
                }else{
                    BullCowCount.Cows++;  //Incriment cow if matching letter
                }
            }
        }
    }
    
    return BullCowCount;
}


EGuessStatus FBullCowGame::CheckGuess(FString guess) const
{
    
    if (false)
    {
        return EGuessStatus::Not_Isogram;
    }//If guess is not isogram
    else if (false)
    {
        return EGuessStatus::Case_Sensitive;
    }
    else if (guess.length() != MyHiddenWord.length() )
    {
        return EGuessStatus::Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
    //return error
     //Check length
     //Check case sensitivity 
        //return error
     //else 
        //Return OK
     
    
    return EGuessStatus::OK;//TODO Make actual error
}



