#include "leetcode.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		switch (nums.size()) {
		case 0:
			return vector<vector<int>>();
		case 1:
			return vector<vector<int>>{nums};
		case 2:
			return vector<vector<int>>{nums, vector<int>{nums[1], nums[0]}};
		default:
			vector<vector<int >> res;
			uint32_t count = 1;
			for (uint32_t i = 2; i <= nums.size(); ++i)
				count *= i;
			res.reserve(count);
			permute_recursion(nums, 0, res);
			return res;
		}
	}

	void permute_recursion(vector<int>& nums, const int idx, vector<vector<int>>& out) {
		if (idx == nums.size() - 1)
			out.push_back(nums);
		else {
			permute_recursion(nums, idx + 1, out);
			for (auto x = idx + 1; x < nums.size(); ++x) {
				std::swap(nums[x], nums[idx]);
				permute_recursion(nums, idx + 1, out);
				std::swap(nums[x], nums[idx]);
			}
		}
	}
};

inline void test() {
	Solution solution;
	vector<int> nums{ 1, 2, 3 };
	auto res = solution.permute(nums);
	for (auto&& vector : res) {
		for (auto&& value : vector) {
			cout << value << " ";
		}
		cout << endl;
	}
}
