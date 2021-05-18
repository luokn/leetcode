#include "leetcode.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& str) {
        int max_len = 0, idx = 0;
        while (idx < str.length()) {
            if (str[idx] == ')') {
                ++idx;
                continue;
            }
            for (size_t i = 0, flag = 0; idx < str.length() && flag >= 0; ++i, ++idx) {
                if (str[idx] == '(') {
                    ++flag;
                } else {
                    --flag;
                }
                if (flag == 0) {
                    max_len = std::max(max_len, static_cast<int>(i + 1));
                }
            }
        }
        idx = str.length() - 1;
        while (idx >= 0) {
            if (str[idx] == '(') {
                --idx;
                continue;
            }
            for (auto i = 0, flag = 0; idx >= 0 && flag >= 0; ++i, --idx) {
                if (str[idx] == ')')
                    ++flag;
                else
                    --flag;
                if (flag == 0) max_len = std::max(max_len, i + 1);
            }
        }
        return max_len;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.longestValidParentheses("((()()(()((()") << endl;
}
