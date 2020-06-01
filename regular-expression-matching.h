#include "leetcode.h"

using namespace std;

void print_mem(const vector<vector<bool>>& mem) {
	system("cls");
	stringstream ss;
	for (auto&& vector : mem) {
		for (auto&& value : vector) {
			ss << (value ? "O " : "X ");
		}
		ss << endl;
	}
	cout << ss.rdbuf();
}

class Solution {
public:
	bool isMatch(const string& src, const string& reg) {
		vector<vector<bool>> memo(src.length() + 1);
		for (auto& vec : memo) {
			vec.resize(reg.length() + 1);
		}
		memo[0][0] = true;
		for (auto i = 1; i < reg.length(); ++i) {
			if (reg[i] == '*' && memo[0][i - 1]) {
				memo[0][i + 1] = true;
			}
		}
		print_mem(memo);
		for (auto i = 0; i < src.length(); ++i) {
			for (auto j = 0; j < reg.length(); ++j) {
				if (reg[j] == src[i] || reg[j] == '.') {
					memo[i + 1][j + 1] = memo[i][j];
				} else if (reg[j] == '*') {
					if (reg[j - 1] != src[i]) {
						memo[i + 1][j + 1] = memo[i + 1][j - 1];
					}
					if (reg[j - 1] == src[i] || reg[j - 1] == '.') {
						memo[i + 1][j + 1] = (memo[i][j + 1] || memo[i + 1][j] || memo[i + 1][j - 1]);
					}
				}
				print_mem(memo);
			}
		}
		return memo[src.length()][reg.length()];
	}

};

inline void test() {
	Solution solution;
	cout << (solution.isMatch("abcde", "ab.*e") ? "Ok" : "Error");
}

