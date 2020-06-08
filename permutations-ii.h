#pragma once
#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    static vector<vector<int>> permute_unique(vector<int> &numbers) {
        std::sort(numbers.begin(), numbers.end());
        vector<vector<int>> res;
        permute_unique(numbers, 0, res);
        return res;
    }

    static void permute_unique(vector<int> &numbers, const size_t hierarchy,
                               vector<vector<int>> &res) {
        if (hierarchy + 1 == numbers.size()) {
            res.push_back(numbers);
        } else {
            for (size_t i = hierarchy; i < numbers.size(); ++i) {
                if (i != hierarchy && numbers[i] == numbers[hierarchy]) {
                    continue;
                }
                std::swap(numbers[i], numbers[hierarchy]);
                permute_unique(numbers, i + 1, res);
            }
        }
    }
};

inline void test() {
    vector<int> v{2, 2, 1, 1};
    cout << Solution::permute_unique(v) << endl;
}
