#pragma once

#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
public:
	static int num_distinct(const string& s, const string& t) {
		vector<vector<uint32_t>> dp(t.size() + 1, vector<uint32_t>(s.size() + 1));
		std::fill(dp[0].begin(), dp[0].end(), 1);
		for (uint32_t i = 1; i <= t.size(); ++i) {
			if (t[i - 1] == s[i - 1]) {
				dp[i][i] = dp[i - 1][i - 1];
			}
			for (uint32_t j = i + 1; j <= s.size(); ++j) {
				if (t[i - 1] == s[j - 1]) {
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
				} else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[t.size()][s.size()];
	}
};

void test() {
    cout << Solution::num_distinct("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo", "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys") << endl;
}
