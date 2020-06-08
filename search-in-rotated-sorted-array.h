#pragma once
#include "leetcode.h"

using namespace std;

class Solution {
  public:
    int search(vector<int> &numbers, const int target) {
        if (numbers.empty())
            return -1;
        auto index = -1;
        search(numbers, target, 0, numbers.size() - 1, index);
        return index;
    }

    void search(vector<int> &numbers, int target, int start, int end,
                int &out) {
        switch (end - start) {
        case 0:
            if (numbers[start] == target)
                out = start;
            return;
        case 1:
            if (numbers[start] == target)
                out = start;
            else if (numbers[end] == target)
                out = end;
            return;
        default:
            const auto mid = (end + start) / 2;
            if (numbers[mid] == target) {
                out = mid;
            } else if (numbers[start] < numbers[mid]) {
                if (target >= numbers[start] && target <= numbers[mid])
                    binary_search(numbers, target, start, mid - 1, out);
                else
                    search(numbers, target, mid + 1, end, out);
            } else if (numbers[mid] < numbers[end]) {
                if (target >= numbers[mid] && target <= numbers[end])
                    binary_search(numbers, target, mid + 1, end, out);
                else
                    search(numbers, target, start, mid - 1, out);
            }
        }
    }

    void binary_search(vector<int> &numbers, const int target, const int start,
                       const int end, int &out) {
        switch (end - start) {
        case 0:
            if (numbers[start] == target)
                out = start;
            return;
        case 1:
            if (numbers[start] == target)
                out = start;
            else if (numbers[end] == target)
                out = end;
            return;
        default:
            const auto mid = (start + end) / 2;
            if (numbers[mid] == target)
                out = mid;
            else if (numbers[mid] < target)
                binary_search(numbers, target, mid + 1, end, out);
            else
                binary_search(numbers, target, start, mid - 1, out);
        }
    }
};

inline void test() {
    Solution solution;
    vector<int> vec{4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(vec, 0);
}
