#include "leetcode.h"

using namespace std;

class Solution {
  public:
    int shortestSubarray(const vector<int> &A, int K) {
        vector<int64_t> P(A.size() + 1, 0);
        for (size_t i = 0; i < A.size(); i++) { P[i + 1] = P[i] + A[i]; }
        int64_t        len = P.size();
        deque<int64_t> deq;
        for (int64_t i = 0; i < P.size(); i++) {
            while (!deq.empty() && P[i] <= P[deq.back()]) { deq.pop_back(); }
            while (!deq.empty() && P[i] >= K + P[deq.front()]) {
                len = std::min(len, i - deq.front());
                deq.pop_front();
            }
            deq.push_back(i);
        }
        return len == P.size() ? -1 : len;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // cout << solution.shortestSubarray({2, -1, 2}, 3) << endl;
    // cout << solution.shortestSubarray({1, 2}, 4) << endl;
    // cout << solution.shortestSubarray({77, 19, 35, 10, -14}, 19) << endl;
    cout << solution.shortestSubarray({84, -37, 32, 40, 95}, 167) << endl;
}