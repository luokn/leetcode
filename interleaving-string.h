#pragma once
#include "leetcode.h"

using namespace std;

inline void print_dp(const vector<vector<bool>>& dp) {
    system("cls");
    for (auto&& vector : dp) {
        for (auto&& val : vector) {
            cout << (val ? "T" : "F") << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    bool isInterleave(const string& src1, const string& src2, const string& comp) {
        const size_t M = src1.size(), N = src2.size();
        if (M + N != comp.size()) return false;
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;
        for (size_t k = 1; k <= M; ++k) {
            dp[k][0] = dp[k - 1][0] && src1[k - 1] == comp[k - 1];
            // print_dp(dp);
        }
        for (size_t k = 1; k <= N; ++k) {
            dp[0][k] = dp[0][k - 1] && src2[k - 1] == comp[k - 1];
            // print_dp(dp);
        }
        for (size_t i = 1; i <= M; ++i) {
            for (size_t j = 1; j <= N; ++j) {
                dp[i][j] = (dp[i - 1][j] && src1[i - 1] == comp[i + j - 1]) ||
                           (dp[i][j - 1] && src2[j - 1] == comp[i + j - 1]);
                // print_dp(dp);
            }
        }
        return dp[M][N];
    }
};

inline void test() {
    Solution solution;
    cout << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}
