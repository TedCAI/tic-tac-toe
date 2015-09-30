#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class AI{
public:
	bool is_in_a_line(int, int, int);
        int scores_for_a_line(int, int, int);
        int scores_for_rows(const vector<int> &);
        int scores_for_columns(const vector<int> &);
        int scores_for_diagonals(const vector<int> &);
        int total_scores(const vector<int> &);
	bool is_empty(const vector<int> &, int, int);
	int find_max(const vector<int> &);
	int find_min(const vector<int> &);
	int best_score(const vector<int> &, int);
	int best_solution(const vector<int> &, int);
	vector<int> scores_boarder(const vector<int> &);
	vector<int> new_boarder(const vector<int> &, int, int, int);
	vector<int> bfs(const vector<int> &, int);
};
