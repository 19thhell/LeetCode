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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        levelOrderBottom(root, 0, result);
        int left = 0, right = result.size() - 1;
        while (left < right)
            swap(result[left++], result[right--]);
        return result;
    }

    void levelOrderBottom(TreeNode *root, int level, vector<vector<int> > &result) {
        if (!root)
            return;
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        levelOrderBottom(root->left, level + 1, result);
        levelOrderBottom(root->right, level + 1, result);
    }
};
