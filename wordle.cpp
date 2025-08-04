#include "wordle.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>

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
    // while testing, length = 5, solution = loner

    cout << "GAME: Please enter a word length between 5 and 7";
    word_length = 5; // default for testing
    } while (word_length > MAX_INT);
    // set word_length to user in

    cout << "GAME: Selecting a word of length " << word_length <<"...";

    solution = fetch_solution(word_length);

    cout << "GAME: the word has been selected";

    char* cur_guess;
    while (guess_ct < 6){
        printf("GAME: Number of guesses: %d", guess_ct);
        printf("GAME: Please make a guess");
        cin >> cur_guess;

        // exception handling needed, for when 0 is returned
        check_guess(cur_guess, solution);
    }

    return 0;
};

char* Wordle::fetch_solution(int len){
    // returns pointer to a char[] that is the solution
    // this ptr is stored to fetched

    char* fetched = (char *)malloc(sizeof(char) * len); // allocate size for solution word

    // assume we pick a word at random from our data
    char def_solution[] = "loner";

    // copy to fetched, and return
    strcpy(def_solution, fetched);

    return fetched;
}

char* Wordle::check_guess(char* g, char* s){
    /** scan until end of guess (given by word_length)
        if we encounter null, or fail to encounter at
        index word_length, guess is invalid
     */
    // two ptrs for each array
    char* i = g;
    char* j = s;
    char* result = (char *)malloc(sizeof(char) * (word_length + 1));

    
        // copy letters of solution to a set
        std::set<char> myset;
        while (*j != '0'){
            myset.insert(*j);
            j++;
        };


    // reset solution ptr
    j = s;

     while (*i != '\0' && *j != '\0'){
        // while both can be read

        if (*i == *j){ // if char ptrs are the same
            *result = 'G';
        }
        else if (*i != *j){ // else they differ
            if (myset.find(*i) == myset.end()){ // i not contained in solution 
                *result = 'X';
            }
            if (myset.find(*i) != myset.end()){
                *result = 'Y';
            }
        }
        i++;
        j++;
        result++;
     }


     if (*i != '\0' || *j != '\0'){
        // if only one ptr is null
        printf("GAME: Mismatched length between guess and solution");
        return 0;
     }

     // reset result ptr by decrementing it
     for (int n = (word_length + 1); n > 0; n--){
        result--;
     };

    return result;
};