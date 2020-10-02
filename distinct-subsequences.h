#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
    static int num_distinct(const string& src, const string& dst) {
        const size_t             M = src.length(), N = dst.size();
        vector<vector<uint32_t>> dp(N + 1, vector<uint32_t>(M + 1));
        std::fill(dp[0].begin(), dp[0].end(), 1);
        for (size_t i = 1; i <= dst.size(); ++i) {
            if (dst[i - 1] == src[i - 1]) {
                dp[i][i] = dp[i - 1][i - 1];
            }
            for (size_t j = i + 1; j <= src.size(); ++j) {
                if (dst[i - 1] == src[j - 1]) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[dst.size()][src.size()];
    }
};

inline void test() {
    cout << Solution::num_distinct("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvel"
                                   "vwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwov"
                                   "sghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqv"
                                   "hxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrd"
                                   "hxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadt"
                                   "umnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdz"
                                   "qhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmks"
                                   "ivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsx"
                                   "zylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcw"
                                   "xbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyq"
                                   "cruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxib"
                                   "tdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonys"
                                   "ahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhig"
                                   "ffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstu"
                                   "zdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczios"
                                   "kqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo",
                                   "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys")
         << endl;
}
