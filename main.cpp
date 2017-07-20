// This is the console executable, that makes use of BullCow class this acts as the view in a mvc pattern
// 
//  main.cpp
//  Bulls and cows
//
//  Created by NzombieGaming on 5/17/17.
//  Copyright © 2017 NzombieGaming. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void Game();
FText GetGuess();
void guessW ();
bool PlayAgain();

FBullCowGame BCGame;//Instantiate a new game


// Introduce code/ Rules
void PrintIntro()
{
    int32 HiddenWord = BCGame.GetHiddenWordLength();
    
    std::cout <<"Welcome to bulls and cows \n";
    std::cout <<"       ^^           `/ /` \n";
    std::cout <<"  bull|oo|      cow |o o| \n";
    std::cout <<"      |~ |          | --| \n";
    std::cout <<"       vv            vvv  \n";
    std::cout <<"--------------------------\n";
    std::cout <<"Try to guess the isogram of length " <<HiddenWord <<  ".\n";
    
    return;
}

FText GetGuess() // TODO: FIX MAX TRIES Get Valid Guess
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    //Gets guess
    std::cout << "Try " <<CurrentTry <<": ";//Try indicator
    FText guess= "";
    //int32MaxTries = 2; TODO fix this damn thing
    
    
  

    return guess;
}

//Input from user


//Repeat users guess
void Game(){
    
    int32 MaxTries = BCGame.GetMaxTries();
    
    while (MaxTries > 0)
    {
        
        FText guess = GetGuess(); //Answer Validation
      
        EGuessStatus Status = BCGame.CheckGuess(guess);
        
        getline(std::cin, guess);
        MaxTries--;
        std::cout<<"Your guess was " << guess <<"\n";
        
        //Submit valid guess to game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
        
        //Print32bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << "\n";
        
        
    }
    
    std::cout <<MaxTries <<"\n";
   
}

bool PlayAgain()//Returns a bool to play again
{
    //bool Again = 0;
    std::cout<<"Do you want to play again (y/n)?\n ";
    FText Response = "";
    getline(std::cin,Response);
    
    return (Response[0] == 'y') || (Response[0] == 'Y') ;
    
}
int main()
{
    
    bool bPlayAgain = false;//bPlayAgain has a "b" for easy recognition of what it links to!
    
    //if (PlayAgain == true){
    do {

        PrintIntro();//Prints intro
        Game(); // returns guess
        GetGuess(); // Retrieves user's guess
        
        bPlayAgain = PlayAgain();//Sets bPlayAgain to PlayAgain to test answer
    }while (bPlayAgain == true);
    
    //}else{
        
    //}
 
    
    return 0;
}













