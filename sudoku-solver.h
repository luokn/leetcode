// https://leetcode-cn.com/problems/sudoku-solver/

#pragma once
#include "leetcode.h"

using namespace std;

inline ostream &operator<<(ostream &os, const vector<vector<char>> &board) {
    for (size_t r = 0; r < 9; ++r) {
        for (size_t c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                os << "  ";
            } else {
                os << board[r][c] << " ";
            }
            if ((c + 1) % 3 == 0 && c != 8) {
                os << "| ";
            }
        }
        if ((r + 1) % 3 == 0 && r != 8) {
            os << endl;
            for (size_t i = 0; i < 22; ++i) {
                os << "-";
            }
            os << endl;
        } else {
            os << endl;
        }
    }
    return os;
}

class Solution {
  public:
    void solveSudoku(vector<vector<char>> &board) {
        for (size_t r = 0; r < 9; ++r) {
            for (size_t c = 0; c < 9; ++c) {
                size_t n = board[r][c];
                const size_t b = 3 * (r / 3) + (c / 3);
                if (n == '.') {
                    spaces_.emplace_back(r, c);
                } else {
                    n -= '1';
                    row_[r][n] = col_[c][n] = block_[b][n] = true;
                }
            }
        }
        solve(board, 0);
    }

    bool solve(vector<vector<char>> &board, const size_t pos) {
        if (pos >= spaces_.size())
            return true;
        const auto &[r, c] = spaces_[pos];
        const size_t b = 3 * (r / 3) + (c / 3);
        for (size_t i = 0; i < 9; ++i) {
            if (row_[r][i] || col_[c][i] || block_[b][i])
                continue;
            board[r][c] = '1' + i;
            row_[r][i] = col_[c][i] = block_[b][i] = true;
            if (solve(board, pos + 1))
                return true;
            board[r][c] = '.';
            row_[r][i] = col_[c][i] = block_[b][i] = false;
        }
        return false;
    }

  private:
    bool row_[9][9]{};
    bool col_[9][9]{};
    bool block_[9][9]{};
    vector<tuple<int, int>> spaces_{};
};

inline void test() {
    Solution solution;
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solution.solveSudoku(board);
    cout << board << endl;
}
