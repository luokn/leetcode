// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
#pragma once

#include <algorithm>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    int       val;
    TreeNode* left;
    TreeNode* right;
};

// class Solution {
//   public:
//     void flatten(TreeNode* root) {
//         stack<TreeNode*> n_stack;
//         while (root != nullptr || !n_stack.empty()) {
//             while (root != nullptr) {
//                 n_stack.emplace(root);
//                 root = root->left;
//             }

//             if (n_stack.empty()) continue;

//             TreeNode* node = n_stack.top();
//             TreeNode* temp = node->right;
//             node->right    = node->left;
//             node->left     = nullptr;
//             while (node->right != nullptr)
//                 node = node->right;
//             node->right = temp;
//             root        = temp;
//             n_stack.pop();
//         }
//     }
// };

class Solution {
  public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right    = root->left;
        root->left     = nullptr;
        while (root->right != nullptr)
            root = root->right;
        root->right = temp;
    }
};

inline TreeNode* TN(int x, TreeNode* left = nullptr,
                    TreeNode* right = nullptr) {
    return new TreeNode(x, left, right);
}

inline void test() {
    Solution  solution;
    TreeNode* root = TN(1, TN(2, TN(3), TN(4)), TN(5, nullptr, TN(6)));
    solution.flatten(root);
    ;
}