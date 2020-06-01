#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
	int jump(const vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		vector<int> dp(nums.size(), 0);
		dp[nums.size() - 1] = -1;
		auto start = 1;
		for (auto i = 0; i < nums.size() && start < nums.size(); i++) {
			if (nums[i] == 0)
				continue;
			const auto end = min(i + nums[i], static_cast<int>(nums.size() - 1));
			while (start <= end) {
				dp[start] = dp[i] + 1;
				++start;
				system("cls");
				cout << dp << endl;
			}
		}
		return dp[nums.size() - 1];
	}
};

inline void test() {
	Solution solution;
	cout << solution.jump({ 4,2,3,1,2,6,1,5,1,1,0,1,2,0,0,0,0,0 }) << endl;
}
