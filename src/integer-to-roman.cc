#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int          values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string       strs[]   = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        stringstream res;
        for (size_t i = 0; i < 13; i++) {
            while (num >= values[i]) {
                num -= values[i];
                res << strs[i];
            }
        }
        return res.str();
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.intToRoman(3) << endl;
}
