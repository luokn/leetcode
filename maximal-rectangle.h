#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix.front().empty())
			return 0;
		const int m = matrix.size(), n = matrix.front().size();
		auto max_area = 0;
        deque<int> deq(n + 1);
        stack<int> stck(deq);
		vector<int> heights(n + 1);
		for (auto i = 0; i < m; ++i) {
			for (auto j = 0; j < n; ++j) {
				if (matrix[i][j] == '0')
					heights[j] = 0;
				else
					++heights[j];
			}
            deq.clear();
			row_max_area(heights, stck, max_area);
		}
		return max_area;
	}

	void row_max_area(const vector<int>& heights, stack<int>& stk, int& out) const {
		for (auto i = 0; i < heights.size(); ++i) {
			while (!stk.empty() && heights[stk.top()] > heights[i]) {
				const auto top = stk.top();
				stk.pop();
				const auto area = heights[top] * (stk.empty() ? i : (i - stk.top() - 1));
				out = std::max(out, area);
			}
			stk.push(i);
		}
	}
};

inline void test() {
	Solution solution;
	vector<vector<char>> mat{
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','1','1','1'},
		{'1','0','0','1','0'}
	};
	cout << solution.maximalRectangle(mat);
}
