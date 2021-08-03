#include "./leetcode.h"

using namespace std;

class Solution {
  public:
    int maxArea(const vector<int> &height) {
        switch (height.size()) {
            case 0:
            case 1: return 0;
            case 2: return std::min(height[0], height[1]);
            default:
                int l = 0, r = static_cast<int>(height.size() - 1), h = 0, max_area = 0;
                while (l < r) {
                    if (height[l] < height[r]) {
                        h = height[l];
                        ++l;
                    } else {
                        h = height[r];
                        --r;
                    }
                    const auto area = h * (r - l + 1);
                    if (area > max_area) { max_area = area; }
                }
                return max_area;
        }
    }
};

int main(int argc, char const *argv[]) {
    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution    solution;
    std::cout << solution.maxArea(vec);
}
