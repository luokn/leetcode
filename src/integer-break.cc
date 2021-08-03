#include <iostream>

using namespace std;

class Solution {
  public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        switch (n % 3) {
            case 0: return quick_pow(3, n / 3);
            case 1: return quick_pow(3, n / 3 - 1) << 2;
            case 2: return quick_pow(3, n / 3 - 1) * 6;
            default: return 0;
        }
    }

    int64_t quick_pow(int64_t x, int64_t p) {
        int64_t res = 1;
        while (p) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    for (int i = 2; i < 12; i++) { cout << solution.integerBreak(i) << endl; }
}