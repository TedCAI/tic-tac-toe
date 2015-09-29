#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class AI{
public:
	AI(const vector<int> &);
	vector<int> boarder;
	bool is_in_a_line(int, int, int);
        bool is_full_boarder();
        bool column_in_a_line();
        bool row_in_a_line();
        bool diagonal_in_a_line();
        bool has_winner();
        int scores_for_a_line(int, int, int);
        int scores_for_rows();
        int scores_for_columns();
        int scores_for_diagonals();
        int total_scores();
	bool is_empty(int, int);
};
