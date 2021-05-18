#include "leetcode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        for (auto& vector : res) vector.resize(n);
        auto x = 0, y = n - 1, cur = 0;
        n = 0;
        while (y > x) {
            for (cur = x; cur <= y; ++cur) res[x][cur] = ++n;
            for (cur = x + 1; cur <= y; ++cur) res[cur][y] = ++n;
            for (cur = y - 1; cur >= x; --cur) res[y][cur] = ++n;
            for (cur = y - 1; cur >= x + 1; --cur) res[cur][x] = ++n;
            ++x;
            --y;
        }
        if (y == x + 1) {
            res[x][x] = ++n;
            res[x][y] = ++n;
            res[y][y] = ++n;
            res[y][x] = ++n;
        } else if (x == y) {
            res[x][x] = ++n;
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    auto     matrix = solution.generateMatrix(10);
    for (auto&& vector : matrix) {
        for (auto&& value : vector) {
            cout << setiosflags(ios::left) << setw(5) << value;
        }
        cout << endl;
    }
}
