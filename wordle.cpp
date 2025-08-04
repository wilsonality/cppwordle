#include "wordle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_INT = 100000000;

Wordle::Wordle(){
    word_length = MAX_INT;
    guess_ct = 0;
    game_num = 0;

    for (int i = 0; i < 7; i++){
        // initialize solution to null
      solution[i] = '\0';
    }

    printf("starting game...");
    game_routine();
    return;
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
    word_length = 5; // default for testing
    } while (word_length > MAX_INT);
    // set word_length to user in

    cout << "GAME: Selecting a word of length " << word_length <<"...";

    solution = fetch_solution(word_length);

    // draw a word from word list

    // while testing, length = 5, solution = loner
    word_length = 5;
    

    cout << "GAME: the word has been selected";

    while (guess_ct < 6){
        char* cur_guess;
        printf("GAME: Number of guesses: %d", guess_ct);
        printf("GAME: Please make a guess");
        check_guess(cur_guess);
    }

    return 0;
};

char* Wordle::fetch_solution(int len){
    // returns pointer to a char[] that is the solution
    // this ptr is stored to solution (type char*)

    // assume we pick a word at random from our data

    char* fetched = (char *)malloc(sizeof(char) * len); // allocate size for solution word

    for (int i = 0; i < len; i++){}


    return fetched;
}

int Wordle::check_guess(char* guess){
    /** scan until end of guess (given by word_length)
        if we encounter null, or fail to encounter at
        index word_length, guess is invalid
     */
    return 0;
};