#pragma once
#include "leetcode.h"

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        vector<int> buffer(m, 1);
        for (auto i = m - 2; i >= 0; i--)
            for (auto j = n - 2; j >= 0; j--)
                buffer[j] += buffer[j + 1];
        return buffer[0];
    }
};

inline void test() {
    Solution solution;
    for (auto i = 2; i < 10; ++i) {
        for (auto j = 1; j < i; ++j) {
            cout << setiosflags(ios::left) << setw(5)
                 << solution.uniquePaths(i, j);
        }
        cout << endl;
    }
}
