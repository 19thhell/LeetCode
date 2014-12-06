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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode *buildTree(vector<int> &preorder, int pre_head, int pre_tail, vector<int> &inorder, int in_head, int in_tail) {
        if (pre_head > pre_tail)
            return NULL;
        int root_val = preorder[pre_head], index = 0;
        TreeNode *root = new TreeNode(root_val);
        for (int i = in_head;i <= in_tail;i++) {
            if (inorder[i] == root_val) {
                index = i;
                break;
            }
        }
        int len = index - in_head;
        root->left = buildTree(preorder, pre_head + 1, pre_head + len, inorder, in_head, index - 1);
        root->right = buildTree(preorder, pre_head + len + 1, pre_tail, inorder, index + 1, in_tail);
        return root;
    }
};
