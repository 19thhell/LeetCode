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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> view;
        if (!root) {
            return view;
        }
        int max_depth = -1;
        dfs(view, root, max_depth, 0);
        return view;
    }
private:
    void dfs(vector<int> &view, TreeNode *root, int &max_depth, int init_depth) {
        if (init_depth > max_depth) {
            view.push_back(root->val);
            max_depth = init_depth;
        }
        if (root->right) {
            dfs(view, root->right, max_depth, init_depth + 1);
        }
        if (root->left) {
            dfs(view, root->left, max_depth, init_depth + 1);
        }
    }
};
