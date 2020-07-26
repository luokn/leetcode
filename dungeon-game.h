// https://leetcode-cn.com/problems/dungeon-game/

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int calculateMinimumHP(const vector<vector<int>> &dungeon) {
        const int M = dungeon.size(), N = dungeon.front().size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        dp[M - 1][N - 1] = max(1, 1 - dungeon[M - 1][N - 1]);
        for (int i = M - 2; i >= 0; --i) {
            dp[i][N - 1] = max(1, dp[i + 1][N - 1] - dungeon[i][N - 1]);
        }
        for (int j = N - 2; j >= 0; --j) {
            dp[M - 1][j] = max(1, dp[M - 1][j + 1] - dungeon[M - 1][j]);
        }
        for (int i = M - 2; i >= 0; --i) {
            for (int j = N - 2; j >= 0; --j) {
                dp[i][j] =
                    max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp.front().front();
    }
};

inline void test() {
    Solution solution;
    cout << solution.calculateMinimumHP(
                {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}})
         << endl; // 7
}