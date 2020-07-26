// https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu/

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minJump(const vector<int> &jump) {
        const auto M = jump.size();
        vector<int> dp(M, 0);
        for (int i = M - 1; i >= 0; --i) {
            dp[i] = i + jump[i] >= M ? 1 : (dp[i + jump[i]] + 1);
            for (int j = i + 1; j < M && j < i + jump[i] && dp[j] > dp[i];
                 ++j) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[0];
    }
};

inline void test() {
    Solution solution;
    cout << solution.minJump({2, 5, 1, 1, 1, 1}) << endl;
}