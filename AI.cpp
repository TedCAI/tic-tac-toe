#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "AI.h"
#include "boarder.h"
#include <string.h>

using namespace std;

bool AI::is_in_a_line(int v1, int v2, int v3){
        return (v1 == v2 && v2 == v3 && (v1 == 1 || v1 == -1));
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

int AI::scores_for_columns(const vector<int> & boarder){
        int col_scores = 0;
        for(int i=0;i<3;i++)
                col_scores += scores_for_a_line(boarder[i], boarder[i+3], boarder[i+6]);
        return col_scores;
}

int AI::scores_for_rows(const vector<int> & boarder){
        int row_scores = 0;
        for(int i=0;i<3;i++)
                row_scores += scores_for_a_line(boarder[3*i], boarder[3*i+1], boarder[3*i+2]);
        return row_scores;
}

int AI::scores_for_diagonals(const vector<int> & boarder){
        return (scores_for_a_line(boarder[0], boarder[4], boarder[8]) + scores_for_a_line(boarder[2], boarder[4], boarder[6]));
}

int AI::total_scores(const vector<int> & boarder){
        return (scores_for_rows(boarder) + scores_for_columns(boarder) + scores_for_diagonals(boarder));
}

bool AI::is_empty(const vector<int> & boarder, int row, int col){
        return (boarder[3*(col - 1) + row - 1] == 0);
}

vector<int> AI::scores_boarder(const vector<int> & current_boarder){
	vector<int> scores_boarder = current_boarder;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(!is_empty(current_boarder,j,i))
				scores_boarder[3*(i - 1) + j - 1] = 1024;
	return scores_boarder;
}

vector<int> AI::new_boarder(const vector<int> & old_boarder, int row, int col, int player){
	vector<int> new_boarder = old_boarder;
	new_boarder[3*(col - 1) + row - 1] = player;
	return new_boarder;
}

int AI::find_max(const vector<int> & scores){
	int max = (scores[0] == 1024) ? -1024 : scores[0];
	for(int i=0;i<9;i++)
		if(scores[i] > max && scores[i] != 1024)
			max = scores[i];
	return max;
}

int AI::find_min(const vector<int> & scores){
	int min = scores[0];
        for(int i=1;i<9;i++)
                if(scores[i] < min)
                        min = scores[i];
        return min;
}

int AI::best_score(const vector<int> & scores, int player){
	return ((player == 1) ? find_max(scores) : find_min(scores));
}

int AI::best_solution(const vector<int> & current_boader, int current_player){
	vector<int> scores;
	scores = bfs(current_boader, current_player);
	int score = best_score(scores, 1*current_player);
	for(int i=0;i<9;i++)
		if(scores[i] == score)
			return i;
}

vector<int> AI::bfs(const vector<int> & current_boarder, int current_player){
	Boarder * boarder_for_bfs = new Boarder(current_boarder, current_player);
	vector<int> score_boarder;
	score_boarder = scores_boarder(current_boarder);
	if(!boarder_for_bfs->has_winner() && !boarder_for_bfs->is_full_boarder()){
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				if(boarder_for_bfs->is_empty(j, i)){
					vector<int> updated_boarder, new_scores_boarder;
					updated_boarder = new_boarder(current_boarder, j, i, 1*current_player);
					new_scores_boarder = bfs(updated_boarder, -1*current_player);
					score_boarder[3*(i - 1) + j - 1] = best_score(new_scores_boarder, -1*current_player);
				}
	}else{
		for(int i=0;i<8;i++)
			score_boarder[i] = 1024;
		score_boarder[8] = total_scores(current_boarder);
	}
	return score_boarder;
}
