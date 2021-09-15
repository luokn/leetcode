#include "leetcode.h"

using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        res.reserve(matrix.size() * matrix[0].size());
        int64_t top = 0, lft = 0, bot = matrix.size() - 1, rgt = matrix[0].size() - 1;
        int64_t cur = 0;
        while (bot >= top || rgt >= lft) {
            if (bot >= top) {
                for (cur = lft; cur <= rgt; ++cur) {
                    res.push_back(matrix[top][cur]);
                }
            }
            ++top;
            if (rgt >= lft) {
                for (cur = top; cur <= bot; ++cur) {
                    res.push_back(matrix[cur][rgt]);
                }
            }
            --rgt;
            if (bot >= top) {
                for (cur = rgt; cur >= lft; --cur) {
                    res.push_back(matrix[bot][cur]);
                }
            }
            --bot;
            if (rgt >= lft) {
                for (cur = bot; cur >= top; --cur) {
                    res.push_back(matrix[cur][lft]);
                }
            }
            ++lft;
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution            solution;
    vector<vector<int>> matrix0{
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4},
    };
    vector<vector<int>> matrix1{
        {1},
        {2},
        {3},
        {4},
    };

    for (auto&& value : solution.spiralOrder(matrix0)) {
        cout << value << " ";
    }
    cout << endl;
    for (auto&& value : solution.spiralOrder(matrix1)) {
        cout << value << " ";
    }
}
