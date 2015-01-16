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
private:    
    int maxPathSum(TreeNode *root, int &result) {
        if (!root)
            return 0;
        int left = 0, right = 0, val = root->val;
        left = maxPathSum(root->left, result);
        val = max(val, val + left);
        right = maxPathSum(root->right, result);
        val = max(val, val + right);
        result = max(result, val);
        return max(root->val, root->val + max(left, right));
    }
};
