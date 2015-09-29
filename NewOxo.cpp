#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "NewOxo.h"
#include <string.h>

using namespace std;

NewOxo::NewOxo(int start_from){
	player = start_from;
	for(int i=0;i<9;i++)
		boarder.push_back(0);
}

void NewOxo::next_player(){
	player *= -1;
}

string NewOxo::convert_value_to_string(int value){
	switch(value){
		case 0:
			return " ";
		case 1:
			return "o";
		case -1:
			return "x";
		default:
			return "error";
	}
}

vector<string> NewOxo::convert_boarder(const vector<int> & int_boarder){
	vector<string> converted_boarder(9);
	for(int i=0;i<9;i++)
		converted_boarder[i] = convert_value_to_string(int_boarder[i]);
	return converted_boarder;
}

void NewOxo::display_boarder(const vector<int> & current_boarder){
	vector<string> converted_boarder = convert_boarder(current_boarder);
	for(int i=0;i<3;i++)
		cout<<converted_boarder[i*3]<<" | "<<converted_boarder[i*3+1]<<" | "<<converted_boarder[i*3+2]<<endl;
}

bool NewOxo::is_full_boarder(){
	for(int i=0;i<9;i++)
		if(boarder[i] == 0)
			return false;
	return true;
}

bool NewOxo::is_in_a_line(int v1, int v2, int v3){
	return (v1 == v2 && v2 == v3 && (v1 == 1 || v1 == -1));
}

bool NewOxo::column_in_a_line(){
	for(int i=0;i<3;i++)
		if(is_in_a_line(boarder[i], boarder[i+3], boarder[i+6]))
			return true;
	return false;
}

bool NewOxo::row_in_a_line(){
	for(int i=0;i<3;i++)
		if(is_in_a_line(boarder[3*i], boarder[3*i+1], boarder[3*i+2]))
			return true;
	return false;
}

bool NewOxo::diagonal_in_a_line(){
	return (is_in_a_line(boarder[0], boarder[4], boarder[8]) || is_in_a_line(boarder[2], boarder[4], boarder[6]));
}

bool NewOxo::has_winner(){
	return (row_in_a_line() || column_in_a_line() || diagonal_in_a_line());
}

bool NewOxo::valid_step(int row, int col){
	return (3*(col -1) + row - 1 >= 0 && 3*(col -1) + row - 1 < 9);
}

bool NewOxo::is_empty(int row, int col){
	return (boarder[3*(col - 1) + row - 1] == 0);
}

void NewOxo::next_step(int row, int col, int player){
	boarder[3*(col - 1) + row - 1] = player;	
}

int NewOxo::scores_for_a_line(int v1, int v2, int v3){
	if(is_in_a_line(v1, v2, v3))
		return v1*10;
	else if((v1 == v2 || v1 == v3 )&& v1 != 0)
		return v1;
	else if(v2 == v3 && v2 != 0)
		return v2;
	else
		return 0;
}

int NewOxo::scores_for_columns(){
	int col_scores = 0;
        for(int i=0;i<3;i++)
                col_scores += scores_for_a_line(boarder[i], boarder[i+3], boarder[i+6]);
        return col_scores;
}

int NewOxo::scores_for_rows(){
	int row_scores = 0;
        for(int i=0;i<3;i++)
                row_scores += scores_for_a_line(boarder[3*i], boarder[3*i+1], boarder[3*i+2]);
        return row_scores;
}

int NewOxo::scores_for_diagonals(){
        return (scores_for_a_line(boarder[0], boarder[4], boarder[8]) + scores_for_a_line(boarder[2], boarder[4], boarder[6]));
}

int NewOxo::total_scores(){
	return (scores_for_rows() + scores_for_columns() + scores_for_diagonals());
}

void NewOxo::start(){
	while(!is_full_boarder()){
		display_boarder(boarder);
		cout<<"Player "<<convert_value_to_string(player)<<"'s turn."<<endl;
		int row, col;
		cout<<"Select a column (1~3): ";
		cin>>row;
		cout<<"Select a row (1~3): ";
		cin>>col;
		if(valid_step(row, col) && is_empty(row, col)){
			next_step(row, col, player);
			if(has_winner()){
				display_boarder(boarder);
				cout<<"Player "<<convert_value_to_string(player)<<" win!"<<endl;
				break;
			}			
			else
				next_player();
		}
		else
			cout<<"Invalid location! Please try again!"<<endl;
		
	}
}
