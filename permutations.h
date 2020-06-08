#pragma once
#include "leetcode.h"

using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int> &numbers) const {
        switch (numbers.size()) {
        case 0:
            return {};
        case 1:
            return {numbers};
        case 2:
            return {numbers, {numbers[1], numbers[0]}};
        default: {
            vector<vector<int>> res;
            uint64_t count = 1;
            for (size_t i = 2; i <= numbers.size(); ++i) {
                count *= i;
            }
            res.reserve(count);
            permute_recursion(numbers, 0, res);
            return res;
        }
        }
    }

    void permute_recursion(vector<int> &numbers, const size_t hierarchy,
                           vector<vector<int>> &out) const {
        if (hierarchy + 1 == numbers.size()) {
            out.emplace_back(numbers);
        } else {
            permute_recursion(numbers, hierarchy + 1, out);
            for (auto x = hierarchy + 1; x < numbers.size(); ++x) {
                std::swap(numbers[x], numbers[hierarchy]);
                permute_recursion(numbers, hierarchy + 1, out);
                std::swap(numbers[x], numbers[hierarchy]);
            }
        }
    }
};

inline void test() {
    Solution solution;
    vector<int> numbers{1, 2, 3};
    auto res = solution.permute(numbers);
    for (auto &&vector : res) {
        for (auto &&value : vector) {
            cout << value << " ";
        }
        cout << endl;
    }
}
