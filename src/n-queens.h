#pragma once

#include "leetcode.h"

using namespace std;

inline void print_queen(const vector<string>& queen) {
    for (auto&& row : queen) {
        for (auto&& c : row) {
            cout << (c == 'Q' ? " O" : " X");
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<string>> solveNQueens(const int n)
        : n_(n), map1_(n, true), map2_(2 * n - 1, true), map3_(2 * n - 1, true), temp_(n, string(n, '.')) {
        solve(0);
        return result_;
    }

private:
    size_t                 n_ = 0;
    vector<bool>           map1_, map2_, map3_;
    vector<string>         temp_;
    vector<vector<string>> result_;

    void solve(const size_t row) {
        if (row == n_) {
            result_.push_back(temp_);
            return;
        }
        for (size_t col = 0; col < n_; ++col) {
            const size_t p = row + col, q = row - col + n_ - 1;
            if (map1_[col] && map2_[p] && map3_[q]) {
                temp_[row][col] = 'Q';
                map1_[col] = map2_[p] = map3_[q] = false;
                solve(row + 1);
                temp_[row][col] = '.';
                map1_[col] = map2_[p] = map3_[q] = true;
            }
        }
    }
};

inline void test() {
    Solution   solution;
    const auto res = solution.solveNQueens(4);

    system("cls");
    for (auto&& vector : res) {
        print_queen(vector);
    }
}
