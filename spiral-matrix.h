#pragma once
#include "leetcode.h"

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty())
			return res;
		res.reserve(matrix.size() * matrix[0].size());
		int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
		auto cur = 0;
		while (bottom >= top || right >= left) {
			if (bottom >= top) {
				for (cur = left; cur <= right; ++cur)
					res.push_back(matrix[top][cur]);
			}
			++top;
			if (right >= left) {
				for (cur = top; cur <= bottom; ++cur)
					res.push_back(matrix[cur][right]);
			}
			--right;
			if (bottom >= top) {
				for (cur = right; cur >= left; --cur)
					res.push_back(matrix[bottom][cur]);
			}
			--bottom;
			if (right >= left) {
				for (cur = bottom; cur >= top; --cur)
					res.push_back(matrix[cur][left]);
			}
			++left;
		}
		return res;
	}
};

inline void test() {
	Solution solution;
	vector<vector<int>> matrix0{
			{1, 1, 1, 1, 1},
			{2, 2, 2, 2, 2},
			{3, 3, 3, 3, 3},
			{4, 4, 4, 4, 4}
	};
    vector<vector<int>> matrix1{ {1},{2},{3},{4} };

	for (auto&& value : solution.spiralOrder(matrix0)) {
		cout << value << " ";
	}
	cout << endl;
	for (auto&& value : solution.spiralOrder(matrix1)) {
		cout << value << " ";
	}
}
