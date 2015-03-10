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
        return maxDepth(root, 0) != -1;
    }
private:
    int maxDepth(TreeNode *root, int depth) {
        if (!root)
            return 0;
        int left = maxDepth(root->left, depth + 1);
        if (left == -1)
            return -1;
        int right = maxDepth(root->right, depth + 1);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
