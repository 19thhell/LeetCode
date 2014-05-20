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
    int maxPathSum(TreeNode *root) {
        int result = 0x80000000;
        maxPathSum(root, result);
        return result;
    }

    int maxPathSum(TreeNode *root, int &result) {
        if (!root)
            return 0;
        int left = 0, right = 0, val = root->val;
        if (root->left) {
            left = maxPathSum(root->left, result);
            if (left > 0)
                val += left;
        }
        if (root->right) {
            right = maxPathSum(root->right, result);
            if (right > 0)
                val += right;
        }
        if (val > result)
            result = val;
        return max(max(root->val + left, root->val + right), root->val);
    }
};
