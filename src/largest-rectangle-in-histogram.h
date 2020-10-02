#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stack;
        int        max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                const int top = stack.top();
                stack.pop();
                const int width = stack.empty() ? i : (i - stack.top() - 1);
                max_area        = max(max_area, heights[top] * width);
            }
            stack.push(i);
        }
        return max_area;
    }
};

inline void test() {
    Solution    solution;
    vector<int> vec{2, 1, 5, 6, 2, 3};
    cout << solution.largestRectangleArea(vec);
}
