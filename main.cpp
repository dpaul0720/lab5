#include <iostream>
#include <fstream>
#include "Puzzle.h"

using namespace std;

int main(int argc, char** argv){
	string filename;
	if(argc == 2){
		filename = argv[1];
	}else{
		cout<<"Please input file: ";
		cin >> filename;
	}

	ifstream file(filename.c_str());
	if(!file.is_open()){
		cout << "Could not open file: " << filename << endl;
		return 1;
	}

	Puzzle<int> puzzle(9,0);	// Create Puzzle object
	file >> puzzle;		// use overloaded operator
	file.close();

	int row,col,num;

	while(puzzle.winCheck() == 1){		//Checks for win
		cout << "Sudoku" << endl;
		cout << puzzle;
		cout << "What row would you like to place(1-9)" << endl;
		cin >> row;
		cout << "What column would you like to place(1-9)" << endl;
		cin >> col;
		cout << "What number would you like to place (1-9)" << endl;
		cin >> num;

		if(puzzle.checkAll(row-1,col-1,num) == 0){
			puzzle.set(row-1,col-1,num);
		}	
		if(num == -1 || row == -1 || col == -1){
			break;
		}
		puzzle.winCheck();
	}
	cout << puzzle;
	cout << "Congrats you completed the puzzle!" << endl;
}