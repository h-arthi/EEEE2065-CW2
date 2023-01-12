#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#define N 10000

using namespace std;

class guessNumber{

private:

    int random_number;

    const int MIN = 1;
    const int MAX = 10;//N range of values to get secret number from

    //ranges to calculate midpoint from
    int top_range = MAX;
    int bottom_range = MIN;

    //variables to store guesses
    int user_guess;
    int computer_guess;
    int guesses;

    string player;
    int game_number;

    int val[N];//variable to store the number of guesses
    int freq[N];//the frequency of each guess
    int guesses_max[N];//to store and find the max number of guesses
    int max_guess;//storing what's the maximum number of guesses
    int index;
    float mean;
    float sigma;



public:

    /***********FUNCTION DEFINITIONS***********/
    //generating random number here
    void generateRandom(){
        //first rand value always stays the same hence why it has to be generated twice
        rand();//have to generate and throw away first value before actually getting 'random' numbers
        random_number = 1+(MAX*rand())/(RAND_MAX+1.0);//random computer number;
    }

    //printing out display texts here
    void goLower(){
        cout<<"You were above the number"<<endl;
    }
    void goHigher(){
        cout<<"You were below the number"<<endl;
    }
    void rightGuess(){
        cout<<"You guessed right!"<<endl;
        cout<<"It took you "<<guesses<<" guesses"<<endl;
    }

    void populateArray(){//takes no input returns no value
        //populating both arrays for guesses and their frequencies with zero
        for(int i=1;i<N;i++){
            val[i] = 0;
            freq[i] = 0;
        }
    }


    /***********FUNCTION DECLARATIONS************/
    int playGame();
    void humanGuess();
    void computerGuess();
    void gameNumber();
    void printHistogram();
    void calcValues();
    void findMax();
};
