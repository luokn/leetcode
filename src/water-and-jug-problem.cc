#include "./leetcode.h"

using namespace std;

class Solution {
public:
    bool canMeasureWater(const uint32_t size_1, const uint32_t size_2, const uint32_t target) {
        if (target == 0) return true;
        if (size_1 + size_2 < target) return false;
        if (size_1 == 0) return target == size_2;
        if (size_2 == 0) return target == size_1;

        return target % gcd(size_1, size_2) == 0;
    }

    int gcd(uint32_t x, uint32_t y) {
        if (x == y) return x;
        uint32_t val = x > y ? (x - y) : (y - x);
        while (val != y) {
            if (y > val) {
                x = y;
                y = val;
            } else {
                x = val;
            }
            val = x - y;
        }
        return val;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    assert(solution.canMeasureWater(3, 5, 4));
    assert(!solution.canMeasureWater(2, 6, 5));
    assert(!solution.canMeasureWater(1, 1, 12));
    cout << "OK" << endl;
}
