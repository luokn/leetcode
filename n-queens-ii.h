#pragma once

#include "./leetcode.h"

using namespace std;

class Solution {
  public:
    int totalNQueens(const int n)
        : n_(n), map1_(n, true), map2_(2 * n - 1, true),
          map3_(2 * n - 1, true) {
        solve(0);
        return result_;
    }

  private:
    int n_ = 0;
    int result_ = 0;
    vector<bool> map1_, map2_, map3_;

    void solve(const int row) {
        if (row == n_) {
            ++result_;
            return;
        }
        for (auto col = 0; col < n_; ++col) {
            const auto ll = row + col;
            const auto rr = row - col + n_ - 1;
            if (map1_[col] && map2_[ll] && map3_[rr]) {
                map1_[col] = map2_[ll] = map3_[rr] = false;
                solve(row + 1);
                map1_[col] = map2_[ll] = map3_[rr] = true;
            }
        }
    }
};

inline void test() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
}
