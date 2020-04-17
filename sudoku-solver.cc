#include "leetcode.h"

using namespace std;

void print_board(const vector<vector<char>>& board) {
	stringstream ss;
	for (auto row = 0; row < 9; ++row) {
		for (auto col = 0; col < 9; ++col) {
			if (board[row][col] == '.') {
				ss << "  ";
			} else {
				ss << board[row][col] << " ";
			}
			if ((col + 1) % 3 == 0 && col != 8) {
				ss << "| ";
			}
		}
		if ((row + 1) % 3 == 0 && row != 8) {
			ss << endl;
			for (auto i = 0; i < 22; ++i) {
				ss << "-";
			}
			ss << endl;
		} else {
			ss << endl;
		}
	}
	cout << ss.rdbuf();
}

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		for (auto i = 0; i < 9; ++i) {
			for (auto j = 0; j < 9; ++j) {
				auto ch = board[i][j];
				if (ch == '.') {
					spaces_.emplace_back(i, j);
				} else {
					const auto b = 3 * (i / 3) + (j / 3);
					ch -= '1';
					row_[i][ch] = true;
					col_[j][ch] = true;
					block_[b][ch] = true;
				}
			}
		}
		solve(board, 0);
	}

	void clear() {
		spaces_.clear();
		for (auto i = 0; i < 9; ++i) {
			for (auto j = 0; j < 9; ++j) {
				row_[i][j] = false;
				col_[i][j] = false;
				block_[i][j] = false;
			}
		}
	}

	bool solve(vector<vector<char>>& board, const int pos) {
		if (pos < spaces_.size()) {
			const auto& [x_, y_] = spaces_.at(pos);
			const auto b = 3 * (x_ / 3) + (y_ / 3);
			for (auto i = 0; i < 9; ++i) {
				if (row_[x_][i] || col_[y_][i] || block_[b][i])
					continue;
				board[x_][y_] = '1' + i;
				row_[x_][i] = true;
				col_[y_][i] = true;
				block_[b][i] = true;
				if (solve(board, pos + 1))
					return true;
				board[x_][y_] = '.';
				row_[x_][i] = false;
				col_[y_][i] = false;
				block_[b][i] = false;
			}
			return false;
		}
		return true;
	}


private:
	bool row_[9][9]{};
	bool col_[9][9]{};
	bool block_[9][9]{};
	vector<tuple<int, int>> spaces_{};
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<vector<char>> board{
			{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	solution.solveSudoku(board);
	print_board(board);
}
