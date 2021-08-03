#include "leetcode.h"

using namespace std;

class Solution {
  public:
    vector<int> grayCode(const int n) {
        vector<int>    res;
        const uint32_t len = 1 << n;
        res.reserve(len);
        for (uint32_t i = 0; i < len; ++i) res.emplace_back(i ^ (i >> 1));
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution   solution;
    const auto res = solution.grayCode(8);
    for_each(res.cbegin(), res.cend(), [](const int &v) { cout << bitset<8>(v) << endl; });
}
