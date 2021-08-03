#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int       value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

inline TreeNode *N(int val, TreeNode *ln = nullptr, TreeNode *rn = nullptr) {
    TreeNode *node = new TreeNode(val);
    node->left     = ln;
    node->right    = rn;
    return node;
}

// class Solution {
//   public:
//     int maxDepth(TreeNode *root) {
//         return root ? (max(maxDepth(root->left), maxDepth(root->right)) + 1)
//                     : 0;
//     }
// };

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> q;
        q.emplace(root);
        size_t depth = 0;
        for (; !q.empty(); ++depth) {
            for (size_t i = 0, len = q.size(); i < len; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return depth;
    }
};

int main(int argc, char const *argv[]) {
    Solution  solution;
    TreeNode *root = N(3, N(9), N(20, N(15), N(7)));
    cout << solution.maxDepth(root) << endl;
}