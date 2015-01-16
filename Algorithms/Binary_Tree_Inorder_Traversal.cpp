//Recursive
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
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
private:
    void inorderTraversal(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
};
//Iterative
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
        stack<TreeNode *> stk;
        vector<int> result;
        TreeNode *p = root;
        while (p){
            stk.push(p);
            p = p->left;
        }
        while (!stk.empty()){
            p = stk.top();
            stk.pop();
            result.push_back(p->val);
            if (p->right){
                p = p->right;
                while (p){
                    stk.push(p);
                    p = p->left;
                }
            }
        }
        return result;
    }
};
