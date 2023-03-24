//
// Created by User on 24.03.2023.
//


#ifndef UNTITLED3_FUNCTIONS_H
#define UNTITLED3_FUNCTIONS_H
#include <iostream>
#include <vector>

void drawBoard(std::vector<std::vector<char>>);
std::vector<std::vector<char>> createBoard();
bool place_circle_x(int, std::vector<std::vector<char>>&, char);
bool is_valid(int, int, std::vector<std::vector<char>> &);
bool random_circle_x(std::vector<std::vector<char>> &, char);
char check_winner(std::vector<std::vector<char>> &);
bool check_board(std::vector<std::vector<char>> &);
std::pair<int,int>  check_position(std::vector<std::vector<char>> &, char );
bool check_for_best_move(std::vector<std::vector<char>> &board, char , bool it = false);
#endif //UNTITLED3_FUNCTIONS_H

