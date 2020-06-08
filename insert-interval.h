/*
 * https://leetcode-cn.com/problems/insert-interval/
 */

#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &new_interval) {
        vector<vector<int>> new_intervals;
        size_t idx = 0;
        while (idx < intervals.size() && new_interval[0] > intervals[idx][0]) {
            new_intervals.push_back(intervals[idx++]);
        }
        if (new_intervals.empty() || new_intervals.back()[1] < new_interval[0])
            new_intervals.push_back(new_interval);
        else
            new_intervals.back()[1] =
                max(new_intervals.back()[1], new_interval[1]);
        while (idx < intervals.size()) {
            if (new_intervals.back()[1] < intervals[idx][0])
                new_intervals.push_back(intervals[idx]);
            else
                new_intervals.back()[1] =
                    max(new_intervals.back()[1], intervals[idx][1]);
            ++idx;
        }
        return new_intervals;
    }
};

inline void test() {
    Solution solution;
    vector<vector<int>> intervals{{1, 3}, {6, 9}};
    vector<int> new_interval{2, 5};
    cout << solution.insert(intervals, new_interval);
}
