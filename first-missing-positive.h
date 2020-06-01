#include "leetcode.h"

using namespace std;

class Solution {
public:
	int firstMissingPositive(const vector<int>& numbers) {
		vector<bool> vec(numbers.size(), false);
		for (const auto& value : numbers) {
			if (value > 0 && value <= numbers.size()) {
				vec[value - 1] = true;
			}
		}
		for (auto i = 0; i < numbers.size(); ++i) {
			if (!vec[i])
				return i + 1;
		}
		return numbers.size() + 1;
	}
};

inline void test() {
	Solution solution;
	cout << solution.firstMissingPositive({ 2,3,4,5,-1 });
}


