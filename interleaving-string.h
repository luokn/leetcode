#pragma once
#include "leetcode.h"

using namespace std;

inline void dp_print(const vector<vector<bool>>& dp) {
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
		const uint32_t m = src1.size(), n = src2.size();
		if (m + n != comp.size())
			return false;
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int k = 1; k <= m; ++k) {
			dp[k][0] = dp[k - 1][0] && src1[k - 1] == comp[k - 1];
			dp_print(dp);
		}
		for (int k = 1; k <= n; ++k) {
			dp[0][k] = dp[0][k - 1] && src2[k - 1] == comp[k - 1];
			dp_print(dp);
		}
		for (int i = 1; i <= m; ++i) {
			for (auto j = 1; j <= n; ++j) {
				dp[i][j] = (dp[i - 1][j] && src1[i - 1] == comp[i + j - 1]) || (dp[i][j - 1] && src2[j - 1] == comp[i + j - 1]);
				dp_print(dp);
			}
		}
		return dp[m][n];
	}
};

inline void test() {
	Solution solution;
	cout << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}
