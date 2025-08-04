#pragma once
#include <unordered_map>


class Wordle{
public:
  // member functions
    Wordle();
    ~Wordle();
    int game_routine();
    char* check_guess(char* g, char* s);
    char* fetch_solution(int len);

  // member variables
    int guess_ct;
    int game_num;
    int word_length;
    char* solution;
};