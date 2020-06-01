#pragma once

#include "leetcode.h"

using namespace std;

inline void dp_print(const vector<vector<int>>& dp) {
    for (auto&& vec : dp) {
        for (auto&& val : vec) {
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        const int m = word1.length() + 1;
        const int n = word2.length() + 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (auto i = 0; i < m; ++i)
            dp[i][0] = i;
        for (auto i = 0; i < n; ++i)
            dp[0][i] = i;

        dp_print(dp);
        system("cls");

        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                const auto d = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = std::min(d, dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = std::min(d, dp[i - 1][j - 1] + 1);
                }

                dp_print(dp);
                system("cls");
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

inline void test() {
    Solution solution;
    cout << solution.minDistance("horse", "ros");
}

