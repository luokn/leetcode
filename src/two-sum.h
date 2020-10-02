// https://leetcode-cn.com/problems/two-sum/

#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (auto iter = mp.find(nums[i]); iter != mp.end()) {
                return {iter->second, i};
            }
            mp[target - nums[i]] = i;
        }

        return {};
    }
};

inline ostream& operator<<(ostream& os, const vector<int>& nums) {
    for (auto&& num : nums) {
        os << num << " ";
    }
    return os;
}

inline void test() {
    Solution solution;
    cout << solution.twoSum({2, 7, 11, 15}, 9) << endl;
}