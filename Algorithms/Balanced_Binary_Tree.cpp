/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool balance = true;
        maxDepth(root, 0, balance);
        return balance;
    }
private:
    int maxDepth(TreeNode *root, int depth, bool &balance) {
        if (!root)
            return depth - 1;
        int left = maxDepth(root->left, depth + 1, balance);
        if (!balance)
            return depth;
        int right = maxDepth(root->right, depth + 1, balance);
        if (!balance)
            return depth;
        if (abs(left - right) > 1)
            balance = false;
        return max(left, right);
    }
};
