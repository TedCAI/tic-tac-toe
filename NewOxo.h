#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "boarder.h"

using namespace std;

class NewOxo{
public:
	NewOxo(int start_from = 1);
        vector<int> boarder;
	int player;
	bool is_empty(int, int);
	void next_step(int, int, int);
	void next_step(int, int);
	void human_player(Boarder *);
	void AI_player(Boarder *);
	void next_player();
	string convert_value_to_string(int);
	vector<string> convert_boarder(const vector<int> &);
        void display_boarder(const vector<int> &);
	bool is_full_boarder();
	bool valid_step(int, int);
	bool has_winner();
	void start(int);
};
