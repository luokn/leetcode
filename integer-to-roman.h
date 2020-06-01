#pragma once

#include "leetcode.h"

using namespace std;

class Solution {
public:
	static string int_to_roman(int num) {
		int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string strs[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

		stringstream res;
		for (int i = 0; i < 13; i++) {
			while (num >= values[i]) {
				num -= values[i];
				res << strs[i];
			}
		}
		return res.str();
	}
};

inline void test() {
	cout << Solution::int_to_roman(3) << endl;
}
