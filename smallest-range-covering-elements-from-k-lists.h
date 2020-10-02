// https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/
#pragma once

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(const vector<vector<int>>& nums) {
        const int                       N    = nums.size();
        int                             xmin = INT_MAX, xmax = INT_MIN;
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < N; ++i) {
            for (auto&& x : nums[i]) {
                indices[x].push_back(i);
                xmin = min(xmin, x);
                xmax = max(xmax, x);
            }
        }

        vector<int> freq(N);
        int         inside = 0;
        int         l = xmin, r = xmin - 1;
        int         best_l = xmin, best_r = xmax;

        while (r < xmax) {
            ++r;
            if (indices.count(r)) {
                for (auto&& x : indices[r]) {
                    ++freq[x];
                    if (freq[x] == 1) ++inside;
                }
                while (inside == N) {
                    if (r - l < best_r - best_l) {
                        best_l = l;
                        best_r = r;
                    }
                    if (indices.count(l)) {
                        for (auto&& x : indices[l]) {
                            --freq[x];
                            if (freq[x] == 0) --inside;
                        }
                    }
                    ++l;
                }
            }
        }

        return {best_l, best_r};
    }
};

ostream& operator<<(ostream& os, const vector<int>& vec) {
    for (auto&& i : vec) {
        cout << i << " ";
    }
    return os;
}

inline void test() {
    Solution solution;
    cout << solution.smallestRange({{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}}) << endl;
}