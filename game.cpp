#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "NewOxo.h"

using namespace std;

bool mode_validation(int mode){
	if(mode == 1){
		cout<<"Human vs human mode is selected"<<endl;
		return true;
	}
	else if(mode == 2){
		cout<<"Human vs AI mode is selected"<<endl;
		return true;
	}
	else
		return false;
}

int mode_selection(){
	int mode = 0;
	cout<<"Game mode selection"<<endl;
	cout<<"1. Human vs human"<<endl;
	cout<<"2. Human vs AI"<<endl;
	while(1){
		cout<<"Please enter 1 or 2: ";
		cin>>mode;
		if(mode_validation(mode))
			return mode;
		else
			cout<<"Invalid selection! Please try once again."<<endl;
	}
}

bool validate_selection(const char & selection){
	return (selection == 'Y' || selection == 'y' || selection == 'N' || selection == 'n');
}

int first_player(const char & selection){
	return ((selection == 'Y' || selection == 'y') ? 1 : -1);
}

int who_is_first_player(int mode){
	int player = 1;
	char selection;
	if(mode == 2){
		while(1){
			cout << "Do you want to start from you? (Y/N): ";
			cin >> selection;
			if(validate_selection(selection)){
				player = first_player(selection);
				break;
			}
			else
				cout << "Please Enter Y or N"<<endl;
		}
	}
	return player;
}

int main(){
	int mode, player;
	mode = mode_selection();
	player = who_is_first_player(mode);
	NewOxo * game = new NewOxo(player);
	game->start(mode);
	return 0;
}
