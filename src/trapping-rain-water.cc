#include "leetcode.h"

using namespace std;

class Solution {
public:
    int trap(const vector<int>& height) {
        if (height.empty()) return 0;
        auto max_val = numeric_limits<int>::min();
        auto max_idx = 0;
        for (auto i = 0; i < height.size(); ++i) {
            if (height[i] > max_val) {
                max_idx = i;
                max_val = height[i];
            }
        }

        int result = 0;

        for (auto cur = 0; cur < max_idx;) {
            if (height[cur]) {
                for (const auto left = cur++; cur <= max_idx && height[left] > height[cur]; ++cur)
                    result += height[left] - height[cur];
            } else {
                ++cur;
            }
        }

        for (auto cur = height.size() - 1; cur > max_idx;) {
            if (height[cur]) {
                for (const auto right = cur--; cur >= max_idx && height[right] > height[cur]; --cur)
                    result += height[right] - height[cur];
            } else {
                --cur;
            }
        }
        return result;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.trap({0, 1, 0, 2, 1, 0, 1, 2, 2, 1, 2, 1}) << endl;
}
