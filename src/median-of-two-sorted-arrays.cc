#include "leetcode.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& numbers1, vector<int>& numbers2) {
        const auto size = numbers1.size() + numbers2.size();
        auto       it1  = numbers1.begin();
        auto       it2  = numbers2.begin();
        int        v1 = 0, v2 = 0;
        for (size_t i = 0; i <= size / 2; i++) {
            if (it1 == numbers1.end())
                v1 = *it2++;
            else if (it2 == numbers2.end())
                v1 = *it1++;
            else if (*it1 < *it2)
                v1 = *it1++;
            else
                v1 = *it2++;
            if (size / 2 - 1 == i) v2 = v1;
        }
        return size % 2 == 0 ? (v1 + v2) / 2.0 : v1;
    }
};

int main(int argc, char const* argv[]) {
    Solution    solution;
    vector<int> a{1, 3, 5, 7, 9};
    vector<int> b{5, 7, 9};

    const double res = solution.findMedianSortedArrays(a, b);
    cout << res << endl;
}
