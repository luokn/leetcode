#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) return 0;
        const size_t M = matrix.size(), N = matrix.front().size();
        auto         max_area = 0;
        deque<int>   dq(N + 1);
        stack<int>   stk(dq);
        vector<int>  heights(N + 1);
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    ++heights[j];
                }
            }
            dq.clear();
            row_max_area(heights, stk, max_area);
        }
        return max_area;
    }

    void row_max_area(const vector<int>& hts, stack<int>& stk, int& out) const {
        for (size_t i = 0; i < hts.size(); ++i) {
            while (!stk.empty() && hts[stk.top()] > hts[i]) {
                const int top = stk.top();
                stk.pop();
                const int area = hts[top] * (stk.empty() ? i : (i - stk.top() - 1));
                out            = std::max(out, area);
            }
            stk.push(i);
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution             solution;
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    cout << solution.maximalRectangle(matrix);
}
