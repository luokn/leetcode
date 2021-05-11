// https://leetcode-cn.com/problems/is-subsequence/

#pragma once

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        const auto s_len = s.length(), t_len = t.length();
        if (s_len == 0) return true;
        if (s_len > t_len) return false;
        for (size_t i = 0, j = 0; j < t_len; ++j) {
            if (s[i] == t[j] && ++i == s_len) return true;
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.isSubsequence("abc", "ahbgdc") << endl; // True
    cout << solution.isSubsequence("axc", "ahbgdc") << endl; // Falsea
}