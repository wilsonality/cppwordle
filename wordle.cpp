#include "wordle.h"
#include <iostream>
#include <cstdlib>
#include <string>
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
        try{
            if (check_guess(cur_guess, solution) == "\0"){
                throw;
            };}
        catch(out_of_range){
            printf("GAME: ERROR. Mismatched length between guess and solution");
        }
        
    }

    return 0;
};

std::string Wordle::fetch_solution(int len){
    // returns pointer to a char[] that is the solution
    // this ptr is stored to fetched

    std::string fetched = "LONER"; // allocate size for solution word

    // assume we pick a word at random from our data, default for now is LONER

    // copy to fetched, and return

    return fetched;
}

std::string Wordle::check_guess(std::string g, std::string s){
    /** scan until end of guess (given by word_length)
        if we encounter null, or fail to encounter at
        index word_length, guess is invalid
     */

    int i = 0; // guess index
    std::string result = ""; // colors will be appended to the string

        // copy letters of solution to a set
        std::set<char> myset;
        for (std::string::iterator it = s.begin(); it != s.end(); ++it){ // uses an iterator
            myset.insert(s[i]);
        };


    // reset solution ptr
    i = 0;

     while (g[i] != '\0' && s[i] != '\0'){
        // while both can be read

        if (g[i] == s[i]){ // if char ptrs are the same
            result.push_back('G');
        }
        else if (g[i] != s[i]){ // else they differ
            if (myset.find(g[i]) == myset.end()){ // i not contained in solution 
                result.push_back('X');
            }
            if (myset.find(g[i]) != myset.end()){
                result.push_back('Y');
            }
        }
        i++;
     }


     if (g[i] != '\0' || s[i] != '\0'){
        // if only one ptr is null
        return 0;
     }

    return result;
};