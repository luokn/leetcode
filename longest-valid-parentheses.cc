#include "leetcode.h"

using namespace std;

class Solution {
public:
	int longestValidParentheses(const string& s) {
		auto max_len = 0;
		auto ptr = 0;
		while (ptr < s.length()) {
			if (s[ptr] == ')') {
				++ptr;
				continue;
			}
			for (auto i = 0, flag = 0; ptr < s.length() && flag >= 0; ++i, ++ptr) {
				if (s[ptr] == '(')
					++flag;
				else
					--flag;
				if (flag == 0)
					max_len = std::max(max_len, i + 1);
			}
		}
		ptr = s.length() - 1;
		while (ptr >= 0) {
			if (s[ptr] == '(') {
				--ptr;
				continue;
			}
			for (auto i = 0, flag = 0; ptr >= 0 && flag >= 0; ++i, --ptr) {
				if (s[ptr] == ')')
					++flag;
				else
					--flag;
				if (flag == 0)
					max_len = std::max(max_len, i + 1);
			}
		}
		return max_len;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.longestValidParentheses("((()()(()((()") << endl;
}
