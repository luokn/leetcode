#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int       value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) { return {}; }
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int l, int r) {
        if (r == l) { return {new TreeNode(l)}; }
        if (l > r) { return {nullptr}; }
        vector<TreeNode *> trees;
        for (int i = l; i <= r; i++) {
            auto l_trees = generateTrees(l, i - 1);
            auto r_trees = generateTrees(i + 1, r);
            for (auto l_tree : l_trees) {
                for (auto r_tree : r_trees) { trees.emplace_back(new TreeNode(i, l_tree, r_tree)); }
            }
        }
        return trees;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    auto     trees = solution.generateTrees(3);
}