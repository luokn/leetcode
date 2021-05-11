// https://leetcode-cn.com/problems/minimum-path-sum/

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(const vector<vector<int>>& grid) {
        const size_t        M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        dp[0][0] = grid[0][0];
        for (size_t i = 1; i < M; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (size_t j = 1; j < N; j++) dp[0][j] = grid[0][j] + dp[0][j - 1];
        for (size_t i = 1; i < M; i++) {
            for (size_t j = 1; j < N; j++) {
                dp[i][j] = grid[i][j] + std::min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp.back().back();
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.minPathSum({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << endl;
}