#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const std::vector<vector<char>> &board) {
    for (auto &&row : board) {
        for (auto &&col : row) {
            os << col << "  ";
        }
        os << endl;
    }
    return os;
}

class Solution {
  public:
    int domino(int n, int m, const vector<vector<int>> &broken) {
        vector<vector<char>> board(n, vector<char>(m, 0));
        for (auto &&xy : broken) {
            board[xy[0]][xy[1]] = 'X';
        }
        const int L = (n * m - broken.size()) / 2;
        int res = 0;
        stack<tuple<char, int, int>> opr_stk;
        for (int row = 0, col = 0;;) {
            if (board[row][col] == 0) {
                if (col + 1 < m && board[row][col + 1] == 0) {
                    board[row][col] = board[row][col + 1] = 'O';
                    opr_stk.emplace('-', row, col);
                    col += 2;
                } else if (row + 1 < n && board[row + 1][col] == 0) {
                    board[row][col] = board[row + 1][col] = 'O';
                    opr_stk.emplace('|', row, col);
                    ++col;
                } else {
                    ++col;
                }
                //
                system("cls");
                cout << board << endl;
            } else {
                ++col;
            }
            if (col >= m) {
                ++row;
                col = 0;
            }
            // 回退
            if (row >= n) {
                res = std::max<int>(res, opr_stk.size());
                if (opr_stk.size() == L) {
                    return L;
                }
                for (;;) {
                    if (opr_stk.empty())
                        return res;
                    auto &[dir, x, y] = opr_stk.top();
                    if (dir == '-') {
                        board[x][y + 1] = 0;
                        if (x + 1 < n && board[x + 1][y] == 0) {
                            board[x + 1][y] = 'O';
                            opr_stk.pop();
                            opr_stk.emplace('|', x, y);
                            row = x;
                            col = y;
                            break;
                        }

                    } else {
                        board[x][y] = board[x + 1][y] = 0;
                    }
                    opr_stk.pop();

                    //
                    system("cls");
                    cout << board << endl;
                }
            }
        }
    }
};

inline void test() {
    Solution solution;

    // cout << solution.domino(2, 3, {{1, 0}, {1, 1}}) << endl;
    // cout << solution.domino(3, 3, {}) << endl;
    cout << solution.domino(8, 8,
                            {{1, 0},
                             {2, 5},
                             {3, 1},
                             {3, 2},
                             {3, 4},
                             {4, 0},
                             {4, 3},
                             {4, 6},
                             {4, 7},
                             {5, 3},
                             {5, 5},
                             {5, 6},
                             {6, 3},
                             {7, 2},
                             {7, 7}})
         << endl;
}