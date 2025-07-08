#include "wordle.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_INT = 100000000;

Wordle::Wordle(){
    word_length = MAX_INT;
    guess_ct = 0;
    game_num = 0;
    for (int i = 0; i < 7; i++){
      solution[i] = '\0';
    }
    printf("starting game...");
}

Wordle::~Wordle(){}

int Wordle::game_routine(){
    // manages steps of the game
    /* select a word length
     * check guesses as they come in
     * decide victory or loss
     * finally, game_num++
    */

    do {
    cout << "GAME: Please enter a word length between 5 and 7";
    cin >> word_length;
    } while (word_length > MAX_INT);
    // set word_length to user in

    cout << "GAME: Selecting a word of length " << word_length <<"...";

    // draw a word from word list

    // while testing, length = 5, solution = loner
    word_length = 5;
    solution[0] = 'l';
    solution[1] = 'o';
    solution[2] = 's';
    solution[3] = 'e';
    solution[4] = 'r';


    cout << "GAME: the word has been selected";

    while (guess_ct < 6){
        string cur_guess;
        printf("GAME: Number of guesses: %d", guess_ct);
        printf("GAME: Please make a guess");
        check_guess(cur_guess);
    }

    return 0;
};

int check_guess(string guess){
//
return 0;
}    ;