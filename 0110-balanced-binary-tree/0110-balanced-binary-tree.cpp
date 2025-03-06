/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int checkBalance(TreeNode* root) {
        if (!root) return 0; // Base case: empty tree has height 0

        int left = checkBalance(root->left);
        if (left == -1) return -1; // Left subtree is unbalanced

        int right = checkBalance(root->right);
        if (right == -1) return -1; // Right subtree is unbalanced

        if (abs(left - right) > 1) return -1; // Current node is unbalanced

        return 1 + max(left, right); // Return height of subtree
    }

    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};
