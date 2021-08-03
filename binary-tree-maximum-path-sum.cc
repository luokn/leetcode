#include "leetcode.h"

using namespace std;
using namespace utils;

class Solution {
  public:
    int maxPathSum(TreeNode *root) {
        int res = std::numeric_limits<int>::min();
        find_max_sum(root, res);
        return res;
    }

    int find_max_sum(TreeNode *root, int &res) const {
        if (root == nullptr) return 0;
        const int ls = max(0, find_max_sum(root->left, res));
        const int rs = max(0, find_max_sum(root->right, res));
        res          = max(res, root->value + ls + rs);
        return root->value + max(0, max(ls, rs));
    }
};

int main(int argc, char const *argv[]) {
    Solution   solution;
    const auto tree = make_tree(-10, make_tree(9), make_tree(20, make_tree(15), make_tree(17)));
    cout << solution.maxPathSum(tree) << endl;
    del_tree(tree);
}
