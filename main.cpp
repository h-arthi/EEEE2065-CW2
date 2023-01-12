#include <iostream>
#include <time.h>
#include "headers.h"

using namespace std;

int main()
{
    string answer;
    cout<<"\nWELCOME TO THE NUMBER GUESSER GAME!\n"<<endl;
    cout<<"\nTo play this game,guess a random number from the range given until you guess the secret number\n"<<endl;
    cout<<"\nYou can choose to play as a human or let the computer play for you\n"<<endl;
    cout<<"\n---------- LET'S START ----------\n"<<endl;

    srand(time(0));//seeding srand here to get random number every time

    guessNumber ng;

    while (ng.playGame()>0) {
        if (ng.playGame()==0) break;
        }


    return 0;
}
