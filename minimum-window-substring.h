#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
  public:
    string minWindow(const string &str, const string &tar) {
        unordered_map<char, bool> map;
        for (auto ch : tar) {
            map[ch] = false;
        }
        auto m_width = INT32_MAX, m_l = 0, m_r = 0, counter = 0, cur = 0;
        deque<int> dq;
        for (; cur < str.length() && dq.size() < tar.length(); ++cur) {
            if (auto it = map.find(str[cur]); it != map.end()) {
                dq.push_front(cur);
                if (!it->second) {
                    it->second = true;
                    ++counter;
                }
            }
        }

        if (dq.size() < tar.size()) {
            return "";
        }

        if (counter == tar.size()) {
            m_r = dq.front() + 1;
            m_l = dq.back();
            m_width = m_r - m_l;
        }

        for (; cur < str.length(); ++cur) {
            if (auto it = map.find(str[cur]); it != map.end()) {
                dq.push_front(cur);
                const auto b = dq.back();
                if (map[b]) {
                    --counter;
                    map[b] = false;
                }
                dq.pop_back();

                if (!it->second) {
                    it->second = true;
                    ++counter;
                }

                if (counter == tar.size()) {
                    const auto width = dq.front() - dq.back() + 1;
                    if (width < m_width) {
                        m_width = width;
                        m_r = dq.front() + 1;
                        m_l = dq.back();
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
