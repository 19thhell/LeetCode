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
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!root)
            return;
        if (root->left) {
            TreeNode *next = findNext(root->left);
            next->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->right);
    }

    TreeNode* findNext(TreeNode *root) {
        if (!root || !root->right)
            return root;
        return findNext(root->right);
    }
};
