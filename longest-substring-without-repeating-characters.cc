#include "leetcode.h"

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() < 2)
			return s.length();
		auto max_len = 0;
		auto len = 0;
		auto cur = 0;
		for (auto i = 0; i < s.length(); ++i) {
			for (auto j = cur; j < i; ++j) {
				if (s[j] == s[i]) {
					cur = j + 1;
					break;
				}
			}
			len = i - cur + 1;
			if (len > max_len) {
				max_len = len;
			}
		}
		return max_len;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
}

