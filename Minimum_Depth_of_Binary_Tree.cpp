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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        int mindepth = 0x7fffffff;
        dfs(root, 1, mindepth);
        return mindepth;
    }

    void dfs(TreeNode *root, int depth, int &mindepth) {
        if (!root)
            return;
        if (depth >= mindepth)
            return;
        if (!root->left && !root->right)
            mindepth = min(mindepth, depth);
        dfs(root->left, depth + 1, mindepth);
        dfs(root->right, depth + 1, mindepth);
    }
};
