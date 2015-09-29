#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "AI.h"
#include <string.h>

using namespace std;

AI::AI(const vector<int> & current_boarder){
	boarder = current_boarder;
}

bool AI::is_in_a_line(int v1, int v2, int v3){
        return (v1 == v2 && v2 == v3 && (v1 == 1 || v1 == -1));
}

bool AI::column_in_a_line(){
        for(int i=0;i<3;i++)
                if(is_in_a_line(boarder[i], boarder[i+3], boarder[i+6]))
                        return true;
        return false;
}

bool AI::row_in_a_line(){
        for(int i=0;i<3;i++)
                if(is_in_a_line(boarder[3*i], boarder[3*i+1], boarder[3*i+2]))
                        return true;
        return false;
}

bool AI::diagonal_in_a_line(){
        return (is_in_a_line(boarder[0], boarder[4], boarder[8]) || is_in_a_line(boarder[2], boarder[4], boarder[6]));
}

int AI::scores_for_a_line(int v1, int v2, int v3){
        if(is_in_a_line(v1, v2, v3))
                return v1*10;
        else if((v1 == v2 || v1 == v3 )&& v1 != 0)
                return v1;
        else if(v2 == v3 && v2 != 0)
                return v2;
        else
                return 0;
}

int AI::scores_for_columns(){
        int col_scores = 0;
        for(int i=0;i<3;i++)
                col_scores += scores_for_a_line(boarder[i], boarder[i+3], boarder[i+6]);
        return col_scores;
}

int AI::scores_for_rows(){
        int row_scores = 0;
        for(int i=0;i<3;i++)
                row_scores += scores_for_a_line(boarder[3*i], boarder[3*i+1], boarder[3*i+2]);
        return row_scores;
}

int AI::scores_for_diagonals(){
        return (scores_for_a_line(boarder[0], boarder[4], boarder[8]) + scores_for_a_line(boarder[2], boarder[4], boarder[6]));
}

int AI::total_scores(){
        return (scores_for_rows() + scores_for_columns() + scores_for_diagonals());
}

bool AI::has_winner(){
        return (row_in_a_line() || column_in_a_line() || diagonal_in_a_line());
}

bool AI::is_full_boarder(){
        for(int i=0;i<9;i++)
                if(boarder[i] == 0)
                        return false;
        return true;
}

bool AI::is_empty(int row, int col){
        return (boarder[3*(col - 1) + row - 1] == 0);
}
