/*
 * https://leetcode-cn.com/problems/number-of-digit-one/
 */

#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int countDigitOne(const int n) {
        int64_t counter = 0;
        for (int64_t x = 1, div = 10; x <= n; x = div, div *= 10) {
            counter += n / div * x + min(max(n % div - x + 1, 0i64), x);
        }
        return counter;
    }
};

inline void test() {
    Solution solution;
    cout << solution.countDigitOne(13) << endl; // 6 = 4 + 2
    cout << solution.countDigitOne(41) << endl; // 15 = 10 + 5
    cout << solution.countDigitOne(33) << endl; // 14 = 10 + 4

    cout << solution.countDigitOne(211) << endl; // 144 = 100 + 22 + 22
    cout << solution.countDigitOne(594) << endl; // 220 = 100 + 55 + 60
    cout << solution.countDigitOne(185) << endl; // 125 = 100 + 16 +
}
