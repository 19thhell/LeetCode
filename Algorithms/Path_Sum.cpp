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
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root)
            return false;
        if (sum == root->val && !root->left && !root->right)
            return true;
        else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
