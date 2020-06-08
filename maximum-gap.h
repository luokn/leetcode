/*
 * https://leetcode-cn.com/problems/maximum-gap/
 */

#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
  public:
    struct Bucket {
        bool used = false;
        int min_val = numeric_limits<int>::max();
        int max_val = numeric_limits<int>::min();
    };

    int maximumGap(vector<int> &numbers) {
        if (numbers.size() < 2)
            return 0;
        const auto min_max = minmax_element(numbers.cbegin(), numbers.cend());
        const int min_val = *min_max.first, max_val = *min_max.second;
        const int bucket_size =
            max(1, (max_val - min_val) / static_cast<int>(numbers.size()));
        vector<Bucket> buckets((max_val - min_val) / bucket_size + 1);
        for (const auto &n : numbers) {
            auto &bucket = buckets[(n - min_val) / bucket_size];
            bucket = {true, min(n, bucket.min_val), max(n, bucket.max_val)};
        }
        int max_gap = 0, prev = min_val;
        for (const auto &bucket : buckets) {
            if (bucket.used) {
                max_gap = max(max_gap, bucket.min_val - prev);
                prev = bucket.max_val;
            }
        }
        return max_gap;
    }
};

inline void test() {
    Solution solution;
    vector<int> numbers{3, 6, 9, 1};
    cout << solution.maximumGap(numbers);
}
