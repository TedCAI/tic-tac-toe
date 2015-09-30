#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "boarder.h"
#include <string.h>

using namespace std;

Boarder::Boarder(const vector<int> & current_boarder, int current_player){
	boarder = current_boarder;
	player = current_player;
}

bool Boarder::is_in_a_line(int v1, int v2, int v3){
        return (v1 == v2 && v2 == v3 && (v1 == 1 || v1 == -1));
}

bool Boarder::column_in_a_line(){
        for(int i=0;i<3;i++)
                if(is_in_a_line(boarder[i], boarder[i+3], boarder[i+6]))
                        return true;
        return false;
}

bool Boarder::row_in_a_line(){
        for(int i=0;i<3;i++)
                if(is_in_a_line(boarder[3*i], boarder[3*i+1], boarder[3*i+2]))
                        return true;
        return false;
}

bool Boarder::diagonal_in_a_line(){
        return (is_in_a_line(boarder[0], boarder[4], boarder[8]) || is_in_a_line(boarder[2], boarder[4], boarder[6]));
}

bool Boarder::has_winner(){
	return (column_in_a_line() || row_in_a_line() || diagonal_in_a_line());
}

bool Boarder::is_full_boarder(){
        for(int i=0;i<9;i++)
                if(boarder[i] == 0)
                        return false;
        return true;
}

bool Boarder::is_empty(int row, int col){
        return (boarder[3*(col - 1) + row - 1] == 0);
}

vector<int> Boarder::copy_boarder(){
	vector<int> copied_boarder(9);
	for(int i=0;i<9;i++)
		copied_boarder[i] = boarder[i];
	return copied_boarder;
}
