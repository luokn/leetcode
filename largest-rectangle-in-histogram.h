#include "leetcode.h"

using namespace std;

class Solution {
public:
	int LargestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		stack<int> stack;
		auto max_area = 0;
		for (auto i = 0; i < heights.size(); i++) {
			while (!stack.empty() && heights[i] < heights[stack.top()]) {
				const auto top = stack.top();
				stack.pop();
				const auto width = stack.empty() ? i : (i - stack.top() - 1);
				max_area = max(max_area, heights[top] * width);
			}
			stack.push(i);
		}
		return max_area;
	}
};

inline void test() {
	Solution solution;
	vector<int> vec{ 2, 1, 5, 6, 2, 3 };
	cout << solution.LargestRectangleArea(vec);
}

