#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class Boarder{
public:
	Boarder(const vector<int> &, int current_player = 1);
	vector<int> boarder;
	int player;
	bool is_in_a_line(int, int, int);
        bool is_full_boarder();
        bool column_in_a_line();
        bool row_in_a_line();
        bool diagonal_in_a_line();
        bool has_winner();
	bool is_empty(int, int);
	vector<int> copy_boarder();
};
