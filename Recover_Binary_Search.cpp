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
    void recoverTree(TreeNode *root) {
        if (!root)
            return;
        TreeNode *p1 = NULL, *p2 = NULL, *pre = NULL;
		findMistake(root, p1, p2, pre);
		if (p1 && p2)
			swap(p1->val, p2->val);
    }

    void findMistake(TreeNode *root, TreeNode *&p1, TreeNode *&p2, TreeNode *&pre) {
        if (!root)
            return;
        findMistake(root->left, p1, p2, pre);
        if (pre && pre->val > root->val)
			if (!p1) {
				p1 = pre;
				p2 = root;
			}
			else p2 = root;
		pre = root;
		findMistake(root->right, p1, p2, pre);
    }
};
