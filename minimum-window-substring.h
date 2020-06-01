#include "leetcode.h"

using namespace std;

class Solution {
public:
	string minWindow(const string& str, const string& tar) {
		unordered_map<char, bool> map;
		for (auto ch : tar) { map[ch] = false; }
		auto m_width = INT32_MAX, m_l = 0, m_r = 0, counter = 0, cur = 0;
		deque<int> deque;
		for (; cur < str.length() && deque.size() < tar.length(); ++cur) {
			if (auto it = map.find(str[cur]); it != map.end()) {
				deque.push_front(cur);
				if (!it->second) {
					it->second = true;
					++counter;
				}
			}
		}

		if (deque.size() < tar.size()) {
			return "";
		}

		if (counter == tar.size()) {
			m_r = deque.front() + 1;
			m_l = deque.back();
			m_width = m_r - m_l;
		}

		for (; cur < str.length(); ++cur) {
			if (auto it = map.find(str[cur]); it != map.end()) {
				deque.push_front(cur);
				const auto b = deque.back();
				if (map[b]) {
					--counter;
					map[b] = false;
				}
				deque.pop_back();

				if (!it->second) {
					it->second = true;
					++counter;
				}

				if (counter == tar.size()) {
					const auto width = deque.front() - deque.back() + 1;
					if (width < m_width) {
						m_width = width;
						m_r = deque.front() + 1;
						m_l = deque.back();
					}
				}
			}
		}
		return m_r > m_l ? str.substr(m_l, m_r) : "";
	}
};


inline void test() {
	Solution solution;
	cout << solution.minWindow("aa", "aa");
}


