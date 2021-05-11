#pragma once
#include "leetcode.h"

using namespace std;

class Solution {
public:
    enum S { S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, F, A };

    S tb[11][6]{
        {S2, S4, S3, F, S1, F}, {S5, F, F, F, F, F},   {S2, S8, F, S7, S6, A}, {S2, F, F, F, S1, F},
        {S2, S4, S3, F, S1, F}, {S5, S8, F, S7, F, A}, {S6, S8, F, S7, F, A},  {S9, F, S10, F, F, F},
        {F, S8, F, F, F, A},    {S9, S8, F, F, F, A},  {S9, S8, F, F, F, F},
    };

    bool isNumber(const string& str) {
        S s = S0;
        for (const char* ch = str.c_str(); s != A && s != F; ++ch) {
            switch (*ch) {
                case ' ': s = tb[s][1]; break;
                case '+': s = tb[s][2]; break;
                case '-': s = tb[s][2]; break;
                case 'e': s = tb[s][3]; break;
                case '.': s = tb[s][4]; break;
                case '\0': s = tb[s][5]; break;
                default: s = *ch >= '0' && *ch <= '9' ? tb[s][0] : F; break;
            }
        }
        return s == A;
    }
};

/*
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    " -90e3   " => true
    " 1e" => false
    "e3" => false
    " 6e-1" => true
    " 99e2.5 " => false
    "53.5e93" => true
    " --6 " => false
    "-+3" => false
    "95a54e53" => false
*/
int main(int argc, char const* argv[]) {
    Solution          solution;
    map<string, bool> mp{{"0", true},        {" 0.1 ", true},  {"abc", false}, {"1 a", false},     {"2e10", true},
                         {" -90e3  ", true}, {" 1e", false},   {"e3", false},  {" 6e-1", true},    {" 99e2.5 ", false},
                         {"53.5e93", true},  {" --6 ", false}, {"-+3", false}, {"95a54e53", false}};

    for (const auto& [s, r] : mp) {
        cout << (solution.isNumber(s) == r ? "O " : "X ") << s << endl;
    }
}
