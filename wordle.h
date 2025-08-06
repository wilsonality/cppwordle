#pragma once
#include <string>


class Wordle{
public:
  // member functions
    Wordle();
    ~Wordle();
    int game_routine();
    std::string check_guess(char* g, char* s);
    std::string fetch_solution(int len);

  // member variables
    int guess_ct;
    int game_num;
    int word_length;
    std::string solution;
};