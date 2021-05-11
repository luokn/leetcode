#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(const vector<int>& numbers) {
        vector<bool> vec(numbers.size(), false);
        for (const int value : numbers) {
            if (value > 0 && value <= numbers.size()) vec[value - 1] = true;
        }
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (!vec[i]) return i + 1;
        }
        return static_cast<int>(numbers.size()) + 1;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.firstMissingPositive({2, 3, 4, 5, -1});
}
