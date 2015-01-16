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
        TreeNode *tree = root;
        while(tree) {
            TreeNode *next = tree->left;
            if (next) {
                while (next->right)
                    next = next->right;
                next->right = tree->right;
                tree->right = tree->left;
                tree->left = NULL;
            }
            tree = tree->right;
        }
    }
};
