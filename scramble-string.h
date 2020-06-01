#include "leetcode.h"

using namespace std;

class Solution {
public:
	int minCut(const string& s) {
		if (s.empty()) return 0;
		const int n = s.size();
		vector<vector<bool> > p(n, vector<bool>(n, false));
		vector<int> dp(n, 0);
		for (int i = 0; i < n; i++) {
			dp[i] = i;
			for (int j = 0; j <= i; j++) {
				if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
					p[j][i] = true;
					dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};

inline void test() {
	Solution solution;
	cout << solution.minCut("1") << endl;
}
