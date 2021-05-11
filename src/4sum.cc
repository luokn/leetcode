// https://leetcode-cn.com/problems/4-sum/
#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int           counter = 0;
        map<int, int> sum_map;
        for (const auto a : A) {
            for (const auto b : B) {
                ++sum_map[a + b];
            }
        }
        for (const auto c : C) {
            for (const auto d : D) {
                counter += sum_map[-(c + d)];
            }
        }
        return counter;
    }
};

int main(int argc, char const* argv[]) {
    Solution    solution;
    vector<int> a{0, 1, -1};
    vector<int> b{-1, 1, 0};
    vector<int> c{0, 0, 1};
    vector<int> d{-1, 1, 1};
    cout << solution.fourSumCount(a, b, c, d) << endl;
}
