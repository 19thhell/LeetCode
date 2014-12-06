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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
     TreeNode *buildTree(vector<int> &inorder, int in_head, int in_tail, vector<int> &postorder, int post_head, int post_tail) {
        if (in_head > in_tail || post_head > post_tail)
            return NULL;
        int root_val = postorder[post_tail], index = 0;
        TreeNode *root = new TreeNode(root_val);
        for (int i = in_head;i <= in_tail;i++) {
            if (inorder[i] == root_val) {
                index = i;
                break;
            }
        }
        int len = index - in_head;
        root->left = buildTree(inorder, in_head, index - 1, postorder, post_head, post_head + len - 1);
        root->right = buildTree(inorder, index + 1, in_tail, postorder, post_head + len, post_tail - 1);
        return root;
    }
};
