//
// Created by User on 24.03.2023.
//

#include "functions.h"

std::vector<std::vector<char>> createBoard(){
    return std::vector<std::vector<char>>{
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
    };
}

void drawBoard(std::vector<std::vector<char>> board) {
    std::cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2]<<std::endl;
    std::cout << "========="<<std::endl;
    std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2]<<std::endl;
    std::cout << "========="<<std::endl;
    std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2]<<std::endl;
}

bool place_circle_x(int slot, std::vector<std::vector<char>>  &board, char symbol) {
    int row = slot / 3;
    int col;

    if (slot % 3 == 0) {
        row--;
        col = 2;
    } else col = (slot % 3) - 1;
    if(is_valid(row, col, board)){
            board[row][col] = symbol;
            return true;
        }
    return false;
}

bool is_valid(int row, int col, std::vector<std::vector<char>> & board){
    if((board[row][col] == 'x') || (board[row][col] == 'o'))
        return false;
    return true;
}

bool random_circle_x(std::vector<std::vector<char>> &board, char symbol){
    int random = rand() % 9 + 1;
    int row = random / 3;
    int col;


    if(random % 3 == 0) {
        row--;
        col = 2;
    }else col = (random % 3) - 1;
    if(is_valid(row, col, board)){
        board[row][col] = symbol;
        return true;
    }
    return false;
}


char check_winner(std::vector<std::vector<char>> & board){
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'x') || (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'o')) return board[2][2];
    if((board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == 'x') || (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == 'o'))return board[0][2];
    for(int i = 0; i < 3; i++){
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][2] == 'x') || (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][2] == 'o'))
            return board[i][0];
        else if ((board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'x') || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'o'))
            return board[0][i];
    }
    return ' ';
}

bool check_board(std::vector<std::vector<char>> & board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

std::pair<int,int> check_position(std::vector<std::vector<char>> & board, char symbol){
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(board[i-1][j-1] == symbol) {
                std::pair<int,int> p1(i,j);
                return p1;
            }
        }
    }
    return {};
}

bool check_for_best_move(std::vector<std::vector<char>> & board, char symbol, bool it ){

    char opposite = symbol == 'x' ? 'o' : 'x';

    auto eq = [=](char a, char b, char symbol){
        if(a != symbol)
            return false;
        if(b != symbol)
            return false;
        return a == b ? true : false;
    };

    if(eq(board[0][0],board[1][1], symbol) && is_valid(2,2,board)){
        board[2][2] = it == false ? symbol : opposite;
        return true;
    }
    else if(eq(board[1][1],board[2][2], symbol) && is_valid(0,0,board)){
        board[0][0] = it == false ? symbol : opposite;
        return true;
    }
    else if(eq(board[0][0],board[2][2], symbol) && is_valid(1,1,board)){
        board[1][1] = it == false ? symbol : opposite;
        return true;
    }
    else if(eq(board[2][0],board[1][1], symbol) && is_valid(0,2,board)){
        board[0][2] = it == false ? symbol : opposite;
        return true;
    }
    else if(eq(board[1][1],board[0][2], symbol) && is_valid(2,0,board)){
        board[2][0] = it == false ? symbol : opposite;
        return true;
    }
    else if(eq(board[2][0],board[0][2], symbol) && is_valid(1,1,board)){
        board[1][1] = it == false ? symbol : opposite;
        return true;
    }

    for(int i = 0; i < 3; i++) {
        if (eq(board[i][1], board[i][0], symbol) && is_valid(i, 2, board)) {
            board[i][2] = it == false ? symbol : opposite;;
            return true;
        } else if (eq(board[i][1], board[i][2], symbol) && is_valid(i, 0, board)) {
            board[i][0] = it == false ? symbol : opposite;
            return true;
        } else if (eq(board[1][i], board[0][i], symbol) && is_valid(2, i, board)) {
            board[2][i] = it == false ? symbol : opposite;
            return true;
        } else if (eq(board[1][i], board[2][i], symbol) && is_valid(0, i, board)) {
            board[0][i] = it == false ? symbol : opposite;
            return true;
        } else if(eq(board[i][0], board[i][2], symbol) && is_valid(i, 1, board)){
            board[i][1] = it == false ? symbol : opposite;
            return true;
        }else if(eq(board[0][i], board[2][i], symbol) && is_valid(1, i, board)){
            board[1][i] = it == false ? symbol : opposite;
            return true;
        }
    }

    return it == false ? check_for_best_move(board, opposite, true) : false;
}

