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
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0;
        sumNumbers(root, 0, result);
        return result;
    }

    void sumNumbers(TreeNode *root, int path, int &sum) {
        if (!root)
            return;
        path = path * 10 + root->val;
        if (!root->left && !root->right) {
            sum += path;
            return;
        }
        sumNumbers(root->left, path, sum);
        sumNumbers(root->right, path, sum);
    }
};
