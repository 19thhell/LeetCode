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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root)
            return true;
        return biTraverse(root->left,root->right);
    }

    bool biTraverse(TreeNode *p, TreeNode *q){
        if (!p && !q)
            return true;
        if (!p && q || p && !q || p->val != q->val)
            return false;
        return biTraverse(p->left,q->right) && biTraverse(p->right,q->left);
    }
};
