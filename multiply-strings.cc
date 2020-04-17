#include "leetcode.h"

using namespace std;

class Solution {
public:
	string multiply(const string num1, const string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		const int len = num1.size() + num2.size();
		const auto buf = new char[len + 1]{ 0 };
		const auto cs1 = num1.c_str();
		const auto cs2 = num2.c_str();

		for (int x = num1.size() - 1; x >= 0; --x) {
			char temp = 0;
			const char left = cs1[x] - '0';
			for (int y = num2.size() - 1; y >= 0; --y) {
				auto& right = buf[x + y + 1];
				right += left * (cs2[y] - '0') + temp;
				temp = right / 10;
				right %= 10;
			}
			if (temp)
				buf[x] = temp;
		}

		int ptr = 0;
		while (ptr < len && *(buf + ptr) == 0)
			++ptr;
		for (auto i = ptr; i < len; ++i)
			buf[i] += '0';
		string str = buf + ptr;
		delete[] buf;
		return str;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.multiply("10", "10");
}


