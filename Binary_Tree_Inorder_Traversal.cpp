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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<TreeNode *> q;
        vector<int> result;
        TreeNode *p = root;
        while (p){
            q.push(p);
            p = p->left;
        }
        while (!q.empty()){
            p = q.top();
            q.pop();
            result.push_back(p->val);
            if (p->right){
                p = p->right;
                while (p){
                    q.push(p);
                    p = p->left;
                }
            }
        }
        return result;
    }
};
