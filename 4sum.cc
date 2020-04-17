#include "./leetcode.h"

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int counter = 0;
		map<int, int> map;
		for (const auto a : A) {
			for (const auto b : B)
				++map[a + b];
		}
		for (const auto c : C) {
			for (const auto d : D)
				counter += map[-(c + d)];
		}
		return counter;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> A{ 0, 1, -1 };
	vector<int> B{ -1, 1, 0 };
	vector<int> C{ 0, 0, 1 };
	vector<int> D{ -1, 1, 1 };
	std::cout << solution.fourSumCount(A, B, C, D) << endl;
}
