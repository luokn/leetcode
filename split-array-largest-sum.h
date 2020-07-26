// https://leetcode-cn.com/problems/split-array-largest-sum/

#pragma once

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int splitArray(const vector<int> &nums, int m) {
        int64_t l = *max_element(nums.begin(), nums.end()),
                r = accumulate(nums.begin(), nums.end(), 0i64);
        while (l < r) {
            int64_t s = 0, c = 1;
            const int64_t mid = (l + r) >> 1;
            for (auto &&num : nums) {
                s += num;
                if (s > mid) {
                    ++c;
                    s = num;
                }
            }
            if (c > m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

inline void test() {
    Solution solution;
    cout << solution.splitArray({7, 2, 5, 10, 8}, 2) << endl; // 18
}