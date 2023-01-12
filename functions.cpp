#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <time.h>
#include <cmath>
#include "headers.h"

#define N 10000

using namespace std;

/**FUNCION TO PLAY THE GAME, TAKES NO INPUT RETURNS VALUE TO BREAK OUT OF WHILE LOOP **/
int guessNumber::playGame(){

    cout<<"Do you want to play as human or computer(human\\computer)?: ";
    cin>>player;
    if(player == "human"){
        humanGuess();
        return 0;
    }
    if(player == "computer"){
        index = 0;//index to store the number of guesses taken each game played
        populateArray();
        gameNumber();
        findMax();
        printHistogram();
        calcValues();
        return 0;
    }

    else{
        cout<<"Enter valid command"<<endl;
        return 1;
    }

}
/*****************************************************************************************/



/**************FUNCION TO GET THE NUMBER OF GAMES TO PLAY, TAKES NO INPUT RETURNS NO VALUE***************/
void guessNumber::gameNumber(){

    game_number = 0;//the number of games to play
    cout<<"How many games do you want to play:  ";
    cin>>game_number;
    int i=1;
    while(i<=game_number){
        computerGuess();
        cout<<"\n";
        i++;
    }
}
/*****************************************************************************************************/



/******FUNCTION TAKES N INPUT OR RETURNS ANY VALUE BUT GETS THE USER GUESS FROM USER******/
void guessNumber::humanGuess(){

   guesses = 0;//setting the initial number of guesses back to zero each new game played
   generateRandom();//generates secret random number

    while(user_guess!=random_number){
        guesses += 1;
        cout<<"Enter a number from "<< MIN << " to "<< MAX<<": ";
        cin>>user_guess;

        if ((user_guess>MAX)||(user_guess<MIN)){//checks if user entered a valid number
            cout<<"Please enter a valid number next time"<<endl;
        }
        //checks if guess is higher,lower or equal to random number
        else if(user_guess>random_number){
            goLower();
        }
        else if(user_guess<random_number){
            goHigher();
        }
        else if(user_guess == random_number){
            rightGuess();
        }

    }
}
/**************************************************************************************/



/******FUNCTION PLAYS THE GAME FOR COMPUTER, TAKES NO INPUT AND RETURNS NO VALUE******/
void guessNumber::computerGuess(){


    guesses = 0;//setting the initial number of guesses back to zero each new game played
    computer_guess = 0;//setting the initial computer guess to zero
    top_range = MAX;//setting the initial top range to MAX
    bottom_range = MIN;//setting the initial bottom range to MIN
    generateRandom();//generates a secret random number

    while(computer_guess!=random_number){

        float range = top_range + bottom_range;
        computer_guess = (int)range/2;//this is the midpoint value and the guess that computer gives
        guesses += 1;

        if(computer_guess>MAX){
            computer_guess = MAX;//if the computer guess is larger than the max value, set it to the max value
        }

        cout<<"Enter a number from "<< MIN << " to "<< MAX <<": ";

        //checks if guess is higher,lower or equal to random number
        if(computer_guess>random_number){
            cout<<"Computer guessed "<<computer_guess<<endl;
            goLower();
            top_range = computer_guess - 1;//setting the new top range to one lower than computer guess
        }

        if(computer_guess<random_number){

            cout<<"Computer guessed "<<computer_guess<<endl;
            goHigher();
            bottom_range = computer_guess + 1;//setting the new bottom range to one higher than the computer guess
        }

        if(computer_guess == random_number){
            cout<<"Computer guessed "<<computer_guess<<endl;
            rightGuess();
            freq[guesses] += 1;//adding the to frequency of a certain guess at that guess index
            guesses_max[index] = guesses;//adding to the array of guesses to obtain max guess later
            index++;//increasing the index to store the next number of guesses
            }
    }
}
/**************************************************************************************/



/******FUNCTION PRINTS OUT HISTOGRAM, TAKES NO INPUT AND RETURNS NO VALUE******/
void guessNumber::printHistogram(){
    int i,j;
    cout<<"\n----------Printing Out Histogram---------"<<endl;
    //looping to only print out until max guess
    for(i=1;i<=max_guess;i++){
        val[i] = i;
        cout<<val[i]<<"/"<<freq[i];
        for(j=0;j<freq[i];j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
/******************************************************************************************/



/**FUNCTION DETERMINES THE MAXIMUM NUMBER OF GUESSES, TAKES NO INPUT AND RETURNS NO VALUE**/
void guessNumber::findMax(){

  for(int i=0;i<game_number; i++) {
    //keeps checking if the previous number was larger than the current number
    if(guesses_max[0] < guesses_max[i]){
        guesses_max[0] = guesses_max[i];//this sets the guess at the first index to the max guess
    }
  }
    max_guess = guesses_max[0];
    cout<<"\n-----------------------------------------"<<endl;
    cout<<"Maximum Number of Guesses Taken: "<<max_guess<<endl;
}
/******************************************************************************************/



/********FUNCTION CALCULATES THE MEAN AND SIGMA, TAKES NO INPUT AND RETURNS NO VALUE*******/
void guessNumber::calcValues(){

    int i;
    float sum = 0.0;
    float sum_square = 0.0;
    float mean_square = 0.0;
    float var = 0.0;

    //getting the sum for each value in the array
    for(i=1;i<=max_guess;i++){
        sum += (val[i]*freq[i]);
    }
    mean = sum/game_number;//calculating the mean of the values

    for(i=1; i <= max_guess;i++) {
        sum_square += (freq[i]*pow(val[i],2));
    }
    mean_square = pow(mean,2);//getting the mean squared
    var = (sum_square/game_number)-mean_square;//calculating the variance
    sigma = sqrt(var);//obtaining the standard deviation
    cout<<"\n-------------Mean and Sigma--------------\n"<<endl;
    cout<<" Mean: "<<setprecision(4)<<mean;
    cout<<" | Sigma: "<<setprecision(4)<<sigma<<endl;
}
/******************************************************************************************/

