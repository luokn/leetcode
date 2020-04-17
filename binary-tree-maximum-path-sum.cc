#include "leetcode.h"

using namespace std;
using namespace utils;


class Solution {
public:
	int maxPathSum(TreeNode* root) {
		auto res = std::numeric_limits<int>::min();
		findMaxSum(root, res);
		return res;
	}

	int findMaxSum(TreeNode* root, int& res) {
		if (root == nullptr)
			return 0;
		const auto ls = max(0, findMaxSum(root->left, res));
		const auto rs = max(0, findMaxSum(root->right, res));
		res = max(res, root->value + ls + rs);
		return root->value + max(0, max(ls, rs));
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	const auto tree = make_tree(-10,
		make_tree(9),
		make_tree(20,
			make_tree(15),
			make_tree(17)
		)
	);
	cout << solution.maxPathSum(tree) << endl;
	delete_tree(tree);
}
