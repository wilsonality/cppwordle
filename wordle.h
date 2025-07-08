#pragma once
#include <unordered_map>


class Wordle{
public:
  // member functions
    Wordle();
    ~Wordle();
    int game_routine();
    int check_guess(std::string guess);

  // member variables
    int guess_ct;
    int game_num;
    int word_length;
    char solution[7];
};