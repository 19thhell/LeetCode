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
        bool isBlc = true;
        isBalanced(root, 0, isBlc);
        return isBlc;
    }

    int isBalanced(TreeNode *root, int depth, bool &isBlc) {
        if (!root)
            return depth - 1;
        int left = isBalanced(root->left, depth + 1, isBlc);
        if (!isBlc)
            return depth;
        int right = isBalanced(root->right, depth + 1, isBlc);
        if (!isBlc)
            return depth;
        if (abs(left - right) > 1)
            isBlc = false;
        return max(left, right);
    }
};
