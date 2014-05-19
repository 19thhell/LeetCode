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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        levelOrder(root, 0, result);
        for (int i = 1;i < result.size();i += 2) {
            int left = 0, right = result[i].size() - 1;
            while (left < right)
                swap(result[i][left++], result[i][right--]);
        }
        return result;
    }

    void levelOrder(TreeNode *root, int level, vector<vector<int> > &result) {
        if (!root)
            return;
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        levelOrder(root->left, level + 1, result);
        levelOrder(root->right, level + 1, result);
    }
};
