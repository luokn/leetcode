/*
 * https://leetcode-cn.com/problems/basic-calculator/
 */

#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
  public:
    int calculate(const string &str) {
        size_t idx = 0;
        return calculate(str, idx);
    }

    int calculate(const string &str, size_t &idx) const {
        int64_t res = 0;
        for (char opr = '+'; idx < str.size();) {
            switch (str[idx]) {
            case '+':
            case '-':
                opr = str[idx++];
                break;
            case '(':
                ++idx;
                res += opr == '+' ? calculate(str, idx) : -calculate(str, idx);
                break;
            case ')':
                ++idx;
                return res;
            default:
                if (isdigit(str[idx])) {
                    int64_t x = str[idx++] - '0';
                    while (idx < str.size() && isdigit(str[idx])) {
                        x = x * 10 + str[idx++] - '0';
                    }
                    res += opr == '+' ? x : -x;
                } else {
                    ++idx;
                }
                break;
            }
        }
        return res;
    }
};

inline void test() {
    Solution solution;
    cout << solution.calculate("1-(2-(3-2))") << endl;         // 0
    cout << solution.calculate("1 + 1") << endl;               // 2
    cout << solution.calculate(" 2-1 + 2 ") << endl;           // 3
    cout << solution.calculate("(1+(4+5+2)-3)+(6+8)") << endl; // 23
}
