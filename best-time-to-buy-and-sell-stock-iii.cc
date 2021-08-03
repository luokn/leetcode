#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        auto fst_buy = numeric_limits<int>::min(), fst_sell = 0;
        auto sec_buy = numeric_limits<int>::min(), sec_sell = 0;
        for (const auto &price : prices) {
            fst_buy  = std::max(fst_buy, -price);
            fst_sell = std::max(fst_sell, fst_buy + price);
            sec_buy  = std::max(sec_buy, fst_sell - price);
            sec_sell = std::max(sec_sell, sec_buy + price);
        }
        return sec_sell;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> vec{1, 2, 3};
    Solution    solution;
    cout << solution.maxProfit(vec);
}
