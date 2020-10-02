#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const char* chars = s.c_str();
        switch (s.length()) {
            case 0:
            case 1:
                return s;
            case 2:
                return chars[0] == chars[1] ? s : s.substr(0, 1);
            default: {
                int first = 0, max_len = 0, l = 0, r = 0;
                for (size_t axis = 0; axis < s.length() - 1; ++axis) {
                    l = axis;
                    r = axis + 1;
                    while (l >= 0 && r < s.length() && chars[l] == chars[r]) {
                        --l;
                        ++r;
                    }
                    if (r - l - 1 > max_len) {
                        first   = l + 1;
                        max_len = r - l - 1;
                    }

                    if (axis > 0) {
                        l = axis - 1;
                        r = axis + 1;
                        while (l >= 0 && r < s.length() && chars[l] == chars[r]) {
                            --l;
                            ++r;
                        }
                        if (r - l - 1 > max_len) {
                            first   = l + 1;
                            max_len = r - l - 1;
                        }
                    }
                }
                return s.substr(first, max_len);
            }
        }
    }
};

inline void test() {
    Solution     solution;
    const string s = solution.longestPalindrome("babad");
    cout << s << endl;
}
