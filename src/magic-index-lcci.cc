#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMagicIndex(const vector<int> &numbers) {
        for (int l = 0, r = numbers.size() - 1; l < r;) {
            int m = (l + r) >> 1;
            if (numbers[m] == m) return m;
            if (numbers[m] > m)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }

  private:
    int v_ = 1;
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.findMagicIndex({0, 2, 3, 4, 5}) << endl; // 0
    cout << solution.findMagicIndex({1, 1, 1}) << endl;       // 1
    cout << solution.findMagicIndex({-1, 2, 3}) << endl;      // 0
}