#include "leetcode.h"

using namespace std;

class Solution {
public:
    string multiply(const string n1, const string n2) {
        if (n1 == "0" || n2 == "0") return "0";
        const size_t len = n1.size() + n2.size();
        char*        buf = new char[len + 1]{0};
        const string s1 = n1.c_str(), s2 = n2.c_str();

        for (int64_t x = n1.size() - 1; x >= 0; --x) {
            char       temp = 0;
            const char left = s1[x] - '0';
            for (int y = n2.size() - 1; y >= 0; --y) {
                auto& right = buf[x + y + 1];
                right += left * (s2[y] - '0') + temp;
                temp = right / 10;
                right %= 10;
            }
            if (temp) {
                buf[x] = temp;
            }
        }

        int ptr = 0;
        while (ptr < len && *(buf + ptr) == 0) ++ptr;
        for (auto i = ptr; i < len; ++i) buf[i] += '0';
        string str = buf + ptr;
        delete[] buf;
        return str;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    cout << solution.multiply("10", "10");
}
