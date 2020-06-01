#include "leetcode.h"

using namespace  std;
using namespace utils;

class Solution {
public:
    static vector<vector<int>> permute_unique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permute_unique(nums, 0, res);
        return res;
    }

    static void permute_unique(vector<int>& nums, const int idx, vector<vector<int>>& res) {
        if (idx == nums.size() - 1) {
            res.push_back(nums);
        } else {
            for (int i = idx; i < nums.size(); ++i) {
                if (i != idx && nums[i] == nums[idx])
                    continue;
                std::swap(nums[i], nums[idx]);
                permute_unique(nums, i + 1, res);
            }
        }
    }
};

inline void test() {
    vector<int> v{ 2, 2, 1, 1 };
    cout << Solution::permute_unique(v) << endl;
}
