// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

#pragma once

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int minArray(const std::vector<int> &numbers) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            const int m = (r + l) >> 1;
            if (numbers[r] > numbers[m]) {
                r = m;
            } else if (numbers[r] < numbers[m]) {
                l = m + 1;
            } else {
                --r;
            }
        }
        return numbers[l];
    }
};

inline void test() {
    Solution solution;
    cout << solution.minArray({3, 4, 5, 1, 2}) << endl;
}