#include "leetcode.h"

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();
        int max_len = 0, len = 0, cur = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            for (size_t j = cur; j < i; ++j) {
                if (s[j] == s[i]) {
                    cur = j + 1;
                    break;
                }
            }
            len = i - cur + 1;
            if (len > max_len) { max_len = len; }
        }
        return max_len;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
}
