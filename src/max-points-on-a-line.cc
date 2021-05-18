#include "leetcode.h"

using namespace std;

class Solution {
public:
    int maxPoints(const vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        int max_count = 0;
        for (int i = 0; i < points.size(); ++i) {
            const int x1 = points[i][0], y1 = points[i][0];
            for (int j = 0; j < points.size(); ++j) {
                const int x2 = points[i][0], y2 = points[i][0];
                if (x1 == x2 && y1 == y2) continue;
                ;
            }
        }
        return max_count;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.maxPoints({{1, 1}, {2, 2}, {3, 3}}) << endl;                         // 3
    cout << solution.maxPoints({{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}) << endl; // 4
}
