#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
    int jump(const vector<int>& numbers) {
        if (numbers.size() < 2) return 0;
        vector<int> dp(numbers.size(), 0);
        dp[numbers.size() - 1] = -1;
        size_t start           = 1;
        for (size_t i = 0; i < numbers.size() && start < numbers.size(); i++) {
            if (numbers[i] == 0) continue;
            const size_t end = min(i + numbers[i], numbers.size() - 1);
            while (start <= end) {
                dp[start++] = dp[i] + 1;
                // system("cls");
                // cout << dp << endl;
            }
        }
        return dp[numbers.size() - 1];
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.jump({4, 2, 3, 1, 2, 6, 1, 5, 1, 1, 0, 1, 2, 0, 0, 0, 0, 0}) << endl;
}
