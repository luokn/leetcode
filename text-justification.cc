#pragma once
#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, const int max_width) {
        vector<string> lines;
        string         line;
        line.reserve(max_width);
        for (int pos = 0; pos < words.size();) {
            line            = words[pos];
            int n_intervals = 0, n_chars = words[pos].size(), line_cur = ++pos;
            while (pos < words.size()) {
                if (n_chars + n_intervals + words[pos].size() >= max_width) break;
                n_chars += words[pos++].size();
                ++n_intervals;
            }
            if (pos >= words.size()) {
                for (int _ = 0; _ < n_intervals; ++_, ++line_cur) {
                    line += " ";
                    line += words[line_cur];
                }
                line.resize(max_width, ' ');
                lines.push_back(line);
                return lines;
            }
            if (n_intervals == 0) {
                line.resize(max_width, ' ');
            } else {
                const int count = (max_width - n_chars) / n_intervals;
                const int rest  = (max_width - n_chars) % n_intervals;
                for (int _ = 0; _ < rest; ++_, ++line_cur) {
                    line += string(count + 1, ' ');
                    line += words[line_cur];
                }
                for (int _ = 0; _ < n_intervals - rest; ++_, ++line_cur) {
                    line += string(count, ' ');
                    line += words[line_cur];
                }
            }

            lines.push_back(line);
        }
        return lines;
    }
};

int main(int argc, char const *argv[]) {
    vector<string> words1{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words2{"What", "must", "be", "acknowledgment", "shall", "be"};
    Solution       solution;

    for (const auto &it : solution.fullJustify(words1, 16)) { cout << "\"" << it << "\"" << endl; }
    cout << endl;
    for (const auto &it : solution.fullJustify(words2, 16)) { cout << "\"" << it << "\"" << endl; }
}
