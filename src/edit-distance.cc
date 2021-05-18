#include "leetcode.h"

using namespace std;

inline void print_dp(const vector<vector<int>>& dp) {
    system("cls");
    for (auto&& vec : dp) {
        for (auto&& val : vec) {
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

class Solution {
public:
    int minDistance(const string& w1, const string& w2) {
        const size_t        M = w1.length(), N = w2.length();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (size_t i = 0; i <= M; ++i) {
            dp[i][0] = i;
        }
        for (size_t i = 0; i <= N; ++i) {
            dp[0][i] = i;
        }

        // print_dp(dp);

        for (size_t i = 1; i <= M; ++i) {
            for (size_t j = 1; j <= N; ++j) {
                int dist = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if (w1[i - 1] == w2[j - 1]) {
                    dp[i][j] = std::min(dist, dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = std::min(dist, dp[i - 1][j - 1] + 1);
                }
                // print_dp(dp);
            }
        }
        return dp[M][N];
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.minDistance("horse", "ros");
}
