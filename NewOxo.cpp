#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "NewOxo.h"
#include <string.h>
#include "AI.h"


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

bool NewOxo::valid_step(int row, int col){
	return (3*(col -1) + row - 1 >= 0 && 3*(col -1) + row - 1 < 9);
}

bool NewOxo::is_empty(int row, int col){
	return (boarder[3*(col - 1) + row - 1] == 0);
}

void NewOxo::next_step(int row, int col, int player){
	boarder[3*(col - 1) + row - 1] = player;	
}

void NewOxo::next_step(int index, int player){
	boarder[index] = player;
}

void NewOxo::human_player(Boarder * game_boarder){
	cout<<"Player "<<convert_value_to_string(player)<<"'s turn."<<endl;
	int row, col;
	cout<<"Select a column (1~3): ";
	cin>>row;
        cout<<"Select a row (1~3): ";
	cin>>col;
	if(valid_step(row, col) && game_boarder->is_empty(row, col)){
		next_step(row, col, player);
		game_boarder->boarder = boarder;
	}
	else{
		cout<<"Invalid location! Please try again!"<<endl;
		next_player();
	}
}

void NewOxo::AI_player(Boarder * game_boarder){
	cout<<"AI's turn!"<<endl;
	AI * ai = new AI();
	int AI_solution = -1;
        AI_solution = ai->best_solution(boarder, player);
	next_step(AI_solution, player);
	game_boarder->boarder = boarder;
}

void NewOxo::start(){
	Boarder * game_boarder = new Boarder(boarder);
	while(!is_full_boarder()){
		display_boarder(boarder);
		if(player == -1)
			human_player(game_boarder);
		else
			AI_player(game_boarder);
			if(game_boarder->has_winner()){
				display_boarder(boarder);
				cout<<"Player "<<convert_value_to_string(player)<<" win!"<<endl;
				break;
			}			
			else
				next_player();
	}
}
