#pragma once
#include "leetcode.h"

using namespace std;

inline void print_dp(const vector<vector<bool>>& dp) {
    system("cls");
    for (auto&& vector : dp) {
        for (auto&& value : vector) {
            cout << (value ? "O " : "X ");
        }
        cout << endl;
    }
}

class Solution {
public:
    bool isMatch(const string& src, const string& reg) {
        const size_t         M = src.length(), N = reg.length();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;
        for (size_t i = 1; i <= M; ++i) {
            if (reg[i] == '*' && dp[0][i - 1]) {
                dp[0][i + 1] = true;
            }
        }
        // print_dp(mem);
        for (size_t i = 0; i <= M; ++i) {
            for (size_t j = 0; j <= N; ++j) {
                if (reg[j] == src[i] || reg[j] == '.') {
                    dp[i + 1][j + 1] = dp[i][j];
                } else if (reg[j] == '*') {
                    if (reg[j - 1] != src[i]) {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    }
                    if (reg[j - 1] == src[i] || reg[j - 1] == '.') {
                        dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1]);
                    }
                }
                // print_dp(mem);
            }
        }
        return dp[M][N];
    }
};

inline void test() {
    Solution solution;
    cout << (solution.isMatch("abcde", "ab.*e") ? "Ok" : "Error");
}
