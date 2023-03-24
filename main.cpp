#include "functions.h"
#include <map>
#include <thread>
#include <chrono>


int main(){
    auto board = createBoard();

    std::map<std::pair<int,int>,int> mp_x;
    std::map<std::pair<int,int>,int> mp_o;

    std::pair<int,int> first_move;
    std::pair<int,int> second_move;



   /* int slot;

    while(!check_board(board)){
        drawBoard(board);

        std::cout<<std::endl;

        std::cin>>slot;

        place_circle_x(slot,board,'x');

        if(check_winner(board) == 'x'){
            break;
        }

        if(!check_for_best_move(board,'o')){
            while((!check_board(board)) && (!random_circle_x(board, 'o')));
        }

        if(check_winner(board) == 'o'){
            break;
        }
    }
    drawBoard(board);
    std::cout<<"Winner is symbol: "<<check_winner(board)<<"!!!"<<std::endl;
    std::cout<<"Congratulations!!!"<<std::endl;
    */


    for(int i = 0; i < 1000000; i++){

        random_circle_x(board,'x');
        first_move = check_position(board, 'x');
        random_circle_x(board, 'o');
        second_move = check_position(board, 'o');

        while(!check_board(board)){

            if(!check_for_best_move(board,'x')){
                while(!random_circle_x(board, 'x'));
            }

            if(check_winner(board) == 'x'){
                mp_x[first_move]++;
                break;
            }
            if(!check_for_best_move(board,'o')){
                while((!check_board(board)) && (!random_circle_x(board, 'o')));
            }

            if(check_winner(board) == 'o'){
                mp_o[second_move]++;
                break;
            }

            //std::this_thread::sleep_for(std::chrono::seconds(2));
            //drawBoard(board);

        }
        board = createBoard();
    }

    int sum = 0;
    int sum_2 = 0;

    for(auto x : mp_x){
        std::cout << " Row: "<< x.first.first<< " Column: " <<x.first.second << " Games won by x: "<<x.second<<std::endl;
        sum+=x.second;
    }

    std::cout<<std::endl;

    for(auto x : mp_o){
        std::cout << " Row: "<< x.first.first<< " Column: " <<x.first.second << " Games won by o: "<<x.second<<std::endl;
        sum_2+=x.second;
    }

    std::cout<<"X won in total: "<<sum<<" where as, o had won: "<<sum_2<<std::endl;
    std::cout<< (sum < sum_2 ? sum_2 - sum : sum - sum_2) << std::endl;



    return 0;
}