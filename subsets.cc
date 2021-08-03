#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &numbers) {
        vector<vector<int>> res;
        vector<int>         t;
        if (numbers.size() < 1) {
            res.push_back(t);
            return res;
        }
        t.push_back(numbers[0]);
        res.push_back(t);
        for (int i = 1; i < numbers.size(); i++) {
            int n = res.size();
            for (int k = 0; k < n; k++) { res.push_back(res[k]); }
            for (int j = 0; j < res.size() / 2; j++) { res[j].push_back(numbers[i]); }
            vector<int> tem;
            tem.push_back(numbers[i]);
            res.push_back(tem);
        }
        vector<int> tem;
        res.push_back(tem);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution    solution;
    vector<int> vec{1, 2, 3, 4};
    const auto  res = solution.subsets(vec);
    for (const auto &vector : res) {
        cout << vector << endl;
        cout << endl;
    }
}
