// https://leetcode-cn.com/problems/4-sum/

#pragma once

#include "leetcode.h"

using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        size_t counter = 0;
        map<int, int> map;
        for (const int a : A) { for (const auto b : B) { ++map[a + b]; } }
        for (const int c : C) { for (const auto d : D) { counter += map[-c - d]; } }
        return counter;
    }
};

inline void test() {
    Solution solution;
    vector<int> a{ 0, 1, -1 };
    vector<int> b{ -1, 1, 0 };
    vector<int> c{ 0, 0, 1 };
    vector<int> d{ -1, 1, 1 };
    std::cout << solution.fourSumCount(a, b, c, d) << endl;
}
