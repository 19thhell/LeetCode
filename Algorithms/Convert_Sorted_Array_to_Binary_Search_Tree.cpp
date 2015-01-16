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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
private:
    TreeNode *sortedArrayToBST(vector<int> &num, int left, int right){
        if (left > right)
            return NULL;
        else {
            int mid = (left + right) / 2;
            TreeNode *tree = new TreeNode(num[mid]);
            tree->left = sortedArrayToBST(num, left, mid - 1);
            tree->right = sortedArrayToBST(num, mid + 1, right);
            return tree;
        }
    }
};
