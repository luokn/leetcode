#pragma once

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
        if (root == nullptr)
            return 0;
        const int ls = max(0, find_max_sum(root->left, res));
        const int rs = max(0, find_max_sum(root->right, res));
        res = max(res, root->val + ls + rs);
        return root->val + max(0, max(ls, rs));
    }
};

inline void test() {
    Solution solution;
    const auto tree = make_tree(-10, make_tree(9),
                                make_tree(20, make_tree(15), make_tree(17)));
    cout << solution.maxPathSum(tree) << endl;
    delete_tree(tree);
}
