#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class NewOxo{
public:
	NewOxo(int start_from = 1);
        vector<int> boarder;
	int player;
//	vector<vector<int> > _boarder(3, vector<int>(3,0));
//	void initiate();
//	int find_index(int[9], int);
	bool is_empty(int, int);
	void next_step(int, int, int);
	void next_player();
	string convert_value_to_string(int);
	vector<string> convert_boarder(const vector<int> &);
        void display_boarder(const vector<int> &);
	bool is_in_a_line(int, int, int);
	bool is_full_boarder();
	bool valid_step(int, int);
	bool column_in_a_line();
	bool row_in_a_line();
	bool diagonal_in_a_line();
	bool has_winner();
	int scores_for_a_line(int, int, int);
	int scores_for_rows();
	int scores_for_columns();
	int scores_for_diagonals();
	int total_scores();
//	void print(const vector<int> &);
//	bool gameover(const vector<int> &);
	

//	inline bool gameover(){
//		return gameover(boarder);
//	}
//	int max_vote(int[9],int);
//	int bfs(int[3][3], int, int);
//	int bfs(const vector<int> &, int, int);
//	int cal_vote(int[3][3]);
//	int cal_vote(vector< vector<int> > &);
	void start();
};
