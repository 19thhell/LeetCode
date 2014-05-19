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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        vector<int> path;
        traverse(result, path, root, sum);
        return result;
    }

    void traverse(vector<vector<int> > &result, vector<int> &path, TreeNode *root, int sum) {
        if (!root)
            return;
        if (root->val == sum && !root->left && !root->right) {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
        }
        else {
            path.push_back(root->val);
            sum -= root->val;
            traverse(result, path, root->left, sum);
            traverse(result, path, root->right, sum);
            path.pop_back();
        }
    }
};
