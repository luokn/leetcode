// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/

#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int res = 0;
    int dir[5] = {0, 1, 0, -1, 0};
    int M, N;
    int dfs(vector<vector<int>> &dp, vector<vector<int>> &matrix, int x, int y,
            int len) {
        if (dp[x][y] != -1)
            return dp[x][y];
        // int tmp = len;
        for (int i = 0; i < 4; i++) {
            int tx = x + dir[i];
            int ty = y + dir[i + 1];
            if (tx >= 0 && tx < M && ty >= 0 && ty < N) {
                if (matrix[tx][ty] > matrix[x][y]) {
                    dp[x][y] = max(dp[x][y], dfs(dp, matrix, tx, ty, len + 1));
                }
            }
        }
        return ++dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix.front().size())
            return 0;
        M = matrix.size(), N = matrix.front().size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                res = max(res, dfs(dp, matrix, i, j, 1));
            }
        }
        return ++res;
    }
};

inline void test() {
    Solution solution;
    cout << solution.longestIncreasingPath({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}})
         << endl; // 4
    cout << solution.longestIncreasingPath({{3, 4, 5}, {3, 2, 6}, {2, 2, 1}})
         << endl; // 4
    cout << solution.longestIncreasingPath(
                {{0, 0, 12, 6, 15, 1, 12, 10, 12, 10, 6},
                 {6, 19, 6, 13, 5, 18, 17, 19, 7, 11, 13},
                 {8, 6, 9, 1, 15, 7, 10, 10, 3, 7, 18},
                 {2, 14, 12, 10, 17, 2, 3, 10, 4, 8, 3},
                 {8, 2, 19, 3, 19, 10, 17, 18, 12, 10, 8},
                 {0, 17, 14, 12, 10, 4, 8, 17, 15, 11, 19},
                 {13, 6, 14, 8, 16, 19, 12, 17, 16, 17, 8},
                 {7, 4, 6, 8, 3, 9, 19, 12, 4, 13, 0},
                 {18, 0, 16, 12, 10, 11, 8, 14, 6, 3, 0},
                 {10, 3, 14, 17, 19, 18, 10, 2, 11, 5, 19},
                 {6, 2, 2, 1, 8, 1, 11, 7, 7, 18, 1},
                 {11, 12, 16, 0, 9, 6, 8, 3, 12, 8, 15},
                 {5, 18, 17, 4, 11, 9, 9, 6, 8, 2, 4},
                 {3, 12, 7, 2, 9, 17, 14, 10, 14, 5, 0}})
         << endl;
}