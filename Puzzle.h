#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename t>
class Puzzle{
	template <typename s>
	friend istream& operator>>(istream&, Puzzle<s> &);
	template <typename s>
	friend ostream& operator<<(ostream&, Puzzle<s>&);

	public:		// all the fucntions needed to run program
		Puzzle(int, t);
		void set(int, int, t);
		int winCheck();	
		int rowCheck(int, t);
		int colCheck(int, t);
		int squareCheck(int, int, t);
		int checkAll(int, int, t);



	private:
		vector<vector<t> > board;		//2d Vector for the board
		t value;

};



template <typename t>	//overloading the operator
ostream& operator<<(ostream& stream, Puzzle<t> &puzzle){
	for(int i = 0; i < 9;i++){
		for(int j = 0; j < 9; j++){
			stream << puzzle.board[i][j] << " ";
		} 
		stream << endl;
	}
	return stream;
}

template <typename t>	//overloaindg >> operator
istream& operator>>(istream& stream, Puzzle<t> &puzzle){
	t var;
	for(int i = 0; i < 9;i++){
		for(int j = 0; j < 9; j++){
			stream >> var;
			puzzle.board[i][j] = var;
		} 
	}
	return stream;
}

template <typename t>	//Constructor
Puzzle<t>::Puzzle(int size, t element){
	t var;
	for(int i = 0; i <size; i++){
		vector<t> row(size, 0);
		board.push_back(row);
	}
	value = element;
}

template <typename t>
int Puzzle<t>::checkAll(int row, int col, t num){
	int i = 0;
	i += rowCheck(row, num);
	i += colCheck(col, num);
	i += squareCheck(row, col, num);

	if(i == 0){
		return 0;
	}
	else{
		return 1;
	}
}

template <typename t>	//Sets a certain place to that number
void Puzzle<t>::set(int row, int col, t num){
	board[row][col] = num;
}

template <typename t>	//check for placement
int Puzzle<t>::rowCheck(int row, t num){
	for(int i = 0; i < 9; i++){
		if(board[row][i] == num){
			cout << num << " cannot be place in that row" << endl;
			return 1;
		}
	}
	return 0;
}

template <typename t>	//check for placement
int Puzzle<t>::colCheck(int col, t num){
	for(int i = 0; i < 9; i++){
		if(board[i][col] == num){
			cout << num << " cannot be placed in that column" << endl;
			return 1;
		}
	}
	return 0;
}

template <typename t>	//checks for square placement
int Puzzle<t>::squareCheck(int row, int col, t num){
	int square_row, square_col;
	if(row < 3){
		square_row = 0;
	}else if( row > 2 && row < 6){
		square_row = 3;
	}else{ square_row = 6;}

	if(col < 3){
		square_col = 0;
	}else if( col > 2 && col < 6){
		square_col = 3;
	}else{ square_col = 6;}
	for(int i = square_row; i < square_row+3; i++){
		for(int j = square_col; j < square_col+3; j++){
			if(num == board[square_row][square_col]){
				return 1;
			}
		}
	}
	return 0;	
}

template <typename t>	//checks for win
int Puzzle<t>::winCheck(){
	for(int i = 0; i < 9;i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j] == 0){
				return 1;
			}
		} 
	}
	return 0;
}


#endif