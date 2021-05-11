// https://leetcode-cn.com/problems/divisor-game/

#pragma once

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) { return !(N & 1); }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << (solution.divisorGame(2) ? "True" : "False") << endl;
}