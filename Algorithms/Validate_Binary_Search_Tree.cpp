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
    bool isValidBST(TreeNode *root) {
        static const int min_val = 0x80000000, max_val = 0x7fffffff;
        return dfs(root, min_val, max_val);
    }

    bool dfs(TreeNode *root, int min_val, int max_val) {
        if (!root)
            return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return dfs(root->left, min_val, root->val) && dfs(root->right, root->val, max_val);
    }
};
